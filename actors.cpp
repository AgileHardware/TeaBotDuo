#include <Adafruit_NeoPixel.h>
#include <Servo.h>

#include "actors.h"

Adafruit_NeoPixel leds = Adafruit_NeoPixel(NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);
Servo servo;



void setupLeds() {
  leds.begin();
  leds.setBrightness(BRIGHTNESS);
  leds.show(); 
}

void setupArms() {
  lowerArm(LEFT);
  lowerArm(RIGHT);
}

void moveArm(int pin, int from, int to) {
  servo.attach(pin);
  for (int i=0; i<=ARM_STEPS; i++) {
    servo.write(map(i, 0, ARM_STEPS, from, to));
    delay(ARM_DELAY);
  }
  servo.detach();
}

void lowerArm(boolean left) {
  if (left) {
    moveArm(LEFT_ARM_PIN,  LEFT_ARM_UPPER,  LEFT_ARM_LOWER );
  } else {
    moveArm(RIGHT_ARM_PIN, RIGHT_ARM_UPPER, RIGHT_ARM_LOWER);
  } 
}

void raiseArm(boolean left) {
  if (left) {
    moveArm(LEFT_ARM_PIN,  LEFT_ARM_LOWER,  LEFT_ARM_UPPER );
  } else {
    moveArm(RIGHT_ARM_PIN, RIGHT_ARM_LOWER, RIGHT_ARM_UPPER);
  } 
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

void creepyGlowingEyes() {
  for (int j=0; j<3; j++) {
    for (int i=0; i<256; i++) {
      setAllLedsToColor((long)i<<16);
      leds.show();
    }
    for (int i=255; i>=0; i--) {
      setAllLedsToColor((long)i<<16);
      leds.show();
    }
  }
}


void drawCountDown(boolean left, int seconds, long color) {
  int rotate, offset;
  int ledsOn;
  
  ledsOn = (seconds/DELTA)+1;
  
  if (left) {
    rotate = OFFSET_LEFT;
    offset = 0;
  } else {
    rotate = OFFSET_RIGHT;
    offset = LEDS_PER_RING;
  }
  
  for (int i=0; (i<ledsOn); i++) {
    leds.setPixelColor(offset+(rotate+i)%LEDS_PER_RING, color);
  }

  for (int i=ledsOn; (i<LEDS_PER_RING); i++) {
    leds.setPixelColor(offset+(rotate+i)%LEDS_PER_RING, BACKGND_COLOR);
  }

  leds.show();
}

long eyeTicks=1;
int  dir = 6;

void drawPupil(int dir){
  leds.setPixelColor((0*LEDS_PER_RING)+(OFFSET_LEFT +dir)%LEDS_PER_RING, EYE_COLOR);
  leds.setPixelColor((1*LEDS_PER_RING)+(OFFSET_RIGHT+dir)%LEDS_PER_RING, EYE_COLOR);
}

void drawLid(int from, int to){
  for (int i=from; i<=to; i++) {
    leds.setPixelColor((0*LEDS_PER_RING)+(OFFSET_LEFT +i)%LEDS_PER_RING, LID_COLOR);
    leds.setPixelColor((1*LEDS_PER_RING)+(OFFSET_RIGHT+i)%LEDS_PER_RING, LID_COLOR);
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
  
  for (int i=0; i<NUM_LEDS; i++) {
    leds.setPixelColor(i, BALL_COLOR);
  } 
  
  drawPupil(dir);

  if (eyeTicks<11) {
    drawClosingLid(eyeTicks);
  } else {
    drawLid(11, 13);
  }
  
  if (eyeTicks == 0) {
    eyeTicks = 200+random(50);
  } // no else
  
  leds.show();

  eyeTicks--;
}


