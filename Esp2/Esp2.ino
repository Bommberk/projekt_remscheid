#include "../assets/includes.h"

/******** LEDs ********/


/****** Sensoren ******/
// Motion Sensor
int motionSensorPin = D0;
bool motionSensorValue;
// Analog Temperature Sensor
int temperatureSensorPin = A0;
float temperatureSensorValue;


/**** Functions ****/
void setup()
{
    
    Serial.begin(115200);
    mq.setup();
}

void loop()
{
    // PIR Motion Sensor
    motionSensorValue = s.getMotionSensor(motionSensorPin);
    Serial.print("PIR Motion Sensor Wert: ");
    Serial.println(motionSensorValue);
    Serial.println("---------------------");

    // Analog Temperature Sensor
    temperatureSensorValue = s.getTemperatureSensor(temperatureSensorPin);
    Serial.print("Analog Temperature Sensor Wert: ");
    Serial.println(temperatureSensorValue);
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
