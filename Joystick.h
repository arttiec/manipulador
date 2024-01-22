#ifndef JOYSTICK_H
#define JOYSTICK_H

#include <Arduino.h>

class Joystick {
  private:
    int positionX;
    int positionY;
    int positionZ;
    
  public:
    Joystick();

    int getPositionX() const;
    int getPositionY() const;
    int getPositionZ() const;

    void mapComponents(uint8_t pin1, uint8_t pin2, uint8_t pin3);

    ~Joystick();
};

#endif
