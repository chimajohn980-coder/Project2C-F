#include <Servo.h>

Servo servo360;
int switchPin = 3;

void setup() {
  servo360.attach(10);
  pinMode(switchPin, INPUT);
}

void loop() {
  int state = digitalRead(switchPin);

  if (state == HIGH) {
    servo360.write(180);   // full-speed forward
  } else {
    servo360.write(90);    // stop
  }
}
