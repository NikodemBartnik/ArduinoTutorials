#define TRIG 2
#define ECHO 3

void setup() {
  Serial.begin(9600);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
}

void loop() {
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(5);
  digitalWrite(TRIG, LOW);

  float t = pulseIn(ECHO, HIGH);
  float distance = t*0.017015;
  Serial.print("Distance: ");
  Serial.println(distance);
  delay(500);
}
