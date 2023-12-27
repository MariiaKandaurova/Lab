#include "lightingsystem.h"

void LightingSystem::TurnOff() {
  _isOn = false;
}

void LightingSystem::TurnOn() {
  _isOn = true;
}

void LightingSystem::Toggle() {
  _isOn = !_isOn;
}
