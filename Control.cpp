#include "Control.h"

Control::Control() : L(), R() 
{
  this->positions = new int[5];
};

int * Control::controlPositions(uint8_t pin1, uint8_t pin2, uint8_t pin3, uint8_t pin4, uint8_t pin5) {
  L.mapComponents(pin1, pin2, pin5);
  R.mapComponents(pin3, pin4, pin5);

  this->positions[0] = R.getPositionY();
  this->positions[1] = R.getPositionX();
  this->positions[2] = L.getPositionY();
  this->positions[3] = L.getPositionX();
  this->positions[4] = L.getPositionZ();

  return this->positions;
};

Control::~Control() 
{
  delete[] positions;
};
