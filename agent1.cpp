#include <iostream>
#include <tuple>
#include <cmath>
#include <random>
#include <iterator>
#include <algorithm>
#include <limits>
#include <assert.h>

#include "emscripten.h"

#include "nichess/nichess.hpp"
#include "nichess_wrapper.hpp"
#include "agent1.hpp"

using namespace nichess;

EMSCRIPTEN_KEEPALIVE
float agent1::Agent1::quiescenceSearch(nichess_wrapper::GameWrapper& gameWrapper, bool maximizingPlayer, Player startingPlayer) {
  if(this->numNodesSearched >= this->numNodesToSearch) {
    this->abortSearch = true;
    return 0;
  }

  std::vector<PlayerAction> actions = gameWrapper.usefulLegalActionsWithoutMoves();
  if(actions.size() == 0) return gameWrapper.positionValue(startingPlayer);
  
  float value, currentValue, bestValue;
  if(maximizingPlayer) {
      value = -std::numeric_limits<float>::max();
      // find best action after 1 step
      PlayerAction bestAction = actions[0];
      float bestValue = -std::numeric_limits<float>::max();
      for(PlayerAction pa : actions) {
        UndoInfo undoInfo = gameWrapper.game->makeAction(pa.moveSrcIdx, pa.moveDstIdx, pa.abilitySrcIdx, pa.abilityDstIdx);
        currentValue = gameWrapper.positionValue(startingPlayer);
        if(currentValue > bestValue) {
          bestValue = currentValue;
          bestAction = pa;
        }
        gameWrapper.game->undoAction(undoInfo);
        numNodesSearched++;
        if(this->abortSearch) return 0;
      }
      UndoInfo undoInfo = gameWrapper.game->makeAction(bestAction.moveSrcIdx, bestAction.moveDstIdx, bestAction.abilitySrcIdx, bestAction.abilityDstIdx);
      value = std::max(value, quiescenceSearch(gameWrapper, false, startingPlayer));
      gameWrapper.game->undoAction(undoInfo);
    } else {
      value = std::numeric_limits<float>::max();
      // find best action after 1 step
      PlayerAction bestAction = actions[0];
      float bestValue = std::numeric_limits<float>::max();
      for(PlayerAction pa : actions) {
        UndoInfo undoInfo = gameWrapper.game->makeAction(pa.moveSrcIdx, pa.moveDstIdx, pa.abilitySrcIdx, pa.abilityDstIdx);
        currentValue = gameWrapper.positionValue(startingPlayer);
        if(currentValue < bestValue) {
          bestValue = currentValue;
          bestAction = pa;
        }
        gameWrapper.game->undoAction(undoInfo);
        numNodesSearched++;
        if(this->abortSearch) return 0;
      }
      UndoInfo undoInfo = gameWrapper.game->makeAction(bestAction.moveSrcIdx, bestAction.moveDstIdx, bestAction.abilitySrcIdx, bestAction.abilityDstIdx);
      value = std::min(value, quiescenceSearch(gameWrapper, true, startingPlayer));
      gameWrapper.game->undoAction(undoInfo);
    }
  return value;
}

EMSCRIPTEN_KEEPALIVE
float agent1::Agent1::alphabeta(nichess_wrapper::GameWrapper& gameWrapper, float alpha, float beta, int depth, bool maximizingPlayer, Player startingPlayer) {
  if(this->numNodesSearched >= this->numNodesToSearch) {
    this->abortSearch = true;
    return 0;
  }
			
  if(depth == 0 || gameWrapper.game->gameOver()) {
    return gameWrapper.positionValue(startingPlayer);
    //return quiescenceSearch(gameWrapper, !maximizingPlayer, startingPlayer);
  }
  if(maximizingPlayer) {
    std::vector<PlayerAction> ala = gameWrapper.game->usefulLegalActions();
    float value = -std::numeric_limits<float>::max();
    for(PlayerAction pa : ala) {
      UndoInfo undoInfo = gameWrapper.game->makeAction(pa.moveSrcIdx, pa.moveDstIdx, pa.abilitySrcIdx, pa.abilityDstIdx);
      value = std::max(value, alphabeta(gameWrapper, alpha, beta, depth - 1, false, startingPlayer));
      gameWrapper.game->undoAction(undoInfo);
      numNodesSearched++;
      if(this->abortSearch) return 0;
      if(value > beta) {
        break;
      }
      alpha = std::max(alpha, value);
    }
    return value;
  } else {
    std::vector<PlayerAction> ala = gameWrapper.game->usefulLegalActions();
    float value = std::numeric_limits<float>::max();
    for(PlayerAction pa : ala) {
      UndoInfo undoInfo = gameWrapper.game->makeAction(pa.moveSrcIdx, pa.moveDstIdx, pa.abilitySrcIdx, pa.abilityDstIdx);
      value = std::min(value, alphabeta(gameWrapper, alpha, beta, depth - 1, true, startingPlayer));
      gameWrapper.game->undoAction(undoInfo);
      numNodesSearched++;
      if(this->abortSearch) return 0;
      if(value < alpha) {
        break;
      }
      beta = std::min(beta, value);
    }
    return value;
  }
}

class ActionValue {
  public:
    PlayerAction action;
    float value;

    ActionValue() { }
    ActionValue(PlayerAction action, float value): action(action), value(value) { }
};

EMSCRIPTEN_KEEPALIVE
bool compareActionValue(ActionValue av1, ActionValue av2) {
  return av1.value > av2.value;
}

EMSCRIPTEN_KEEPALIVE
PlayerAction agent1::Agent1::runAlphaBetaSearch(nichess_wrapper::GameWrapper& gameWrapper, int searchDepth) {
  std::vector<PlayerAction> ala = gameWrapper.game->usefulLegalActions();
  float bestValue = -std::numeric_limits<float>::max();
  PlayerAction bestAction = ala[0];
  float value;
  Player startingPlayer = gameWrapper.game->getCurrentPlayer();
  std::vector<ActionValue> bestActionValues;
  for(PlayerAction pa : ala) {
    UndoInfo undoInfo = gameWrapper.game->makeAction(pa.moveSrcIdx, pa.moveDstIdx, pa.abilitySrcIdx, pa.abilityDstIdx);
    float alpha = -std::numeric_limits<float>::max();
    float beta = std::numeric_limits<float>::max();
    value = alphabeta(gameWrapper, alpha, beta, searchDepth - 1, false, startingPlayer);
    gameWrapper.game->undoAction(undoInfo);
    numNodesSearched++;
    if(this->abortSearch) return bestAction;
    if(value > bestValue) {
      bestValue = value;
      bestAction = pa;
    }

    if(bestActionValues.size() < 5) {
      ActionValue av = ActionValue(pa, value);
      bestActionValues.push_back(av);
      std::sort(bestActionValues.begin(), bestActionValues.end(), compareActionValue);
    } else {
      ActionValue currentAv;
      for(int i = 0; i < bestActionValues.size(); i++) {
        currentAv = bestActionValues[i];
        if(value > currentAv.value) {
          ActionValue newAv = ActionValue(pa, value);
          bestActionValues.insert(bestActionValues.begin() + i, newAv);
          bestActionValues.pop_back();
          break;
        }
      }
    }
  }
  std::cout << "Number of nodes explored: " << numNodesSearched << "\n";
  std::cout << "Best actions and their values:\n";
  for(ActionValue av: bestActionValues) {
    std::cout << "Action:\n";
    av.action.print();
    std::cout << "Value:\n";
    std::cout << av.value << "\n";
  }
  return bestAction;
}

EMSCRIPTEN_KEEPALIVE
PlayerAction agent1::Agent1::computeAction(nichess_wrapper::GameWrapper& gameWrapper, int numNodesToSearch) {
  assert(numNodesToSearch > 300);
  this->numNodesSearched = 0;
  this->numNodesToSearch = numNodesToSearch;
  this->abortSearch = false;
  PlayerAction allTimeBestAction, currentBestAction;
  allTimeBestAction = PlayerAction(MOVE_SKIP, MOVE_SKIP, ABILITY_SKIP, ABILITY_SKIP);
  int i = 1;
  while(true) {
    std::cout << "Searching with max depth " << i << "\n";
    std::cout << "nodes searched: " << this->numNodesSearched << "\n";
    std::cout << "nodes to search: " << this->numNodesToSearch << "\n";
    currentBestAction = runAlphaBetaSearch(gameWrapper, i);
    if(!this->abortSearch) { // only save best action if search was completed
      allTimeBestAction = currentBestAction;
    } else {
      std::cout << "Total number of nodes explored: " << this->numNodesSearched << "\n";
      std::cout << "Search with depth " << i << " not completed. Using result from depth " << i-1 << ".\n";
      break;
    }
    i++;
  }
  return allTimeBestAction;
}
