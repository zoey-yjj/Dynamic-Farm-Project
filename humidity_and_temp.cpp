#include "DHT.h"
#define Type DHT11
int sensePin = 2;
DHT HT(sensePin, Type);
float humidity;
float tempC;
float tempF;
int setTime = 500;
int dt = 1000;
int fan = 4;
int led1 = 8;
int led2 = 7;

void setup() {
    // setup code, run once:
    Serial.begin(9600);
    HT.begin();
    delay(setTime);

    // Declaring fan and led as output
    pinMode(fan, OUTPUT);
    pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);
}

void loop() {
    humidity = HT.readHumidity();
    tempC = HT.readTemperature();
    tempF = HT.readTemperature(true);

    Serial.print("Humidity: ");
    Serial.print(humidity);
    Serial.print("% Temperature: ");
    Serial.print(tempC);
    Serial.print(" C ");
    Serial.print(tempF);
    Serial.println(" F ");

    if (tempC > 33) {
        analogWrite(fan, 255);
        digitalWrite(led2, HIGH);
        digitalWrite(led1, HIGH);
        Serial.println("Fan Speed: 100%   ");
        Serial.println("Light one and two are on");

    } else if (tempC > 31) {
        analogWrite(fan, 240);
        digitalWrite(led2, HIGH);
        digitalWrite(led1, HIGH);
        Serial.println("Fan Speed: 80%    ");
        Serial.println("Light one and two are on");

    } else if (tempC > 29){
        analogWrite(fan, 210);
        digitalWrite(led2, HIGH);
        digitalWrite(led1, HIGH);
        Serial.println("Fan Speed: 60%    ");
        Serial.println("Light one and two are on");

    } else if (tempC > 27) {
        analogWrite(fan, 180);
        digitalWrite(led1, HIGH);
        Serial.println("Fan Speed: 40%    ");
        Serial.println("Light one is on");

    } else if (tempC > 25) {
        analogWrite(fan, 150);
        digitalWrite(led1, HIGH);
        Serial.print("Fan Speed: 20%    ");
        Serial.println("Light one is on");

    } else if (tempC <= 25) {
        analogWrite(fan, 0);
        Serial.println("Fan OFF");
    }

    delay(dt);
}
