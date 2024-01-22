#ifndef SERVOMOTOR_H
#define SERVOMOTOR_H

#include <Arduino.h>
#include <VarSpeedServo.h>

class ServoMotor {
  protected:
    VarSpeedServo servo;

    String name;

    int angle;
    int speed;

  public:
    ServoMotor();

    ServoMotor(String name_, int speed_ = 80);

    int getAngle() const;

    void toAttach(int pin);
    void rotate(int destiny);

    ~ServoMotor();
};

class Effector : public ServoMotor {
  private:
    int currenteState;
    int previousState;

  public:
    Effector();

    int getCurrentState() const;
    int getPreviousState() const;

    void open();
    void close();

    ~Effector();
};

#endif
