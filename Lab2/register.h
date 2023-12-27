#pragma once

class Register {
public:
  Register(int startMoney); 
  int GetMoney();
  void AddMoney(int amount);
  void SubstractMoney(int amount);
private:
  int _money;
};
