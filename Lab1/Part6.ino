#define POT 3
#define LED_PIN 22
#define AI1 4
#define AI2 5

void setup() {
  Serial.begin(115200);
  ledcAttach(LED_PIN, 2000, 12);
  pinMode(AI1, OUTPUT);
  pinMode(AI2, OUTPUT);
}

void loop() {
  int potValue = analogRead(POT);
  int center = 1650;
  ledcWrite(LED_PIN, 2 * abs(potValue - center));
  Serial.println(potValue);

 if (abs(potValue - center) < 100) {
  digitalWrite(AI1, LOW);
  digitalWrite(AI2, LOW);
  Serial.println("Stop");
 } else if (potValue - center > 0) {
    digitalWrite(AI1, HIGH);
    digitalWrite(AI2, LOW);
    Serial.println("Forwards");
 } else {
    digitalWrite(AI1, LOW);
    digitalWrite(AI2, HIGH);
    Serial.println("Backwards");
 }
  
}
