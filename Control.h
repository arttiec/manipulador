#ifndef CONTROL_H
#define CONTROL_H

#include "Joystick.h"

class Control { 
  private:
    Joystick L;
    Joystick R;
    
    int * positions;
    
  public:
    Control();

    int * controlPositions(uint8_t pin1, uint8_t pin2, uint8_t pin3, uint8_t pin4, uint8_t pin5);

    ~Control();
};

#endif
