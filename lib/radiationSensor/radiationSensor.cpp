//This class uses a DH11 Sensor to test for radation 
//For the purposes of this project and testing we will use humidity as the values to check 

#include <Wire.h>
//DHT Sensor Config
#include <DHT.h> //Sensor library
#define DHTPIN 15 //Pin of sensor
#define DHTTYPE DHT11   // DHT 11


DHT dht(DHTPIN, DHTTYPE); //Sets sensor pin and which type of sensor we are using in the DHL


//Defines where the radation value is stored
float radationValue;

//Setting up the sensor
void radationSensorSetup(){
    dht.begin();
        Serial.println("Radation Sensor initialised");
}

//Radation Value is checked and stored in a float 
float radationValueReturned(){
    return radationValue = dht.readHumidity();
}