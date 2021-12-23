#include "Account.h"

double Account::init_rate() {
	return 0.23;
}

double Account::interest_rate = init_rate();

// normal member function calculate
void Account::calculate() {
	amount += amount * interest_rate;
}

void Account::rate(double new_rate) {
	interest_rate = new_rate;
}