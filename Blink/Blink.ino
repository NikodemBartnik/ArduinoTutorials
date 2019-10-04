int LED = 13;          // Led connected to pin 13 (integrated LED)
int pause = 1000;      // Set the waiting time

void setup() {
pinMode(LED, OUTPUT);     // Set pin 13 as output
}

void loop() {
digitalWrite(LED, HIGH);    // Turns the LED on
delay(pause);               // Waits the defined time
digitalWrite(LED, LOW);     // Turns the LED off
delay(pause);               // Waits the defined time
}
