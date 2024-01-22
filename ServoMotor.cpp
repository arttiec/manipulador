#include "ServoMotor.h"

ServoMotor::ServoMotor() 
{
};

ServoMotor::ServoMotor(String name_, int speed_) : name(name_), speed(speed_) 
{
};

int ServoMotor::getAngle() const 
{
  return this->angle;
}

void ServoMotor::toAttach(int pin) 
{
  this->servo.attach(pin);
};

void ServoMotor::rotate(int destiny) 
{
  this->servo.slowmove(destiny, this->speed);

  this->angle = destiny;

  while (this->servo.isMoving()) 
  {
    Serial.println();
  }
};


ServoMotor::~ServoMotor() {};

Effector::Effector() {};
