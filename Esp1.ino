#include "includes.h"

/******** LEDs ********/
// LED 
int ledPin = 13;
bool ledState = false;
// LED2

// LED3

/****** Sensoren ******/
// Infrarot Sensor
int infraredSensorPin = D0;
int infraredSensorValue;
// Ultraschall Sensor
int ultrasonicSensorPin = 1;
int ultrasonicSensorValue;


/**** Functions ****/
void setup()
{
    pinMode(ledPin, OUTPUT);
    pinMode(infraredSensorPin, INPUT);
    pinMode(ultrasonicSensorPin, INPUT);
    pinMode(motionSensorPin, INPUT);
    Serial.begin(115200);
    mq.setup();
}

void loop()
{
    // InverredSensor
    infraredSensorValue = s.getInfreredSensor(infraredSensorPin);
    Serial.print("Infrarot Sensor Wert: ");
    Serial.println(infraredSensorValue);
    Serial.println("---------------------");

    // UltrasonicSensor
    


    // Ausführung
    if(um.delayWithoutDelay(previousMillis,5000)){mq.send("guten tag");}
    // action();
}
    
void action()
{
    digitalWrite(ledPin,ledState);
}
