#include "C:/Users/JimMohncke/Documents/Remscheid Berufsschule/Projekt/assets/includes.h"

/******** LEDs ********/


/****** Sensoren ******/
// Infrarot Sensor
int infraredSensorPin = D0;
bool infraredSensorValue;
// Ultraschall Sensor
int ultrasonicSensorPin = D1;
int ultrasonicTrigPin = D2;
double ultrasonicSensorValue;


/**** Functions ****/
void setup()
{
    pinMode(infraredSensorPin, INPUT);
    pinMode(ultrasonicSensorPin, INPUT);
    pinMode(ultrasonicTrigPin, OUTPUT);
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
    if(um.delayWithoutDelay(previousMillis,50)){
        ultrasonicSensorValue = s.getUltrasonicSensor(ultrasonicSensorPin,ultrasonicTrigPin);
    }
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
