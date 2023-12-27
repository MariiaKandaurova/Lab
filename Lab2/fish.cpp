#include "fish.h"
#include <iostream>
#include <string>

void Fish::ChangeFoodRation(int newFoodRation) {
  _foodRation = newFoodRation;
}

int Fish::GetFoodRation() {
  return _foodRation;
}

void Fish::Feed() {
  _atefood += _foodRation;
}

void Fish::UpdateDay() {
  if (!_isAlive)
    return;

  _atefood -= _foodRation;
  if (_atefood < 0)
    _isAlive = false;
}

int Fish::GetDirtiness() {
  return _dirtiness;
}

void Fish::Print() {
  if (_isAlive)
    std::cout << "Species: " << _species << " food ration: " << _foodRation << " size: " << _size << " weight: " << _weight  << " dirtiness: " << _dirtiness << std::endl;
  else 
    std::cout << "Species: " << _species << " dead" << std::endl;
}

std::wstring Fish::ToString() {
    std::wstring str = L"";
    if (_isAlive)
        str += L"Species: " + std::wstring(_species.begin(), _species.end()) + L" food ration: " + std::to_wstring(_foodRation) + L" size: " + std::to_wstring(_size) + L" weight: " + std::to_wstring(_weight) + L" dirtiness: " + std::to_wstring(_dirtiness);
    else
        str += L"Species: " + std::wstring(_species.begin(), _species.end()) + L" dead ";
    return str;
}