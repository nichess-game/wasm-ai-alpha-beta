#include "nichess_wrapper.hpp"

using namespace nichess;

std::vector<std::vector<float>> createPieceTypeToIndexToSquareValue() {
  std::vector<std::vector<float>> pieceTypeToIndexToSquareValue(NUM_PIECE_TYPE);
  int mostValuableX, mostValuableY, dx, dy, currentSquareIndex;
  double t;

  // p1 king
  mostValuableX = 0;
  mostValuableY = 0;
  std::vector<float> indexToP1KingSquareValue(NUM_ROWS * NUM_COLUMNS);
  for(int y = 0; y < NUM_ROWS; y++) {
    for(int x = 0; x < NUM_COLUMNS; x++) {
      currentSquareIndex = coordinatesToBoardIndex(x, y);
      dx = std::abs(mostValuableX - x);
      dy = std::abs(mostValuableY - y);
      if(dx == 0 && dy == 0) {
        indexToP1KingSquareValue[currentSquareIndex] = 1;
      } else {
        t = std::max(dx, dy);
        t = 1 - 0.1 * t;
        t = std::max(0.5, t);
        indexToP1KingSquareValue[currentSquareIndex] = t;
      }
    }
  }
  pieceTypeToIndexToSquareValue[P1_KING] = indexToP1KingSquareValue;

  // p1 mage
  mostValuableX = 4;
  mostValuableY = 4;
  std::vector<float> indexToP1MageSquareValue(NUM_ROWS * NUM_COLUMNS);
  for(int y = 0; y < NUM_ROWS; y++) {
    for(int x = 0; x < NUM_COLUMNS; x++) {
      currentSquareIndex = coordinatesToBoardIndex(x, y);
      dx = std::abs(mostValuableX - x);
      dy = std::abs(mostValuableY - y);
      if(dx == 0 && dy == 0) {
        indexToP1MageSquareValue[currentSquareIndex] = 1;
      } else {
        t = std::max(dx, dy);
        t = 1 - 0.1 * t;
        t = std::max(0.5, t);
        indexToP1MageSquareValue[currentSquareIndex] = t;
      }
    }
  }
  pieceTypeToIndexToSquareValue[P1_MAGE] = indexToP1MageSquareValue;

  // p1 pawn
  mostValuableX = 2;
  mostValuableY = 2;
  std::vector<float> indexToP1PawnSquareValue(NUM_ROWS * NUM_COLUMNS);
  for(int y = 0; y < NUM_ROWS; y++) {
    for(int x = 0; x < NUM_COLUMNS; x++) {
      currentSquareIndex = coordinatesToBoardIndex(x, y);
      dx = std::abs(mostValuableX - x);
      dy = std::abs(mostValuableY - y);
      if(dx == 0 && dy == 0) {
        indexToP1PawnSquareValue[currentSquareIndex] = 1;
      } else {
        t = std::max(dx, dy);
        t = 1 - 0.1 * t;
        t = std::max(0.5, t);
        indexToP1PawnSquareValue[currentSquareIndex] = t;
      }
    }
  }
  pieceTypeToIndexToSquareValue[P1_PAWN] = indexToP1PawnSquareValue;

  // p1 warrior
  mostValuableX = 5;
  mostValuableY = 5;
  std::vector<float> indexToP1WarriorSquareValue(NUM_ROWS * NUM_COLUMNS);
  for(int y = 0; y < NUM_ROWS; y++) {
    for(int x = 0; x < NUM_COLUMNS; x++) {
      currentSquareIndex = coordinatesToBoardIndex(x, y);
      dx = std::abs(mostValuableX - x);
      dy = std::abs(mostValuableY - y);
      if(dx == 0 && dy == 0) {
        indexToP1WarriorSquareValue[currentSquareIndex] = 1;
      } else {
        t = std::max(dx, dy);
        t = 1 - 0.1 * t;
        t = std::max(0.5, t);
        indexToP1WarriorSquareValue[currentSquareIndex] = t;
      }
    }
  }
  pieceTypeToIndexToSquareValue[P1_WARRIOR] = indexToP1WarriorSquareValue;

  // p1 assassin
  mostValuableX = 7;
  mostValuableY = 2;
  std::vector<float> indexToP1AssassinSquareValue(NUM_ROWS * NUM_COLUMNS);
  for(int y = 0; y < NUM_ROWS; y++) {
    for(int x = 0; x < NUM_COLUMNS; x++) {
      currentSquareIndex = coordinatesToBoardIndex(x, y);
      dx = std::abs(mostValuableX - x);
      dy = std::abs(mostValuableY - y);
      if(dx == 0 && dy == 0) {
        indexToP1AssassinSquareValue[currentSquareIndex] = 1;
      } else {
        t = std::max(dx, dy);
        t = 1 - 0.1 * t;
        t = std::max(0.5, t);
        indexToP1AssassinSquareValue[currentSquareIndex] = t;
      }
    }
  }
  pieceTypeToIndexToSquareValue[P1_ASSASSIN] = indexToP1AssassinSquareValue;

  // p2 king
  mostValuableX = 7;
  mostValuableY = 7;
  std::vector<float> indexToP2KingSquareValue(NUM_ROWS * NUM_COLUMNS);
  for(int y = 0; y < NUM_ROWS; y++) {
    for(int x = 0; x < NUM_COLUMNS; x++) {
      currentSquareIndex = coordinatesToBoardIndex(x, y);
      dx = std::abs(mostValuableX - x);
      dy = std::abs(mostValuableY - y);
      if(dx == 0 && dy == 0) {
        indexToP2KingSquareValue[currentSquareIndex] = 1;
      } else {
        t = std::max(dx, dy);
        t = 1 - 0.1 * t;
        t = std::max(0.5, t);
        indexToP2KingSquareValue[currentSquareIndex] = t;
      }
    }
  }
  pieceTypeToIndexToSquareValue[P2_KING] = indexToP2KingSquareValue;

  // p2 mage
  mostValuableX = 3;
  mostValuableY = 3;
  std::vector<float> indexToP2MageSquareValue(NUM_ROWS * NUM_COLUMNS);
  for(int y = 0; y < NUM_ROWS; y++) {
    for(int x = 0; x < NUM_COLUMNS; x++) {
      currentSquareIndex = coordinatesToBoardIndex(x, y);
      dx = std::abs(mostValuableX - x);
      dy = std::abs(mostValuableY - y);
      if(dx == 0 && dy == 0) {
        indexToP2MageSquareValue[currentSquareIndex] = 1;
      } else {
        t = std::max(dx, dy);
        t = 1 - 0.1 * t;
        t = std::max(0.5, t);
        indexToP2MageSquareValue[currentSquareIndex] = t;
      }
    }
  }
  pieceTypeToIndexToSquareValue[P2_MAGE] = indexToP2MageSquareValue;

  // p2 pawn
  mostValuableX = 5;
  mostValuableY = 5;
  std::vector<float> indexToP2PawnSquareValue(NUM_ROWS * NUM_COLUMNS);
  for(int y = 0; y < NUM_ROWS; y++) {
    for(int x = 0; x < NUM_COLUMNS; x++) {
      currentSquareIndex = coordinatesToBoardIndex(x, y);
      dx = std::abs(mostValuableX - x);
      dy = std::abs(mostValuableY - y);
      if(dx == 0 && dy == 0) {
        indexToP2PawnSquareValue[currentSquareIndex] = 1;
      } else {
        t = std::max(dx, dy);
        t = 1 - 0.1 * t;
        t = std::max(0.5, t);
        indexToP2PawnSquareValue[currentSquareIndex] = t;
      }
    }
  }
  pieceTypeToIndexToSquareValue[P2_PAWN] = indexToP2PawnSquareValue;

  // p2 warrior
  mostValuableX = 2;
  mostValuableY = 2;
  std::vector<float> indexToP2WarriorSquareValue(NUM_ROWS * NUM_COLUMNS);
  for(int y = 0; y < NUM_ROWS; y++) {
    for(int x = 0; x < NUM_COLUMNS; x++) {
      currentSquareIndex = coordinatesToBoardIndex(x, y);
      dx = std::abs(mostValuableX - x);
      dy = std::abs(mostValuableY - y);
      if(dx == 0 && dy == 0) {
        indexToP2WarriorSquareValue[currentSquareIndex] = 1;
      } else {
        t = std::max(dx, dy);
        t = 1 - 0.1 * t;
        t = std::max(0.5, t);
        indexToP2WarriorSquareValue[currentSquareIndex] = t;
      }
    }
  }
  pieceTypeToIndexToSquareValue[P2_WARRIOR] = indexToP2WarriorSquareValue;

  // p2 assassin
  mostValuableX = 0;
  mostValuableY = 0;
  std::vector<float> indexToP2AssassinSquareValue(NUM_ROWS * NUM_COLUMNS);
  for(int y = 0; y < NUM_ROWS; y++) {
    for(int x = 0; x < NUM_COLUMNS; x++) {
      currentSquareIndex = coordinatesToBoardIndex(x, y);
      dx = std::abs(mostValuableX - x);
      dy = std::abs(mostValuableY - y);
      if(dx == 0 && dy == 0) {
        indexToP2AssassinSquareValue[currentSquareIndex] = 1;
      } else {
        t = std::max(dx, dy);
        t = 1 - 0.1 * t;
        t = std::max(0.5, t);
        indexToP2AssassinSquareValue[currentSquareIndex] = t;
      }
    }
  }
  pieceTypeToIndexToSquareValue[P2_ASSASSIN] = indexToP2AssassinSquareValue;

  return pieceTypeToIndexToSquareValue;
}

nichess_wrapper::AgentCache::AgentCache() {
  pieceTypeToIndexToSquareValue = createPieceTypeToIndexToSquareValue();
}

float pieceTypeToValueMultiplier(PieceType pt) {
  switch(pt) {
    case P1_KING:
      return 10;
    case P1_MAGE:
      return  10; 
    case P1_PAWN:
      return 1;
    case P1_WARRIOR:
      return 5;
    case P1_ASSASSIN:
      return 5;
    case P2_KING:
      return 10;
    case P2_MAGE:
      return 10;
    case P2_PAWN:
      return 1;
    case P2_WARRIOR:
      return 5;
    case P2_ASSASSIN:
      return 5;
    case NO_PIECE:
      return 0;
    default:
      return 0;
  }
}
/*
 * Used for dead pieces. Reason: Some pieces (King, Assassin) getting damaged isn't too important, but it's very bad
 * if they die.
 */
float pieceTypeToValueMultiplier2(PieceType pt) {
  switch(pt) {
    case P1_KING:
      return 1000;
    case P1_MAGE:
      return  10; 
    case P1_PAWN:
      return 1;
    case P1_WARRIOR:
      return 5;
    case P1_ASSASSIN:
      return 30;
    case P2_KING:
      return 1000;
    case P2_MAGE:
      return 10;
    case P2_PAWN:
      return 1;
    case P2_WARRIOR:
      return 5;
    case P2_ASSASSIN:
      return 30;
    case NO_PIECE:
      return 0;
    default:
      return 0;
  }
}

/*
 * Returns value of the current position, relative to the player.
 */
float nichess_wrapper::GameWrapper::positionValue(Player player) {
  float retval = 0;
  std::vector<Piece*> p1Pieces = game->getAllPiecesByPlayer(PLAYER_1);
  for(Piece* p : p1Pieces) {
    if(p->healthPoints <= 0) {
      retval -= pieceTypeToValueMultiplier2(p->type) * 100;
      continue;
    }
    retval += agentCache->pieceTypeToIndexToSquareValue[p->type][p->squareIndex] * pieceTypeToValueMultiplier(p->type) * p->healthPoints;
  }
  std::vector<Piece*> p2Pieces = game->getAllPiecesByPlayer(PLAYER_2);
  for(Piece* p : p2Pieces) {
    if(p->healthPoints <= 0) {
      retval += pieceTypeToValueMultiplier2(p->type) * 100;
      continue;
    }
    retval -= agentCache->pieceTypeToIndexToSquareValue[p->type][p->squareIndex] * pieceTypeToValueMultiplier(p->type) * p->healthPoints;
  }
  float m = 1;
  if(player == PLAYER_2) m = -1;
  return m * retval;
}


nichess_wrapper::GameWrapper::GameWrapper(GameCache& gameCache, AgentCache& agentCache) {
  game = std::make_unique<Game>(gameCache);
  this->agentCache = &agentCache;
}

/*
 * Useful actions are those whose abilities change the game state.
 * For example, warrior attacking an empty square is legal but doesn't change the game state.
 * Returns the vector of PlayerActions, excluding actions where:
 * 1) Move is different from MOVE_SKIP
 * 2) Ability is ABILITY_SKIP
 */
std::vector<PlayerAction> nichess_wrapper::GameWrapper::usefulLegalActionsWithoutMoves() {
  std::vector<PlayerAction> retval;
  // If King is dead, game is over and there are no legal actions
  if(game->playerToPieces[game->currentPlayer][KING_PIECE_INDEX]->healthPoints <= 0) {
    return retval;
  }

  for(int k = 0; k < NUM_STARTING_PIECES; k++) {
    Piece* cp2 = game->playerToPieces[game->currentPlayer][k];
    if(cp2->healthPoints <= 0) continue; // no abilities for dead pieces
    auto legalAbilities = game->gameCache->pieceTypeToSquareIndexToLegalAbilities[cp2->type][cp2->squareIndex];
    for(int l = 0; l < legalAbilities.size(); l++) {
      Piece* destinationSquarePiece = game->board[legalAbilities[l].abilityDstIdx];
      // exclude useless abilities
      switch(cp2->type) {
        // king can only use abilities on enemy pieces
        case P1_KING:
          switch(destinationSquarePiece->type) {
            case P1_KING:
              continue;
            case P1_MAGE:
              continue;
            case P1_PAWN:
              continue;
            case P1_WARRIOR:
              continue;
            case P1_ASSASSIN:
              continue;
            case P2_KING:
              break;
            case P2_MAGE:
              break;
            case P2_PAWN:
              break;
            case P2_WARRIOR:
              break;
            case P2_ASSASSIN:
              break;
            case NO_PIECE:
              continue;
            default:
              break;
          }
        // mage can only use abilities on enemy pieces
        case P1_MAGE:
          switch(destinationSquarePiece->type) {
            case P1_KING:
              continue;
            case P1_MAGE:
              continue;
            case P1_PAWN:
              continue;
            case P1_WARRIOR:
              continue;
            case P1_ASSASSIN:
              continue;
            case P2_KING:
              break;
            case P2_MAGE:
              break;
            case P2_PAWN:
              break;
            case P2_WARRIOR:
              break;
            case P2_ASSASSIN:
              break;
            case NO_PIECE:
              continue;
            default:
              break;
          }
          break;
        // pawn can only use abilities on enemy pieces
        case P1_PAWN:
          switch(destinationSquarePiece->type) {
            case P1_KING:
              continue;
            case P1_MAGE:
              continue;
            case P1_PAWN:
              continue;
            case P1_WARRIOR:
              continue;
            case P1_ASSASSIN:
              continue;
            case P2_KING:
              break;
            case P2_MAGE:
              break;
            case P2_PAWN:
              break;
            case P2_WARRIOR:
              break;
            case P2_ASSASSIN:
              break;
            case NO_PIECE:
              continue;
            default:
              break;
          }
          break;
        // warrior can only use abilities on enemy pieces
        case P1_WARRIOR:
          switch(destinationSquarePiece->type) {
            case P1_KING:
              continue;
            case P1_MAGE:
              continue;
            case P1_PAWN:
              continue;
            case P1_WARRIOR:
              continue;
            case P1_ASSASSIN:
              continue;
            case P2_KING:
              break;
            case P2_MAGE:
              break;
            case P2_PAWN:
              break;
            case P2_WARRIOR:
              break;
            case P2_ASSASSIN:
              break;
            case NO_PIECE:
              continue;
            default:
              break;
          }
          break;
        // assassin can only use abilities on enemy pieces
        case P1_ASSASSIN:
          switch(destinationSquarePiece->type) {
            case P1_KING:
              continue;
            case P1_MAGE:
              continue;
            case P1_PAWN:
              continue;
            case P1_WARRIOR:
              continue;
            case P1_ASSASSIN:
              continue;
            case P2_KING:
              break;
            case P2_MAGE:
              break;
            case P2_PAWN:
              break;
            case P2_WARRIOR:
              break;
            case P2_ASSASSIN:
              break;
            case NO_PIECE:
              continue;
            default:
              break;
          }
          break;

        // king can only use abilities on enemy pieces
        case P2_KING:
          switch(destinationSquarePiece->type) {
            case P1_KING:
              break;
            case P1_MAGE:
              break;
            case P1_PAWN:
              break;
            case P1_WARRIOR:
              break;
            case P1_ASSASSIN:
              break;
            case P2_KING:
              continue;
            case P2_MAGE:
              continue;
            case P2_PAWN:
              continue;
            case P2_WARRIOR:
              continue;
            case P2_ASSASSIN:
              continue;
            case NO_PIECE:
              continue;
            default:
              break;
          }
        // mage can only use abilities on enemy pieces
        case P2_MAGE:
          switch(destinationSquarePiece->type) {
            case P1_KING:
              break;
            case P1_MAGE:
              break;
            case P1_PAWN:
              break;
            case P1_WARRIOR:
              break;
            case P1_ASSASSIN:
              break;
            case P2_KING:
              continue;
            case P2_MAGE:
              continue;
            case P2_PAWN:
              continue;
            case P2_WARRIOR:
              continue;
            case P2_ASSASSIN:
              continue;
            case NO_PIECE:
              continue;
            default:
              break;
          }
          break;
        // pawn can only use abilities on enemy pieces
        case P2_PAWN:
          switch(destinationSquarePiece->type) {
            case P1_KING:
              break;
            case P1_MAGE:
              break;
            case P1_PAWN:
              break;
            case P1_WARRIOR:
              break;
            case P1_ASSASSIN:
              break;
            case P2_KING:
              continue;
            case P2_MAGE:
              continue;
            case P2_PAWN:
              continue;
            case P2_WARRIOR:
              continue;
            case P2_ASSASSIN:
              continue;
            case NO_PIECE:
              continue;
            default:
              break;
          }
          break;
        // warrior can only use abilities on enemy pieces
        case P2_WARRIOR:
          switch(destinationSquarePiece->type) {
            case P1_KING:
              break;
            case P1_MAGE:
              break;
            case P1_PAWN:
              break;
            case P1_WARRIOR:
              break;
            case P1_ASSASSIN:
              break;
            case P2_KING:
              continue;
            case P2_MAGE:
              continue;
            case P2_PAWN:
              continue;
            case P2_WARRIOR:
              continue;
            case P2_ASSASSIN:
              continue;
            case NO_PIECE:
              continue;
            default:
              break;
          }
          break;
        // assassin can only use abilities on enemy pieces
        case P2_ASSASSIN:
          switch(destinationSquarePiece->type) {
            case P1_KING:
              break;
            case P1_MAGE:
              break;
            case P1_PAWN:
              break;
            case P1_WARRIOR:
              break;
            case P1_ASSASSIN:
              break;
            case P2_KING:
              continue;
            case P2_MAGE:
              continue;
            case P2_PAWN:
              continue;
            case P2_WARRIOR:
              continue;
            case P2_ASSASSIN:
              continue;
            case NO_PIECE:
              continue;
            default:
              break;
          }
          break;
        case NO_PIECE:
          break;
        default:
          break;
      }

      PlayerAction p = PlayerAction(MOVE_SKIP, MOVE_SKIP, legalAbilities[l].abilitySrcIdx, legalAbilities[l].abilityDstIdx);
      retval.push_back(p);
    }
  }
  return retval;
}
