#include "C:/Users/JimMohncke/Documents/Remscheid Berufsschule/Projekt/assets/includes.h"

/******** LEDs ********/


/****** Sensoren ******/
// Ultrasonic Sensor
int  ultrasonicSensorPin = D0;
int  ultrasonicTrigPin = D1;
double motionSensorValue;
// 
int temperatureSensorPin = A0;
double temperatureSensorValue;


/**** Functions ****/
void setup()
{
    pinMode()
    Serial.begin(115200);
    mq.setup();
}

void loop()
{
    


    // Ausführung
    action();
}
    
void action()
{
    if(um.delayWithoutDelay(previousMillis, 2000)){
        mq.send("guten Tag ESP2");
        Serial.println("Action ausgeführt");
    }
}
