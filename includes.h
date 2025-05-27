#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include "assets/classes/UsefullMethods.h"
#include "assets/classes/Sensors.h"
#include "assets/classes/Msqtt.h"


/**** Sekunden ****/
unsigned long previousMillis = 0;
const long standardInterval = 1000;

/**** Objekte ****/
UsefullMethods um;
Sensors s;
Msqtt mq;