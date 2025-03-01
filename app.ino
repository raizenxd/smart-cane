#include <Arduino.h>
#include "Talkie.h"
#include "Vocab_US_Large.h"
#include "Vocab_Special.h"
#include "Vocab_US_TI99.h"
#include "Vocab_US_Clock.h"

Talkie voice;

#define TRIG_PIN 6
#define ECHO_PIN 7
#define BUZZER 12
#define AUDIO_OUT 4

long getDistance() {
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);
    
    long duration = pulseIn(ECHO_PIN, HIGH);
    long distance = duration * 0.034 / 2;  // Convert to cm
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");
    return distance;
}

void speak(const uint8_t* word) {
    Serial.println("Speaking...");
    voice.say(word);
    delay(1000);
}

void buzzer() {
    Serial.println("Buzzer activated");
    tone(BUZZER, 1000);
    delay(1000);
    noTone(BUZZER);
    delay(1000);
}

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
    Serial.begin(9600);
    while (!Serial);

    Serial.println("Smart Cane System Initialized");
    
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
    pinMode(BUZZER, OUTPUT);
    pinMode(AUDIO_OUT, OUTPUT);

    Serial.println("Starting test speech...");
    voice.say(sp3_WIND);
    voice.say(sp3_NORTHEAST);
    voice.say(sp3_GUSTING_TO);
    voice.say(sp3_FOURTY);
    voice.say(sp3_MILES);
    voice.say(sp3_PER);
    voice.say(sp3_HOUR);
}

void loop() {
    long frontDist = getDistance();
    
    if (frontDist < 30) {
        Serial.println("Obstacle detected! Checking left...");
        buzzer();
        speak(sp2_CHECK);
        speak(sp2_LEFT);
        delay(500);

        if (getDistance() > 30) {
            Serial.println("Left is clear, proceeding.");
            speak(sp2_GO);
            return;
        }

        Serial.println("Left is blocked, checking right...");
        buzzer();
        speak(sp2_CHECK);
        speak(sp2_RIGHT);
        delay(500);

        if (getDistance() > 30) {
            Serial.println("Right is clear, proceeding.");
            speak(sp2_GO);
            return;
        }

        Serial.println("Both sides blocked, stopping.");
    }

    delay(500);
}
