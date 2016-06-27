#include "config.h"
#include "sensors.h"
#include "actors.h"
#include "state.h"

void setupPins() {
  pinMode(LEFT_UP_PIN,    INPUT_PULLUP);	
  pinMode(LEFT_DOWN_PIN,  INPUT_PULLUP);	
  pinMode(RIGHT_UP_PIN,   INPUT_PULLUP);	
  pinMode(RIGHT_DOWN_PIN, INPUT_PULLUP);	

  pinMode(PIEZO_PIN,     OUTPUT);
  pinMode(LEFT_ARM_PIN,  OUTPUT);
  pinMode(RIGHT_ARM_PIN, OUTPUT);
}


void setup() {
  setupPins();
  setupLeds();
  setupArms();
  soundSignal();
  setupStateMachine();

  creepyGlowingEyes();
}


int remainingLeft  = LEFT_DEFAULT_VALUE*DELTA;
int remainingRight = RIGHT_DEFAULT_VALUE*DELTA;


void loop() {
/*
  adjust(remainingLeft,  LEFT_UP_PIN,  LEFT_DOWN_PIN,  DELTA, MIN_VALUE, MAX_VALUE);
  adjust(remainingRight, RIGHT_UP_PIN, RIGHT_DOWN_PIN, DELTA, MIN_VALUE, MAX_VALUE);
  
  drawCountDown(LEFT,  remainingLeft,  SELECT_COLOR);
  drawCountDown(RIGHT, remainingRight, SELECT_COLOR);
*/
  // readTemp();

  animateEyes();
  delay(DELAY);
}
