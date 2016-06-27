#ifndef __SENSORS_H__
#define __SENSORS_H__

#include <Arduino.h>
#include "config.h"

#define LENGTH_MEAS_ROW       50

boolean adjust(int &value, int pinUp, int pinDown, int delta, int minimum, int maximum);
int readTemp(boolean left);

#endif
