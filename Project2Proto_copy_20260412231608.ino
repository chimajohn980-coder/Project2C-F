#include <Servo.h>

// -------------------------
// SERVO OBJECTS
// -------------------------
Servo jack360;      // continuous rotation servo
Servo akuFall;      // 180° servo

// -------------------------
// PIN ASSIGNMENTS
// -------------------------
const int switchJack360 = 2;   // copper tape switch 1
const int switchAku      = 3;  // copper tape switch 2

const int pinJack360     = 9;  // continuous rotation servo
const int pinAkuFall     = 6;  // 180° servo

// -------------------------
// ANIMATION SETTINGS
// -------------------------

// Continuous rotation servo speeds
int spinSpeed = 120;   // >90 = clockwise spin
int stopSpeed = 90;    // 90 = stop

// Aku fall animation
int akuUp = 90;        // standing angle
int akuDown = 0;       // fallen angle
int akuSpeed = 5;      // smaller = slower fall

// -------------------------
// SETUP
// -------------------------
void setup() {
  jack360.attach(pinJack360);
  akuFall.attach(pinAkuFall);

  pinMode(switchJack360, INPUT);
  pinMode(switchAku, INPUT);

  jack360.write(stopSpeed);
  akuFall.write(akuUp);
}

// -------------------------
// LOOP
// -------------------------
void loop() {

  // -------------------------
  // SWITCH 1 — JACK 360° SPIN
  // -------------------------
  if (digitalRead(switchJack360) == HIGH) {
    jack360.write(spinSpeed);
  } else {
    jack360.write(stopSpeed);
  }

  // -------------------------
  // SWITCH 2 — AKU FALL CONTINUOUSLY
  // -------------------------
  if (digitalRead(switchAku) == HIGH) {

    // Fall
    for (int pos = akuUp; pos >= akuDown; pos--) {
      akuFall.write(pos);
      delay(akuSpeed);

      // If switch released mid-animation, break
      if (digitalRead(switchAku) == LOW) break;
    }

    // Reset
    for (int pos = akuDown; pos <= akuUp; pos++) {
      akuFall.write(pos);
      delay(akuSpeed);

      // If switch released mid-animation, break
      if (digitalRead(switchAku) == LOW) break;
    }
  }
}





