#include <dht.h>
#define outPin 8
#define VIBRATIONPIN 5


#define BLYNK_TEMPLATE_ID "TMPL2ijErC54j"
#define BLYNK_TEMPLATE_NAME "DHT"
#define BLYNK_AUTH_TOKEN "W2QZGcwudfhCNT5NGQtsfsVESy9xxuEq"


char ssid[] = "TEdataCDE53B";  // Your WiFi credentials.
char pass[] = "07914657xd";




#include <Blynk.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>


dht DHT;

int vibration;
float t;
float h;

void blynksetup() {

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  delay(1000);
}
void blynkLoop() {
  Blynk.run();                // Initiates Blynk
  Blynk.virtualWrite(V0, t);  // Temperature
  Blynk.virtualWrite(V1, h);  // Humidity
  // lux++;
  // Serial.println(lux);
  delay(1000);
}



void setup() {
  pinMode(VIBRATIONPIN, INPUT);
  Serial.begin(115200);
}

void loop() {
  vibration = analogRead(VIBRATIONPIN);

  int readData = DHT.read11(outPin);

  t = DHT.temperature;
  h = DHT.humidity;

  Serial.print("Temperature = ");
  Serial.print(t);
  Serial.print("°C | ");
  Serial.print((t * 9.0) / 5.0 + 32.0);
  Serial.println("°F ");
  Serial.print("Humidity = ");
  Serial.print(h);
  Serial.println("% ");
  Serial.println("");

  Serial.print("Vibration: ");
  Serial.println(vibration);

  delay(1000);
}