#ifndef BULK_QUOTE_H
#define BULK_QUOTE_H

#include "Discounted_quote.h"

class Bulk_quote : public Discounted_quote {
public:
	Bulk_quote() = default;
	Bulk_quote(const std::string &, double, std::size_t, double);

	double net_price(std::size_t) const override;
	Bulk_quote *clone() const & { return new Bulk_quote(*this); }
	Bulk_quote *clone() &&{ return new Bulk_quote(std::move(*this)); }

};
#endif