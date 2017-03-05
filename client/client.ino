#include <ESP8266WiFi.h>
#include <WiFiClient.h>

const int LED = D7;
const int BUTTON = D2;
int  val = 0;
WiFiClient client;


const char* WIFI_SSID = "";
const char* WIFI_PSK = "";


//Server info
const char http_site[] = "94.177.173.229";
const int http_port = 3002;

bool state = false;


// the setup function runs once when you press reset or power the board
void setup() {
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT);
  Serial.begin(9600);
  Serial.println("Startup");
  connectWiFi();
}

// the loop function runs over and over again forever
void loop() {

  val = digitalRead(BUTTON);
  if (val == HIGH) {
    digitalWrite(LED, HIGH);  //accende il led

    if(!state){
      state = true;
       if ( !getPage() ) {
        Serial.println("POST request failed");
       }
    }

  }
  else {
    digitalWrite(LED, LOW);   //spegne il led
        if(state){
      state = false;
       if ( !getPage() ) {
        Serial.println("POST request failed");
       }
    }

  }
}




// Attempt to connect to WiFi
void connectWiFi() {

  // Set WiFi mode to station (client)
  WiFi.mode(WIFI_STA);

  // Initiate connection with SSID and PSK
  WiFi.begin(WIFI_SSID, WIFI_PSK);

  // Blink LED while we wait for WiFi connection
  while ( WiFi.status() != WL_CONNECTED ) {
    delay(100);
  }
}





// Perform an HTTP POST request to a remote page
bool getPage() {

  // Attempt to make a connection to the remote server
  if ( !client.connect(http_site, http_port) )  return false;

  if(state){
    // Make an HTTP POST request
    client.println("POST /updateState?secret_id=segreto&status=true HTTP/1.1");
    client.print("Host: ");
    client.println(http_site);
    client.println("Connection: close");
    client.println();
  } else {
    client.println("POST /updateState?secret_id=segreto&status=false HTTP/1.1");
    client.print("Host: ");
    client.println(http_site);
    client.println("Connection: close");
    client.println();
  }

  return true;
}
