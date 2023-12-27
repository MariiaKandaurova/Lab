#pragma once

class LightingSystem {
public:
	LightingSystem() : _isOn(false) { }
	void TurnOn();
	void TurnOff();
	void Toggle();
	bool Status() { return _isOn; }
private:
	bool _isOn;
};
