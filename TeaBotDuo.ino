#include "config.h"
#include "sensors.h"
#include "actors.h"
#include "state.h"

long remaining   [NUM_SIDES] = {LEFT_DEFAULT_VALUE * DELTA, RIGHT_DEFAULT_VALUE * DELTA};
long defaultValue[NUM_SIDES] = {LEFT_DEFAULT_VALUE * DELTA, RIGHT_DEFAULT_VALUE * DELTA};
long startTime   [NUM_SIDES] = {0, 0};

void calcRemaining(byte side) {
  remaining[side]--; // TODO FIX
}

boolean isTeaReady(byte side) {
  return (remaining[side]<=0);
}

void processSide(byte side) {
  boolean keyHit = false;
  
  keyHit = adjust(side, remaining[side]);

  if (keyHit) {
    noteActivity();  
    if ((IDLE == getState(side)) || (TEA_READY == getState(side))) {
      setState(side, SELECT_TIME); 
      ensureArmLow(side); 
      remaining[side] = defaultValue[side];
    } // no else
  } // no else

  if (getState(side) == COUNT_DOWN) {
    calcRemaining(side);
  } // no else
    
  if (isSuddenRaise(side) && (getState(side)==SELECT_TIME)) {
    noteActivity();  
    setState(side, COUNT_DOWN);
    startTime[side] = millis();
  }

  if ((getState(side)==COUNT_DOWN) && isTeaReady(side)) {
    setState(side, TEA_READY);
    raiseArm(side);
  } 
  
}

long getStateColor(int state) {
  long result = 0;
  
  switch (state) {
    case IDLE:
    case SELECT_TIME: 
      result = SELECT_COLOR;
      break;
    case COUNT_DOWN:
      result = COUNT_COLOR;
      break;
    case TEA_READY:
      result = READY_COLOR;
      break;       
  }
  return result;
}

void showRemaining() {
  for (byte side=0; side<NUM_SIDES; side++) {
    drawCountDown(side, remaining[side], getStateColor(getState(side)));
  }
  
  showAll();
}

void setupPins() {
  pinMode(LEFT_UP_PIN,    INPUT_PULLUP);	
  pinMode(LEFT_DOWN_PIN,  INPUT_PULLUP);	
  pinMode(RIGHT_UP_PIN,   INPUT_PULLUP);	
  pinMode(RIGHT_DOWN_PIN, INPUT_PULLUP);	

  pinMode(PIEZO_PIN,      OUTPUT);
  pinMode(LEFT_ARM_PIN,   OUTPUT);
  pinMode(RIGHT_ARM_PIN,  OUTPUT);
}

void setup() {
  setupPins();
  setupLeds();
  setupArms();
  setupState();
  setupSensors();

  soundSignal();
  glowEyes();

  Serial.begin(9600);
}

int debug = LEFT_DEFAULT;

void useWhenBuilding(byte side) {
  boolean keyHit = false;
  
  keyHit = adjust(side, debug);
  
  drawCountDown(side, debug, 0x00ff00);
  showAll();
  raiseArm(side); 
  delay(500);
  
  drawCountDown(side, debug, 0xff0000);
  showAll();
  lowerArm(side); 
  delay(500);
  
  Serial.println(20*keyHit + readTemp(side));
}

void loop() {

  for (byte side=0; side <NUM_SIDES; side++) {
    processSide(side);
  }

  if (isActive()) {
    showRemaining();
  } else {
    animateEyes();  
  }

  delay(DELAY);

  // useWhenBuilding(LEFT);
  // useWhenBuilding(RIGHT);
}
