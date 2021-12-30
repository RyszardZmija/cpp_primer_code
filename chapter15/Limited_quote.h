#ifndef LIMITED_QUOTE_H
#define LIMITED_QUOTE_H

#include "Discounted_quote.h"

class Limited_quote : public Discounted_quote {
public:
	Limited_quote() = default;
	Limited_quote(const std::string &, double, std::size_t, double);

	double net_price(std::size_t) const override;
};
#endif