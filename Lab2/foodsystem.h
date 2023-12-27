#pragma once

class FoodSystem {
public:
  FoodSystem() : _food(0) { }
  FoodSystem(int startingFood) : _food(startingFood) { }
  void AddFood(int food);
  bool TakeFood(int food);
private:
  int _food;
};
