#ifndef DISCOUNTED_QUOTE_H
#define DISCOUNTED_QUOTE_H

#include "Quote.h"

class Discounted_quote : public Quote {
public:
	Discounted_quote() = default;
	Discounted_quote(const std::string &, double, std::size_t, double);

	// no meaning for net_price because this class doesn't
	// implement any meaningful discount strategy
	double net_price(std::size_t) const = 0;
	void debug() const override;

protected:
	std::size_t quantity = 0;
	double discount = 0.0;
};
#endif