#include "C:/Users/JimMohncke/Documents/Remscheid Berufsschule/Projekt/assets/includes.h"

/******** LEDs ********/


/****** Sensoren ******/
// Flame Sensor
int flameSensorPin = D0;
bool flameSensorValue;
// 18B20 Temperatur Sensor
int temperatureSensorPin = D1;
bool temperatureSensorValue;
// Analog Gas Sensor
int gasSensorPin = A0;
double gasSensorValue;


/**** Functions ****/
void setup()
{
    pinMode(flameSensorPin, INPUT);
    pinMode(gasSensorPin, INPUT);
    Serial.begin(115200);
    mq.setup();
}

void loop()
{
    // Flame Sensor
    flameSensorValue = s.getFlameSensor(flameSensorPin);
    Serial.print("Flame Sensor Wert: ");
    Serial.println(flameSensorValue);
    Serial.println("---------------------");
    
    // 18B20 Temperatur Sensor
    temperatureSensorValue = s.getTemperatureSensor18B20(temperatureSensorPin);
    Serial.print("18B20 Temperatur Sensor Wert: ");
    Serial.println(temperatureSensorValue);
    Serial.println("---------------------");

    // Gas Sensor
    gasSensorValue = s.getGasSensor(gasSensorPin);
    Serial.print("Gas Sensor Wert: ");
    Serial.println(gasSensorValue);
    Serial.println("---------------------");


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
