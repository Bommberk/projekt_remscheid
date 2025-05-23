// #include <ESP8266WiFi.h>
// #include <PubSubClient.h>
#include "assets/classes/UsefullMethods.h"
#include "assets/classes/Sensors.h"
#include "assets/classes/Msqtt.h"

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
// Ultraschall Sensor
int ultrasonicSensorPin = 1;
int ultrasonicSensorValue;


/**** Sekunden ****/
unsigned long previousMillis = 0;
const long standardInterval = 1000;

/**** Objekte ****/
UsefullMethods um;
Sensors s;
Msqtt mq;

void setup()
{
    pinMode(ledPin, OUTPUT);
    pinMode(infraredSensorPin, INPUT);
    pinMode(ultrasonicSensorPin, INPUT);
    Serial.begin(115200);
}

void loop()
{
    // InverredSensor
    infraredSensorValue = s.getInfreredSensor(infraredSensorPin);
    Serial.println(infraredSensorValue);

    // MotionSensor
    motionSensorValue = s.getMotionSensor(sensorPin);


    // Ausführung
    if(um.delayWithoutDelay(previousMillis,5000)){um.send("guten tag",client);}
    // action();
}
    
void action()
{
    digitalWrite(ledPin,ledState);
}
