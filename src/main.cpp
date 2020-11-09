#include <Arduino.h>
#include <display.cpp>


void setup() {
  radationSensorSetup();
  ledSetup();
  radioAlarmInitialization();
  outputScreenInitialization();
  
}

void loop() {
  ledColorSet();
  radationAlarmCheck();
  screenDisplay();
}