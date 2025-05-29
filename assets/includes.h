// #include <ESP8266WiFi.h>
// #include <PubSubClient.h>
// #include <math.h>
// #include <OneWire.h>
// #include <dht11.h>
#include "classes/UsefullMethods.h"
#include "classes/Sensors.h"
#include "classes/Msqtt.h"


/**** Sekunden ****/
unsigned long previousMillis = 0;
const long standardInterval = 1000;

/**** Objekte ****/
UsefullMethods um;
Sensors s;
Msqtt mq;