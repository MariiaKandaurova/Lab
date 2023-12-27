#pragma once

class WaterSystem {
public:
  WaterSystem(int startingDirtiness) : _dirtiness(startingDirtiness) { }
  void ClearWater();
  void AddDirtinessDelta(int dirtiness);
  int GetDirtiness();
private:
  int _dirtiness;
};
