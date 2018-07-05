#include <Servo.h>

Servo myservo;
int pos = 0;
boolean isOpen = true;

const int analogInPin = A0;
int sensorValue = 0;

void setup() {
  myservo.attach(8);
  Serial.begin(9600);
  close();
}
void open() {
  if (!isOpen) {
    isOpen = true;
    myservo.write(170);
  }
}

void close() {

  if (isOpen) {
    isOpen = false;
    for (pos = 170; pos >= 2; pos -= 1) {
      myservo.write(pos);
      delay(15);
    }
  }
}

void loop() {
  sensorValue = analogRead(analogInPin);
  Serial.println(sensorValue);
  if (sensorValue > 300) {
    open();
  } else {
    close();
  }

  delay(500);
}
