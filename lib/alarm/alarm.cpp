#include <Arduino.h>
#include <warningLight.cpp>

const int alarmPin = 4;

//Five second timer varibles
int fiveSeconds = 5000;
int prevAlarmLoop = 0;


//Sets up the alarm component
void radioAlarmInitialization(){
    pinMode(alarmPin, OUTPUT);
    Serial.println("Alarm initialised");
    
    //Extra sound check due to being such an important feature.
    Serial.println("Alarm test activated");
    digitalWrite(alarmPin, 1);
    delay(1000);
    digitalWrite(alarmPin, 0);
    Serial.println("Alarm check complete");

}

//Method used to output to serial monitor if radiation reaches Amber or Red Levels 
void serialMonitorWarningMessage(){
    
    float radation = radationValueReturned();
    
    int alarmValue = ledColorSet();

    while(alarmValue > 0){

    if(alarmValue == 1){
        Serial.println("Amber warning Activated");
        Serial.print("Radation levels have reached: ");
        Serial.println(radation);
    }
    else if(alarmValue == 2){
        Serial.println("RED ALERT Activated");
        Serial.print("Radation levels have reached: ");
        Serial.println(radation);
        Serial.println("Radation has reached dangerous levels");
    }
    break;
}

}

//This method is used to see if the alarm needs to be activated 
void radationAlarmCheck(){
    
    while(alarm > 0){
    
        if(alarm > 0){
            //Records current time since system started 
            int time = millis();

            if(time - prevAlarmLoop > fiveSeconds){
                prevAlarmLoop = time;
                digitalWrite(alarmPin, 1);
                serialMonitorWarningMessage();
                delay(1000);

            }
        else{
            digitalWrite(alarmPin, 0);
        }
    }
    break;
    }

}

