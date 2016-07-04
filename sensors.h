#ifndef __SENSORS_H__
#define __SENSORS_H__

#include <Arduino.h>
#include "config.h"

#define MEAS_ROW_SIZE    50
#define HISTORY_SIZE     10
#define HISTORY_DELTA  2000  // store a value each 2 sec

void    setupSensors();
boolean adjust(byte side, int &value);
int     readTemp(byte side);
void    resetSuddenRaise();
boolean isSuddenRaise(byte side);

#endif
