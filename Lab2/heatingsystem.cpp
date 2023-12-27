#include "heatingsystem.h"

void HeatingSystem::ChangeTemperature(int newTemperature) {
  _temperature = newTemperature;
}

void HeatingSystem::ChangeTemperatureDelta(int deltaTemperature) {
  _temperature += deltaTemperature;
}

int HeatingSystem::GetTemperature() {
	return _temperature;
}