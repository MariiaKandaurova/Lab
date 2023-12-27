#pragma once
#include "fishtank.h"
#include "client.h"
#include "register.h"
#include <string>
#include <vector>

class Oceanarium {
public:
	Oceanarium(const std::string& name, int startingMoney) : _name(name), _register(startingMoney), _ticketCost(100) { }
	std::string GetName() { return _name; }
	int GetMoney() { return _register.GetMoney(); }
	void BuyTicket(Client& client);
	void FillAllFood(int amount);
	void AddTank();
	void RemoveTank(int position);
	void RemoveFishFromTank(int position, int tankpos);
	void RemoveDecorationFromTank(int position, int tankpos);
	void PrintTanks();
	void AddFishToTank(Fish* fish, int position);
	void AddDecorationToTank(Decoration* decoration, int position);
	void UpdateDay();
	void CleanAllTanks();
	void AddFood(int amount, int position);
	void TurnOnLight(int tankpos);
	void TurnOffLight(int tankpos);
	void ToggleLight(int tankpos);
	bool GetLightStatus(int tankpos);
	void SetTemperature(int temperature, int tankpos);
	int GetTemperature(int tankpos);
	void AddTemperature(int deltaTemperature, int tankpos);
	Fish* GetFish(int tankpos, int position);
	Decoration* GetDecoration(int tankpos, int position);
	int GetDirtiness(int tankpos);
private:
	std::string _name;
	int _ticketCost;
	Register _register;
	std::vector<FishTank> _fishtanks;
};
