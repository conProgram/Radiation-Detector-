#include <Arduino.h>
#include <radiationSensor.cpp>

const int redLight = 0;
const int amberLight = 1;
const int greenLight = 2;

//float radationValue;

//Class used to set up LED light 
void ledSetup(){
    
    radationSensorSetup();
    
    pinMode(redLight, OUTPUT);
    pinMode(amberLight, OUTPUT);
    pinMode(greenLight, OUTPUT);
    Serial.println("LED initialised");

}

void ledColorSet(){
    float radationValue2 = 10;
    Serial.println(radationValue2);
    delay(2000);



}

