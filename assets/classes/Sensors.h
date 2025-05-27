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
    public: bool getUltrasonicSensor(const int sensorPin)
    {
        bool sensorState = false;
        return sensorState;
    }

    // PixyCam2


    /***** ESP2 *****/
    // PIR Motion Sensor
    public: bool getMotionSensor(const int sensorPin)
    {
        bool sensorState = digitalRead(sensorPin);
        return sensorState;
    }

    // Analog Temperature Sensor
    public: float getTemperatureSensor(const int sensorPin)
    {
        float temperature = 0.0;
        return temperature;
    }

    /***** ESP3 *****/
    // Flame Sensor
    public: bool getFlameSensor(const int sensorPin)
    {
        bool sensorState = false;
        return sensorState;
    }

    // Analog Gas Sensor
    public: float getGasSensor(const int sensorPin)
    {
        float gasValue = 0.0;
        return gasValue;
    }

    // 18B20 Temperature Sensor
    public: bool getTemperatureSensor18B20(const int sensorPin)
    {
        bool sensorState = false;
        return sensorState;
    }

    /***** ESP4 *****/
    // DHT11 Temperature and Humidity Sensor
    public: bool getDHT11Sensor(const int sensorPin)
    {
        bool sensorState = false;
        return sensorState;
    }

    // Vapor Sensor
    public: float getVaporSensor(const int sensorPin)
    {
        float vaporValue = 0.0;
        return vaporValue;
    }

    /***** RASPI *****/
    // Digital Buzzer


    // DS3231 Clock Module
};
