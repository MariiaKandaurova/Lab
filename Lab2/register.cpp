#include "register.h"


Register::Register(int startMoney) {
  _money = startMoney;
}

int Register::GetMoney() {
  return _money;
}

void Register::AddMoney(int amount) {
  _money += amount;
}

void Register::SubstractMoney(int amount) {
  _money -= amount;
}
