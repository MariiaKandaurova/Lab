#include "watersystem.h"

void WaterSystem::ClearWater() {
  _dirtiness = 0;
}

void WaterSystem::AddDirtinessDelta(int dirtiness) {
  _dirtiness += dirtiness;
}


int WaterSystem::GetDirtiness() {
	return _dirtiness;
}