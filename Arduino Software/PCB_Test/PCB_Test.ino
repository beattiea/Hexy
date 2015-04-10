#include "Servo.h"

int current_pins[6] = {A10, A11, A13, A20, A15, A16};

Servo hip, knee, ankle;

void setup() {
    Serial.begin(115200);
    
    hip.attach(4);
    knee.attach(5);
    ankle.attach(6);
    
    pinMode(32, OUTPUT);
    pinMode(33, OUTPUT);
    pinMode(24, OUTPUT);
    
    pinMode(25, OUTPUT);
    digitalWrite(25, HIGH);
    
    digitalWrite(33, HIGH);
    digitalWrite(32, HIGH);
    digitalWrite(24, HIGH);
    
    pinMode(26, OUTPUT);
    pinMode(27, OUTPUT);
    
    pinMode(13, OUTPUT);
    digitalWrite(13, HIGH);
    
    delay(100);
}



int servo_val = 0;
int servo_dir = 1;

void loop() {
    if (servo_val < 3) {
        servo_dir = 3;
        digitalWrite(13, !digitalRead(13));
    }
    if (servo_val >= 180) {
        servo_dir = -3;
        digitalWrite(13, !digitalRead(13));
    }
    
    servo_val += servo_dir;
    
    hip.write(servo_val);
    knee.write(servo_val);
    ankle.write(servo_val);
    
    Serial.print("Servo_Val: ");
    Serial.println(servo_val);
    
    Serial.print("Battery: ");
    Serial.println(analogRead(28));
    
    Serial.println("Current Draws");
    for (int i = 0; i < 6; i++) {
        Serial.print("Servo ");
        Serial.print(i+1);
        Serial.print(": ");
        Serial.println(analogRead(current_pins[i]));
    }
    
    Serial.println();
    delay(20);
}
