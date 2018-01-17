#include <ESP8266WiFi.h>
#include <ArduinoHttpClient.h>
#include <Adafruit_NeoPixel.h>
 
#define PIN      13
#define N_LEDS 1
 
Adafruit_NeoPixel strip = Adafruit_NeoPixel(N_LEDS, PIN, NEO_GRB + NEO_KHZ800);
const char* ssid = "Godbey WiFi";
const char* pass = "godbeywifi";


const char* host = "patrickg.net";  // server address
int port = 80;

WiFiClient wifi;
HttpClient client = HttpClient(wifi, host, port);

String response;
int statusCode = 0;

void setup() {
  strip.begin();
  Serial.begin(115200);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  // print the SSID of the network you're attached to:
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // print your WiFi shield's IP address:
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);
}

void loop() {

  strip.Color(0, 0, 0); // Green
  Serial.println("making GET request");
  client.get("/school.php");

  // read the status code and body of the response
  statusCode = client.responseStatusCode();
  response = client.responseBody();

  if(response == "open"){
    chase(strip.Color(0, 255, 0)); // green
  }
  if(response == "closed"){
    chase(strip.Color(255, 0, 0)); // red
  }
  if(response == "delay"){
    chase(strip.Color(255, 100, 0)); // pink
  }

  Serial.print("Status code: ");
  Serial.println(statusCode);
  Serial.print("Response: ");
  Serial.println(response);
  Serial.println("Wait five seconds");
  delay(5000);
}
static void chase(uint32_t c) {
  for(uint16_t i=0; i<strip.numPixels()+4; i++) {
      strip.setPixelColor(i  , c); // Draw new pixel
      strip.setPixelColor(i-4, 0); // Erase pixel a few steps back
      strip.show();
      delay(300);
  }
}
