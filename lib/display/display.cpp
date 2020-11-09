#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <alarm.cpp>

//Size of the screen attached to the microcontroller using a small OLED display for now
#define SCREEN_WIDTH 128 
#define SCREEN_HEIGHT 64 

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

String outputMessage;
float radationLevelToScreen;

//Screen initalization
void outputScreenInitialization(){
    if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    Serial.println("Screen not connected...");
  }

Serial.println("Screen has been initialized");
}

String dataOnScreen(){
    
    int alarmSwitch = ledColorSet();
    
    switch(alarmSwitch){
        case 0:
        outputMessage = "Everything is good";
        case 1:
        outputMessage = "AMBER warning activated";
        case 2:
        outputMessage = "RED AlERT";

    }
    
    return outputMessage;
}

void screenDisplay(){
    
    dataOnScreen();
    
    int radationIntoInt = radationValueReturned();

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  // Display static text
  display.println(outputMessage);
  display.print("Radation level is: ");
  display.println(radationIntoInt);
  display.display();
}