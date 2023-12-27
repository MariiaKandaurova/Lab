#pragma once
#include <string>

class Client {
public:
  Client(const std::string& name, int startingMoney) : _name(name), _money(startingMoney), _tickets(0) {}
  void BuyTicket(int TicketCost);
  void AddMoney(int money);
  void UseTicket();
  int GetMoney();
  int GetTickets();
private:
  int _money;
  int _tickets;
  std::string _name;
};
