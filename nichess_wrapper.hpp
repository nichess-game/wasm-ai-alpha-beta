#pragma once

#include "nichess/nichess.hpp"
#include "nichess/util.hpp"

#include <vector>
#include <memory>

using namespace nichess;

namespace nichess_wrapper {

class AgentCache {
  public:
    std::vector<std::vector<float>> pieceTypeToIndexToSquareValue;

    AgentCache();
};

class GameWrapper {
  public:
    std::unique_ptr<Game> game;
    AgentCache *agentCache;

    GameWrapper(GameCache& gameCache, AgentCache& agentCache);
    std::vector<PlayerAction> usefulLegalActionsWithoutMoves();
    float positionValue(Player player);

};

} // namespace nichess_wrapper
