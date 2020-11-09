#include <Arduino.h>
#include <radiationSensor.cpp>

const int redLight = 0;
const int amberLight = 1;
const int greenLight = 2;

float radationLevel = 0;


//Class used to set up LED light 
void ledSetup(){
    
    radationSensorSetup();
    
    pinMode(redLight, OUTPUT);
    pinMode(amberLight, OUTPUT);
    pinMode(greenLight, OUTPUT);
    Serial.println("LED initialised");

}

int ledColorSet(){
    int alarm;
	float radationFloatValue = radationValueReturned();
    Serial.println(radationFloatValue);
    delay(2000);

    if (isnan(radationFloatValue)) {
		Serial.println("Failed to read radation levels from DHT sensor!");
		Serial.println("Ensure radation sensor is connected correctly");
		delay(2000);
	}

	if (radationFloatValue >= 35 && radationFloatValue <= 60) {
		digitalWrite(greenLight, HIGH);
		digitalWrite(amberLight, LOW);
		digitalWrite(redLight, LOW);
		
		alarm = 0;
		 
	}

	else if ((radationFloatValue >= 25 && radationFloatValue <= 34) || (radationFloatValue >= 60 && radationFloatValue <= 75)) {
		digitalWrite(greenLight, HIGH);
		digitalWrite(amberLight, LOW);
		digitalWrite(redLight, HIGH);
		
		alarm = 1;
		
	}
	else {
		digitalWrite(greenLight, LOW);
		digitalWrite(amberLight, LOW);
		digitalWrite(redLight, HIGH);
		
		alarm = 2;
	}
	
	return alarm;
}





