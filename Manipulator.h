#ifndef MANIPULATOR_H
#define MANIPULATOR_H

#include "ServoMotor.h" 

class Manipulator {
  private:
    String id;

    ServoMotor * servos;

  public:
    Manipulator(String id_);

    String getId() const;

    void setPins(int * pins, int lenght);
    void setPositions(int * positions, int lenght);
    
    void online(int servo, int destiny);
    void offline(int * positions);

    ~Manipulator();

};

#endif
