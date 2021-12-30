#ifndef QUOTE_H
#define QUOTE_H

#include <string>
#include <cstddef>
#include <iostream>

class Quote {
public:
	Quote() = default;
	Quote(const std::string &book_no, double price) :
		book_no(book_no), price(price) {}

	std::string isbn() const { return book_no; }

	virtual double net_price(std::size_t n) const { return n * price; }
	virtual void debug() const;
	virtual Quote *clone() const &{ return new Quote(*this); }
	virtual Quote *clone() &&{ return new Quote(std::move(*this)); }

	// base class should specify its destructor as virtual
	virtual ~Quote() = default;
	Quote(const Quote &) = default;
	Quote(Quote &&) = default;
	Quote &operator=(const Quote &) = default;
	Quote &operator=(Quote &&) = default;

private:
	std::string book_no;
protected:
	double price = 0.0;
};

double print_total(std::ostream &, const Quote &, std::size_t);
#endif