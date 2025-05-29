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
    public: bool getUltrasonicSensor(const int sensorPin,int trigPin)
    {
        long duration,distance;
        digitalWrite(trigPin, LOW); 
        delayMicroseconds(2); 

        digitalWrite(trigPin, HIGH);
        delayMicroseconds(10); 
        digitalWrite(trigPin, LOW);

        duration = pulseIn(echoPin, HIGH);
        
        //Calculate the distance (in cm) based on the speed of sound.
        distance = duration/58.2;

        return distance;
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
    public: double getTemperatureSensor(const int sensorPin)
    {
        double val=analogRead(0);
        double fenya=(val/1023)*5;
        double r=(5-fenya)/fenya*4700;
        double temperature = 1/(log(r/10000) /3950 + 1/(25+273.15))-273.15; 

        return temperature;
    }

    /***** ESP3 *****/
    // Flame Sensor
    public: bool getFlameSensor(const int sensorPin)
    {
        bool sensorState = digitalRead(sensorPin);
        return sensorState;
    }

    // Analog Gas Sensor
    public: double getGasSensor(const int sensorPin)
    {
        int sensorValue = analogRead(sensorPin);
        double gasValue = (sensorValue*100)/1024;
        return gasValue;
    }

    // 18B20 Temperature Sensor
    public: float getTemperatureSensor18B20(const int sensorPin)
    {
        OneWire ds(sensorPin);
        
        byte data[12];
        byte addr[8];
        
        if ( !ds.search(addr)) {
            //no more sensors on chain, reset search
            ds.reset_search();
            return -1000;
        }
        
        if ( OneWire::crc8( addr, 7) != addr[7]) {
            Serial.println("CRC is not valid!");
            return -1000;
        }
        
        if ( addr[0] != 0x10 && addr[0] != 0x28) {
            Serial.print("Device is not recognized");
            return -1000;
        }
        
        ds.reset();
        ds.select(addr);
        ds.write(0x44,1); // start conversion, with parasite power on at the end
        
        byte present = ds.reset();
        ds.select(addr);    
        ds.write(0xBE); // Read Scratchpad
        
        for (int i = 0; i < 9; i++) { // we need 9 bytes
            data[i] = ds.read();
        }
        ds.reset_search();
        
        byte MSB = data[1];
        byte LSB = data[0];
        
        float tempRead = ((MSB << 8) | LSB); //using two's compliment
        float TemperatureSum = tempRead / 16;  

        return TemperatureSum;
    }

    /***** ESP4 *****/
    // DHT11 Temperature and Humidity Sensor
    public: bool getDHT11Sensor(const int sensorPin)
    {
        bool sensorState = false;
        return sensorState;
    }

    // Vapor Sensor
    public: double getVaporSensor(const int sensorPin)
    {
        int sensorValue = analogRead(sensorPin);
        double vaporValue = (sensorValue*100)/1024;
        return vaporValue;
    }

    /***** RASPI *****/
    // Digital Buzzer


    // DS3231 Clock Module
};
