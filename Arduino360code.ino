#include <Servo.h>

Servo servo180;
int switchPin = 2;

void setup() {
  servo180.attach(9);
  pinMode(switchPin, INPUT);
}

void loop() {
  int state = digitalRead(switchPin);

  if (state == HIGH) {
    servo180.write(90);   // or whatever angle you want
  } else {
    servo180.write(0);
  }
}
