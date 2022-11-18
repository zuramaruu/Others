#include "DHT.h"

#define RAIN_A 13
#define LDR_P 14
#define DHTPIN 27
#define DHTTYPE DHT11  // Type

DHT dht(DHTPIN, DHTTYPE);

uint32_t u_time;

void setup() {
        Serial.begin(115200);
        pinMode(RAIN_A, INPUT);
        pinMode(LDR_P, INPUT);
        dht.begin();
}

void loop() {
        if (millis() - u_time >= 1000) {

                Serial.print("ADC = ");
                Serial.println(analogRead(RAIN_A));

                Serial.print("LDR = ");
                Serial.println(!digitalRead(LDR_P));

                float t = dht.readTemperature();  // read temperature
                float h = dht.readHumidity();     // read humidity

                Serial.print(F(" Humidity: "));
                Serial.print(h);
                Serial.print(F("%  Temperature: "));
                Serial.print(t);
                Serial.print(F("°C "));
                Serial.println();

                u_time = millis();
        }
}