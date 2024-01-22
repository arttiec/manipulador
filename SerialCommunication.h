#ifndef SERIALCOMMUNICATION_H
#define SERIALCOMMUNICATION_H

#include <ArduinoJson.h>

class SerialCommunication
{
  private:
    StaticJsonDocument<100> msg;
    StaticJsonDocument<100> lastMsg;
    
  public:
    SerialCommunication();

    StaticJsonDocument<100> getMsg() const;
    StaticJsonDocument<100> getLastMsg() const;

    void doHandshake(String data);
    void waitHandshake(String data); 

    void receive();
    void send(String msg);
};

#endif
