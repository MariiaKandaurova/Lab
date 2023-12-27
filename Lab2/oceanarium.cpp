#include "oceanarium.h"
#include <iostream>

void Oceanarium::BuyTicket(Client& client) {
	client.BuyTicket(_ticketCost);
}

Fish* Oceanarium::GetFish(int tankpos, int position) {
	if (tankpos <= _fishtanks.size()) {
		return _fishtanks[tankpos - 1].GetFish(position);
	}
	return nullptr;
}

Decoration* Oceanarium::GetDecoration(int tankpos, int position) {
	if (tankpos <= _fishtanks.size()) {
		return _fishtanks[tankpos - 1].GetDecoration(position);
	}
	return nullptr;
}

bool Oceanarium::GetLightStatus(int tankpos) {
	if (tankpos <= _fishtanks.size()) {
		return _fishtanks[tankpos - 1].LightStatus();
	}
	return false;
}

void Oceanarium::AddTank() {
	_fishtanks.emplace_back();
}

void Oceanarium::RemoveTank(int position) {
	_fishtanks.erase(_fishtanks.begin() + position - 1);
}

void Oceanarium::PrintTanks() {
	int i = 1;
	for (auto& tank : _fishtanks) {
		std::cout << "tank " << i++ << ": " << std::endl;
		tank.Print();
	}
}

void Oceanarium::AddFishToTank(Fish* fish, int position) {
	if (position <= _fishtanks.size())
		_fishtanks[position - 1].AddFish(fish);
}

void Oceanarium::CleanAllTanks() {
	for (auto& tank : _fishtanks) {
		tank.Clean();
	}
}

void Oceanarium::UpdateDay() {
	for (auto& tank : _fishtanks) {
		tank.UpdateDay();
	}
}

int Oceanarium::GetDirtiness(int tankpos) {
	if (tankpos <= _fishtanks.size()) {
		return _fishtanks[tankpos - 1].GetDirtiness();
	}
	return -1;
}

int Oceanarium::GetTemperature(int tankpos) {
	if (tankpos <= _fishtanks.size()) {
		return _fishtanks[tankpos - 1].GetTemperature();
	}
	return -1;
}

void Oceanarium::AddDecorationToTank(Decoration* decoration, int position) {
	if (position <= _fishtanks.size())
		_fishtanks[position - 1].AddDecoration(decoration);
}

void Oceanarium::RemoveFishFromTank(int position, int tankpos) {
	if (tankpos <= _fishtanks.size())
		_fishtanks[tankpos - 1].RemoveFish(position);
}

void Oceanarium::RemoveDecorationFromTank(int position, int tankpos) {
	if (tankpos <= _fishtanks.size())
		_fishtanks[tankpos - 1].RemoveDecoration(position);
}

void Oceanarium::FillAllFood(int amount) {
	if (_register.GetMoney() >= amount) {
		_register.SubstractMoney(amount);
		int foodPerTank = amount / _fishtanks.size();
		for (auto& tank : _fishtanks) {
			tank.AddFood(foodPerTank);
		}
	}
}

void Oceanarium::AddFood(int amount, int position) {
	if (_register.GetMoney() >= amount && position <= _fishtanks.size()) {
		_register.SubstractMoney(amount);
		_fishtanks[position - 1].AddFood(amount);
	}
}

void Oceanarium::TurnOnLight(int tankpos) {
	if (tankpos <= _fishtanks.size()) {
		_fishtanks[tankpos - 1].TurnOnLight();
	}
}

void Oceanarium::TurnOffLight(int tankpos) {
	if (tankpos <= _fishtanks.size()) {
		_fishtanks[tankpos - 1].TurnOffLight();
	}
}

void Oceanarium::ToggleLight(int tankpos) {
	if (tankpos <= _fishtanks.size()) {
		_fishtanks[tankpos - 1].ToggleLight();
	}
}

void Oceanarium::SetTemperature(int temperature, int tankpos) {
	if (tankpos <= _fishtanks.size()) {
		_fishtanks[tankpos - 1].SetTemperature(temperature);
	}
}

void Oceanarium::AddTemperature(int deltaTemperature, int tankpos) {
	if (tankpos <= _fishtanks.size()) {
		_fishtanks[tankpos - 1].AddTemperature(deltaTemperature);
	}
}
