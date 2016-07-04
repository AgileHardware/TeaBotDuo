#include "state.h"

int state[NUM_SIDES];

long lastActivity = -STAY_ACTIVE;

void setupState() {
  for (byte side=0; side<NUM_SIDES; side++) {
    setState(side,  IDLE);
  }
}

int getState(byte side) {
  return state[side];
}

void setState(byte side, int newState) {
  state[side] = newState;
}

void noteActivity() {
  lastActivity = millis();
}

boolean isActive() {
  boolean result;
  
  result = lastActivity+(long)STAY_ACTIVE > millis();

  if (!result) {
    for (byte side=0; side<NUM_SIDES; side++) {
      setState(side,  IDLE);
    }
  }
  
  return result;
}

