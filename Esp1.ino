#include "includes.h"

/******** LEDs ********/


/****** Sensoren ******/
// Infrarot Sensor
int infraredSensorPin = D0;
bool infraredSensorValue;
// Ultraschall Sensor
int ultrasonicSensorPin = 1;
bool ultrasonicSensorValue;


/**** Functions ****/
void setup()
{
    pinMode(infraredSensorPin, INPUT);
    pinMode(ultrasonicSensorPin, INPUT);
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
    ultrasonicSensorValue = s.getUltrasonicSensor(ultrasonicSensorPin);
    Serial.print("Ultraschall Sensor Wert: ");
    Serial.println(ultrasonicSensorValue);
    Serial.println("---------------------");


    // Ausführung
    action();
}
    
void action()
{
    if(um.delayWithoutDelay(previousMillis, 2000)){
        mq.send("guten Tag ESP1");
        Serial.println("Action ausgeführt");
    }
}
