#include "Manipulator.h"
#include "Control.h"
#include "SerialCommunication.h"

#define arduino Serial
#define LENGHT 5
#define OPTION 9

SerialCommunication serial;

Manipulator manipulator("MP001");
Control control;

bool option;

int pins[LENGHT] = {4, 5, 6, 7, 8};
int initialPositions[LENGHT] = {90, 60, 50, 140, 0};

int * positions;

unsigned long previousMillis = 0;
const long interval = 1000;

String data = "";

void setup() 
{
  arduino.begin(9600);

  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(2, INPUT_PULLUP);
  pinMode(option, INPUT);
  
  manipulator.setPins(pins, LENGHT);
  manipulator.setPositions(initialPositions, LENGHT);

  serial.doHandshake("{\"Id\": \"MP001\", \"Data\": \"Hello\"}");

  delay(1000);
}

void loop() 
{
  option = digitalRead(OPTION);
  
  if (option != LOW)
  {
    serial.receive();
    arduino.println(serial.getMsg().as<String>());

    if (serial.getMsg() != NULL && serial.getMsg() != serial.getLastMsg())
    {
      int servo = serial.getMsg()["Parte"].as<int>();
      int destiny = serial.getMsg()["Posicao"].as<int>();
  
      manipulator.online(servo, destiny);
    }
  }
  else
  {
    unsigned long currentMillis = millis();

    if (currentMillis - previousMillis >= interval)
    {
      previousMillis = currentMillis;
      positions = control.controlPositions(A0, A1, A2, A3, 2);
    }

    manipulator.offline(positions);
  }

}
