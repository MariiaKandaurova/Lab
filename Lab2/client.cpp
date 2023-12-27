#include "client.h"


void Client::BuyTicket(int TicketCost) {
	if (TicketCost <= _money) {
		_money -= TicketCost;
		_tickets++;
	}
}

void Client::AddMoney(int money) {
	_money += money;
}

void Client::UseTicket() {
	_tickets--;
}

int Client::GetMoney() {
	return _money;
}

int Client::GetTickets() {
	return _tickets;
}