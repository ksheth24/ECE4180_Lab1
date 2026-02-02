
#define POT 3
#define LED_PIN 22
#define AI1 4
#define AI2 5

void setup() {
  // put your setup code here, to run once:
  Serial.beging(115200);
  ledAttach(LED_PIN, 2000, 12);
  pinMode(AI1, OUTPUT);
  pinMode(AI2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int time = 0;
  int potValue = analogRead(POT);  
  bool finished = false;
  ledcWrite(LED_PIN, 2048);

  if (time > 0) {
    while (potValue > 3200 && time > 0) {
      digitalWrite(AI1, HIGH);
      digitalWrite(AI2, LOW);
      time--;
      delay(1);
      while (potValue < 100) {
        digitalWrite(AI1, LOW);
        digitalWrite(AI2, LOW);
        delay(1);
      }
    }
  }
    while (potValue > 3200) {
      //speaker on
    }
  } else if (Serial.available()) {
    time = Serial.parseInt() * 1000;
  }


}
