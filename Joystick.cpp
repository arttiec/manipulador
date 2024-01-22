#include "Joystick.h"

Joystick::Joystick() {};

int Joystick::getPositionX() const {
  return this->positionX;
}

int Joystick::getPositionY() const {
  return this->positionY;
}

int Joystick::getPositionZ() const {
  // Serial.println(this->isPressed);

  return this->positionZ;
}

void Joystick::mapComponents(uint8_t pin1, uint8_t pin2, uint8_t pin3) {
  this->positionZ = digitalRead(pin3);

  int X = analogRead(pin1);
  X = map(X , 0, 1023, 0, 180);

  if (X > 100) {
    this->positionX = 1;
  } else if (X < 80) {
    this->positionX = -1;
  } else {
    this->positionX = 0;
  }

  int Y = analogRead(pin2);
  Y = map(Y, 0, 1023, 0,180);
  
  if (Y > 100) {
    this->positionY = 1;
  } else if (Y < 80) {
    this->positionY = -1;
  } else {
    this->positionY = 0;
  }
};

Joystick::~Joystick() {};
