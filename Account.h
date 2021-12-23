#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

class Account {
	
public:
	Account() : amount(0) {}
	Account(const std::string &owner, double amount) :
		owner(owner), amount(amount) {}

	void calculate();
	double get_amount() const { return amount; }
	static double rate() { return interest_rate; }
	static void rate(double);

private:
	std::string owner;
	double amount;
	static double interest_rate;

	static double init_rate();
};
#endif