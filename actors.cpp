#include <Adafruit_NeoPixel.h>
#include <Servo.h>

#include "actors.h"

Adafruit_NeoPixel leds = Adafruit_NeoPixel(NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);
Servo servo;

int armPin      [NUM_SIDES] = {LEFT_ARM_PIN,   RIGHT_ARM_PIN};
int armLimitDown[NUM_SIDES] = {LEFT_ARM_LOWER, RIGHT_ARM_LOWER};
int armLimitUp  [NUM_SIDES] = {LEFT_ARM_UPPER, RIGHT_ARM_UPPER};

int ledOffset   [NUM_SIDES] = {OFFSET_LEFT,    OFFSET_RIGHT}; 
int ledRotation [NUM_SIDES] = {ROTATION_LEFT,  ROTATION_RIGHT};

void setupLeds() {
  leds.begin();
  leds.setBrightness(BRIGHTNESS);
  leds.show(); 
}

void setupArms() {
  for (byte side=0; side<NUM_SIDES; side++) {
    ensureArmLow(side);
  }
}

void moveArm(int pin, int from, int to) {
  servo.attach(pin);
  delay(ARM_DELAY);
  for (int i=0; i<=ARM_STEPS; i++) {
    servo.write(map(i, 0, ARM_STEPS, from, to));
    delay(ARM_DELAY);
  }
  delay(ARM_DELAY_LONG);
  servo.detach();
}

void ensureArmLow(byte side) {
  servo.attach(armPin[side]);
  delay(ARM_DELAY);
  servo.write(armLimitDown[side]);
  delay(ARM_DELAY_LONG);
  servo.detach();
}

void lowerArm(byte side) {
  moveArm(armPin[side], armLimitUp[side], armLimitDown[side]);
}

void raiseArm(byte side) {
  moveArm(armPin[side], armLimitDown[side], armLimitUp[side]);
}

void soundSignal() {
  int freq = 110;

  for (int i=0; (i<6); i++) {
    tone(PIEZO_PIN, freq);
    delay(TONE_DELAY);
    noTone(PIEZO_PIN);
    freq += freq;
  }
  digitalWrite(PIEZO_PIN, LOW);
}

void setAllLedsToColor(long color) {
  for (int l=0; l<NUM_LEDS; l++) {
    leds.setPixelColor(l, color);
  }
}

void glowEyes() {
  for (int j=0; j<3; j++) {
    for (int i=0; i<256; i++) {
      setAllLedsToColor((long)i<<16);
      showAll();
    }
    for (int i=255; i>=0; i--) {
      setAllLedsToColor((long)i<<16);
      showAll();
    }
  }
}


void drawCountDown(byte side, int seconds, long color) {
  int numLedsOn;
  
  numLedsOn = (seconds/DELTA)+1;
  
  for (int i=0; (i<numLedsOn); i++) {
    leds.setPixelColor(ledOffset[side]+(ledRotation[side]+i)%LEDS_PER_RING, color);
  }

  for (int i=numLedsOn; (i<LEDS_PER_RING); i++) {
    leds.setPixelColor(ledOffset[side]+(ledRotation[side]+i)%LEDS_PER_RING, BACKGND_COLOR);
  }
}

void showAll() {
  leds.show();
}

long eyeTicks = 1;
int  dir      = 6;

void drawPupil(int dir){
  for (byte side=0; side<NUM_SIDES; side++) {
    leds.setPixelColor(ledOffset[side]+(ledRotation[side]+dir)%LEDS_PER_RING, EYE_COLOR);
  }
}

void drawLid(int from, int to){
  for (byte side=0; side<NUM_SIDES; side++) {
    for (int i=from; i<=to; i++) {
      leds.setPixelColor(ledOffset[side]+(ledRotation[side]+i)%LEDS_PER_RING, LID_COLOR);
    }
  }
}

void drawClosingLid(long tick){
  if (tick<6) {
    drawLid(10-tick, 14+tick);
  } else {
    drawLid(   tick, 24-tick);
  }
}

long animateEyes() {
  int newDir;
  
  if (0==random(1000)) {
    newDir = 5+random(3);
    if (abs(dir-newDir)<2) {
      dir = newDir;
    } // no else
  } // no else
  
  setAllLedsToColor(BALL_COLOR);
  drawPupil(dir);

  if (eyeTicks<11) {
    drawClosingLid(eyeTicks);
  } else {
    drawLid(11, 13);
  }
  
  if (eyeTicks == 0) {
    eyeTicks = 200+random(50);
  } // no else
  
  showAll();

  eyeTicks--;
}

