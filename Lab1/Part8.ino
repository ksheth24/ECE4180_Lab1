#include <ESP32Servo.h>

Servo myServo;

void setup() {
  Serial.begin(115200);
  myServo.attach(4);
  pinMode(5, INPUT_PULLUP);
  pinMode(18, INPUT_PULLUP);
  pinMode(19, INPUT_PULLUP);
  pinMode(21, INPUT_PULLUP);
}

void loop() {
  if (!digitalRead(5)) {
    myServo.write(0);
    Serial.println("0 Degree Angle");
    delay(500);
  } else if (!digitalRead(18)) {
    myServo.write(45);
    Serial.println("45 Degree Angle");
    delay(500);
  } else if (!digitalRead(19)) {
    myServo.write(90);
    Serial.println("90 Degree Angle");
    delay(500);
  } else if (!digitalRead(21)) {
    myServo.write(135);
    Serial.println("135 Degree Angle");
    delay(500);
  }
}
