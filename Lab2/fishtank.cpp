#include "fishtank.h"

void FishTank::AddDecoration(Decoration* decoration) {
	_decorationList.push_back(decoration);
}

Fish* FishTank::GetFish(int position) {
	if (position <= _fishList.size()) {
		return _fishList[position - 1];
	}
	return nullptr;
}

Decoration* FishTank::GetDecoration(int position) {
	if (position <= _decorationList.size()) {
		return _decorationList[position - 1];
	}
	return nullptr;
}

bool FishTank::LightStatus() {
	return _lightingsystem.Status();
}

int FishTank::GetTemperature() {
	return _heatingsystem.GetTemperature();
}

void FishTank::AddFish(Fish* fish) {
	_fishList.push_back(fish);
}

void FishTank::RemoveFish(int position) {
	if (position < _fishList.size())
	{
		delete _fishList[position - 1];
		_fishList.erase(_fishList.begin() + position - 1);
	}
}

void FishTank::RemoveDecoration(int position) {
	if (position < _decorationList.size())
	{
		delete _decorationList[position - 1];
		_decorationList.erase(_decorationList.begin() + position - 1);
	}
}

void FishTank::FeedAllFish() {
	for (Fish* fish : _fishList) {
		if (_foodsystem.TakeFood(fish->GetFoodRation()))
			fish->Feed();
	}
}

void FishTank::UpdateDay() {
	int dirtinessDelta = 0;
	FeedAllFish();
	for (Fish* fish : _fishList) {
		fish->UpdateDay();
		dirtinessDelta += fish->GetDirtiness();
	}
	_watersystem.AddDirtinessDelta(dirtinessDelta);
}

int FishTank::GetDirtiness() {
	return _watersystem.GetDirtiness();
}

void FishTank::Clean() {
	_watersystem.ClearWater();
}

void FishTank::AddFood(int food) {
	_foodsystem.AddFood(food);
}

void FishTank::Print() {
	for (Fish* fish : _fishList) {
		fish->Print();
	}
}

void FishTank::ToggleLight() {
	_lightingsystem.Toggle();
}

void FishTank::TurnOnLight() {
	_lightingsystem.TurnOn();
}

void FishTank::TurnOffLight() {
	_lightingsystem.TurnOff();
}

void FishTank::SetTemperature(int temperature) {
	_heatingsystem.ChangeTemperature(temperature);
}
void FishTank::AddTemperature(int deltaTemperature) {
	_heatingsystem.ChangeTemperatureDelta(deltaTemperature);
}
