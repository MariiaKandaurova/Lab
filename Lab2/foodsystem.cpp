#include "foodsystem.h"

void FoodSystem::AddFood(int food) {
  _food += food;
}

bool FoodSystem::TakeFood(int food) {
  if (_food >= food)
  {
    _food -= food;
    return true;
  }
  return false;
}
