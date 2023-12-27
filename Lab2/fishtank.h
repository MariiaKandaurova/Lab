#pragma once
#include "fish.h"
#include "foodsystem.h"
#include "lightingsystem.h"
#include "watersystem.h"
#include "decoration.h"
#include "heatingsystem.h"
#include <vector>

class FishTank {
public:
	FishTank() : _heatingsystem(0), _watersystem(0) {}
	void AddFish(Fish* fish);
	void AddFood(int food);
	void AddDecoration(Decoration* decoration);
	void RemoveFish(int position);
	void RemoveDecoration(int position);
	void FeedAllFish();
	void UpdateDay();
	void Clean();
	bool LightStatus();
	void Print();
	void TurnOnLight();
	void TurnOffLight();
	void ToggleLight();
	void SetTemperature(int temperature);
	void AddTemperature(int deltaTemperature);
	int GetTemperature();
	int GetDirtiness();
	Fish* GetFish(int position);
	Decoration* GetDecoration(int position);
private:
	std::vector<Fish*> _fishList;
	std::vector<Decoration*> _decorationList;
	HeatingSystem _heatingsystem;
	WaterSystem _watersystem;
	FoodSystem _foodsystem;
	LightingSystem _lightingsystem;
};
