#include <Servo.h>

// -------------------------
// SERVO OBJECTS
// -------------------------
Servo jack360;      // continuous rotation servo
Servo jackFight;    // 180° servo (continuous fight loop)
Servo akuFall;      // 180° servo (45° fall loop)

// -------------------------
// PIN ASSIGNMENTS
// -------------------------
const int switchJack360 = 2;   // original switch 1
const int switchJackFight = 3; // original switch 2 (same behavior, new name)
const int switchAku      = 4;  // new switch 3

const int pinJack360     = 9;   // continuous rotation servo
const int pinJackFight   = 6;   // 180° servo (Jack fight)
const int pinAkuFall     = 10;  // 180° servo (Aku fall)

// -------------------------
// ANIMATION SETTINGS
// -------------------------

// Jack spin
int spinSpeed = 120;
int stopSpeed = 90;

// Jack fight animation (same behavior as your old Aku loop)
int fightUp = 90;
int fightDown = 0;
int fightSpeed = 5;

// Aku fall animation (45° loop)
int akuUp = 90;
int akuDown = 45;
int akuSpeed = 5;

// -------------------------
// SETUP
// -------------------------
void setup() {
  jack360.attach(pinJack360);
  jackFight.attach(pinJackFight);
  akuFall.attach(pinAkuFall);

  pinMode(switchJack360, INPUT);
  pinMode(switchJackFight, INPUT);
  pinMode(switchAku, INPUT);

  jack360.write(stopSpeed);
  jackFight.write(fightUp);
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
  // SWITCH 2 — JACK FIGHT (same behavior as old Aku loop)
  // -------------------------
  if (digitalRead(switchJackFight) == HIGH) {

    // Down swing
    for (int pos = fightUp; pos >= fightDown; pos--) {
      jackFight.write(pos);
      delay(fightSpeed);

      if (digitalRead(switchJackFight) == LOW) break;
    }

    // Up swing
    for (int pos = fightDown; pos <= fightUp; pos++) {
      jackFight.write(pos);
      delay(fightSpeed);

      if (digitalRead(switchJackFight) == LOW) break;
    }
  }

 // -------------------------
// SWITCH 3 — AKU FALL/RISING AT 90° CONTINUOUSLY
// -------------------------
if (digitalRead(switchAku) == HIGH) {

  // Fall to 0° (full 90° drop)
  for (int pos = akuUp; pos >= akuDown; pos--) {
    akuFall.write(pos);
    delay(akuSpeed);

    if (digitalRead(switchAku) == LOW) break;
  }

  // Rise back up to 90°
  for (int pos = akuDown; pos <= akuUp; pos++) {
    akuFall.write(pos);
    delay(akuSpeed);

    if (digitalRead(switchAku) == LOW) break;
    }
  }
}