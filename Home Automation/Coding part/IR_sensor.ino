#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>


char auth[] = "JV40IBwZj3rvC-T-41Qkgkl4mpWmfR0S";
char ssid[] = "Ram";
char pass[] = "0123456789";


#define IR A0
int ir;
void setup() {
Serial.begin(9600);
pinMode(IR, INPUT);
Blynk.begin(auth, ssid, pass);
}
void loop() {
ir = analogRead(IR);
Serial.println(ir);
if(ir <= 900)
{
 Serial.println("Object is present");
 Blynk.notify("Something is present");
}
else if (ir == 0)
{
 Serial.println("Empty");
}

Blynk.run();
}
