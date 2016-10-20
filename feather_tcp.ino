/*
 *  Simple HTTP get webclient test
 */

#include <ESP8266WiFi.h>

const char* ssid     = "itpsandbox";
const char* password = "NYU+s0a!+P?";

const char* host = "172.22.151.124";

void setup() {
  Serial.begin(115200);
  delay(200);

  
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

int value = 0;

boolean clientStared = false;

WiFiClient client;

void loop() {
  delay(2000);

  
  ++value;

  Serial.print("Connecting to ");
  Serial.println(ssid);
  Serial.print("connecting to ");
  Serial.println(host);
  
  // Use WiFiClient class to create TCP connections

  if( clientStared == false ){
    
    const int httpPort = 8080;

    Serial.print("I have not opening port, this is my ");
    Serial.print(value);
    Serial.println(" try");
    
    
    if (!client.connect(host, httpPort)) {
      Serial.println("connection failed");
      return;
    }

    clientStared = true;   

    delay(500);

    client.print("n=Rubin\n");
    client.print("i");

  }
  else{
     Serial.println("I already started the port");
  }
  
  // This will send the request to the server
  client.print("r");
  delay(500);
  
  // Read all the lines of the reply from server and print them to Serial
  while(client.available()){
    String line = client.readStringUntil('\r');
    Serial.print(line);
  }

}
