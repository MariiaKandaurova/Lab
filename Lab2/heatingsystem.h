#pragma once

class HeatingSystem {
public:
  HeatingSystem(int startingTemperature) : _temperature(startingTemperature) { }
  void ChangeTemperature(int newTemperature);
  void ChangeTemperatureDelta(int deltaTemperature);
  int GetTemperature();
private:
  int _temperature;
};
