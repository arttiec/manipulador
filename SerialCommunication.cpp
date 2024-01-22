#include "SerialCommunication.h"

#define arduino Serial

SerialCommunication::SerialCommunication()
{
}

StaticJsonDocument<100> SerialCommunication::getMsg() const
{
  return this->msg;
}

StaticJsonDocument<100> SerialCommunication::getLastMsg() const
{
  return this->lastMsg;
}

void SerialCommunication::doHandshake(String data)
{
  // {"Id": "ESP", "Data": "Ok"}
  unsigned long previousMillis = 0;
  
  while (this->msg["Data"] != "Ok")
  {
    unsigned long currentMillis = millis();
    
    if (currentMillis - previousMillis > 1000)
    {
      previousMillis = currentMillis;
      this->send(data);  
    }

    this->receive();
    arduino.println(this->msg.as<String>());
  }

  arduino.println("Handshake received: " + this->msg["Data"].as<String>() + " from " + this->msg["Id"].as<String>());
}

void SerialCommunication::waitHandshake(String data)
{
  while (this->msg["Data"] != "Hello")
  {
    this->receive();
  }

  this->send(data);
  
  arduino.println("Handshake received: " + msg["Data"].as<String>() + " from " + msg["Id"].as<String>());
}

void SerialCommunication::receive()
{
  String data;
  
  if (arduino.available() > 0) 
  {
    data = arduino.readStringUntil('\n');
    this->lastMsg = this->msg;

    StaticJsonDocument<100> doc;
    DeserializationError error = deserializeJson(doc, data);
    
    if (error) 
    {
      Serial.println("Erro ao desserializar JSON!");
    } 
    else 
    {
      this->msg = doc;
    }
  }
}

void SerialCommunication::send(String msg)
{
  arduino.println(msg);
}
