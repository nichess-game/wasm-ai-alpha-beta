#include "nichess/nichess.hpp"
#include "nichess_wrapper.hpp"
#include "agent1.hpp"

#include <iostream>
#include <emscripten.h>


#ifdef __cplusplus
#define EXTERN extern "C"
#else
#define EXTERN
#endif

EXTERN EMSCRIPTEN_KEEPALIVE
int computeAIAction(char* gameState) {
  GameCache gameCache = GameCache();
  auto agentCache = nichess_wrapper::AgentCache();
  nichess_wrapper::GameWrapper gw = nichess_wrapper::GameWrapper(gameCache, agentCache);
  gw.game->boardFromString(gameState);
  agent1::Agent1 agent = agent1::Agent1();
  nichess::PlayerAction pa = agent.computeAction(gw, 500000);
  // Returning arrays in WASM is difficult.
  // Instead, this returns the PlayerAction as a single 9 digit int in form:
  // 1 moveSrcIdx moveDstIdx abilitySrcIdx abilityDstIdx
  // First digit is reserved as 1 to ensure that the return value always has the same number of
  // digits.
  // Problem: MOVE_SKIP and ABILITY_SKIP are -1, which can't be encoded in the proposed way.
  // Solution (for now): MOVE_SKIP and ABILITY_SKIP will be encoded by number 99.
  if(pa.moveSrcIdx == nichess::MOVE_SKIP) {
    pa.moveSrcIdx = 99;
    pa.moveDstIdx = 99;
  }
  if(pa.abilitySrcIdx == nichess::ABILITY_SKIP) {
    pa.abilitySrcIdx = 99;
    pa.abilityDstIdx = 99;
  }
  int retval = 100000000;
  retval += pa.moveSrcIdx * 1000000;
  retval +=  pa.moveDstIdx * 10000;
  retval += pa.abilitySrcIdx * 100;
  retval += pa.abilityDstIdx;
  return retval;
}
