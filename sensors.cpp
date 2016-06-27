#include "sensors.h"


boolean adjust(int &value, int pinUp, int pinDown, int delta, int minimum, int maximum) {
  boolean result = false;
  int     begin  = value;
  
  if (LOW == digitalRead(pinUp)) {
    value = min(maximum, value+delta);
  } else if (LOW == digitalRead(pinDown)) {
    value = max(minimum, value-delta);
  }
  
  if (begin != value) {
    delay(200);
    result = true;
  }
  
  return result;
}

int readTemp(boolean left) {
  int sum=0;
  int pin;

  if (left) {
    pin = LEFT_SENSOR_PIN;
  } else {
    pin = RIGHT_SENSOR_PIN;
  }
  
  for (int i=0; i<LENGTH_MEAS_ROW; i++) {
    sum += analogRead(pin);
  }
  return sum/LENGTH_MEAS_ROW; 
}

