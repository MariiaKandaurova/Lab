#pragma once
#include <string>

class Fish {
public:
	Fish(const std::string& species, int size, int weight) : _species(species), _size(size), _weight(weight), _atefood(0) {
		_foodRation = _size * _weight / 100;
		_dirtiness = _size * 10;
	}
	void ChangeFoodRation(int newFoodRation);
	int GetFoodRation();
	void Feed();
	void UpdateDay();
	int GetDirtiness();
	void Print();
	std::wstring ToString();
private:
	std::string _species;
	int _foodRation;
	int _size;
	int _weight;
	int _dirtiness;
	int _atefood;
	bool _isAlive = true;
};
