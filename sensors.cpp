#include "sensors.h"

int pinUp    [NUM_SIDES] = {LEFT_UP_PIN,     RIGHT_UP_PIN    }; 
int pinDown  [NUM_SIDES] = {LEFT_DOWN_PIN,   RIGHT_DOWN_PIN  }; 
int pinSensor[NUM_SIDES] = {LEFT_SENSOR_PIN, RIGHT_SENSOR_PIN};

long lastTime;
int  history[NUM_SIDES][HISTORY_SIZE];

void setupSensors() {
  int value;
  
  for (byte side=0; side<NUM_SIDES; side++) {
    value = readTemp(side);
    for (int i=0; i<HISTORY_SIZE; i++) {
      history[side][i] = value;
    }
  }
}

boolean adjust(byte side, int &value) {
  boolean result = false;
  int     begin  = value;
  
  if (LOW == digitalRead(pinUp[side])) {
    value = min(MAX_VALUE, value+DELTA);
    result = true;
  } else if (LOW == digitalRead(pinDown[side])) {
    value = max(MIN_VALUE, value-DELTA);
    result = true;
  }
  
  if (begin != value) {
    delay(200);
  }
  
  return result;
}

int readTemp(byte side) {
  int sum = 0;
  
  for (int i=0; i<MEAS_ROW_SIZE; i++) {
    sum += analogRead(pinSensor[side]);
  }

  return sum/MEAS_ROW_SIZE; 
}

boolean isSuddenRaise(byte side) {
  boolean result = false;
  int     temp;
  long    now;
  
  temp = readTemp(side);
  
  if (temp > history[side][HISTORY_SIZE-1]+1) {
    result = true;
  }

  now = millis();
  
  if (now > lastTime+HISTORY_DELTA) {
    for (int i=0; i<HISTORY_SIZE-1; i++) {
      history[side][i] = history[side][i+1];
    }
    
    history[side][HISTORY_SIZE-1] = temp;
    lastTime = now;
  }  
  
  return result;
}

