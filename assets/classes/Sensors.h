class Sensors
{
    /***** ESP1 *****/
    // Infrared Obstacle Aviodance Sensor
    public: bool getInfreredSensor(const int sensorPin)
    {
        const int ledPin =  13;
        bool sensorState = false;   
        sensorState = digitalRead(sensorPin);
        return !sensorState;
    }
    

    // SR01 Ultrasonic Sensor


    // PixyCam2


    /***** ESP2 *****/
    // PIR Motion Sensor
    public: bool getMotionSensor(const int sensorPin)
    {
        bool sensorState = digitalRead(sensorPin);
        return sensorState;
    }

    // Analog Temperature Sensor


    /***** ESP3 *****/


    // Flame Sensor


    // Analog Gas Sensor


    // 18B20 Temperature Sensor


    /***** ESP4 *****/
    // DHT11 Temperature and Humidity Sensor


    // Vapor Sensor


    /***** RASPI *****/
    // Digital Buzzer


    // DS3231 Clock Module
};
