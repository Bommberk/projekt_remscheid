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
// Bewegungs Sensor
int motionSensorPin = 2;
int motionSensorValue;


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
    pinMode(motionSensorPin, INPUT);
    Serial.begin(115200);
    mq.setup();
}

void loop()
{
    // InverredSensor
    infraredSensorValue = s.getInfreredSensor(infraredSensorPin);
    Serial.println(infraredSensorValue);

    // MotionSensor
    motionSensorValue = s.getMotionSensor(motionSensorPin);


    // Ausführung
    if(um.delayWithoutDelay(previousMillis,5000)){mq.send("guten tag");}
    // action();
}
    
void action()
{
    digitalWrite(ledPin,ledState);
}
