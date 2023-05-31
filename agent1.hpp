#pragma once

#include "nichess/nichess.hpp"
#include "nichess_wrapper.hpp"

#include <vector>
#include <chrono>

using namespace nichess;

namespace agent1 {

class Agent1 {
  public:
    int numNodesSearched = 0;
    int numNodesToSearch;
    bool abortSearch = false; // set to true when numNodesSearched >= numNodesToSearch

		Agent1() { }
    PlayerAction computeAction(nichess_wrapper::GameWrapper& gameWrapper, int maxThinkingTime);
    PlayerAction runAlphaBetaSearch(nichess_wrapper::GameWrapper& gameWrapper, int searchDepth);
    float alphabeta(nichess_wrapper::GameWrapper& gameWrapper, float alpha, float beta, int depth, bool maximizingPlayer, Player startingPlayer);
    //float positionValue(nichess_wrapper::GameWrapper& gameWrapper, Player player);
    float quiescenceSearch(nichess_wrapper::GameWrapper& gameWrapper, bool maximizingPlayer, Player startingPlayer);
};

} // namespace agent1
