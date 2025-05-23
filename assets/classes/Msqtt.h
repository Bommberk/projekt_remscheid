WiFiClient espClient;
PubSubClient client(espClient);

class Msqtt
{
    const char* ssid = "Ikea Net";
    const char* password = "hallo123hallo";
    const char* mqtt_server = "172.20.10.3"; // IP deines Docker-Hosts

    public: void setup()
    {
        this->setup_wifi();
        client.setServer(this->mqtt_server, 1883);
    }
    // WiFi Setup
    public: void setup_wifi() 
    {
        WiFi.begin(this->ssid, this->password);
        Serial.print("Connect to WiFi: ");
        Serial.println(this->ssid);

        while(WiFi.status() != WL_CONNECTED){
            Serial.print(".");
            delay(500);
        }
        Serial.println();
        Serial.println("Connected");
    }
    // Reconnect
    public: void reconnect() {
        while(!client.connected()){
            if(client.connect("ESPClient")){
                client.subscribe("test/topic");
            }else{
                Serial.println("Nicht Verbunden");
                delay(5000);
            }
        }
    }
    // Send
    public: void send(const char* message)
    {
        if(!client.connected()){this->reconnect(client);}
        
        client.loop();
        client.publish("test/topic", message);
    }
}