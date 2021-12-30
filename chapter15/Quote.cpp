#include "Quote.h"

#include <iostream>

double print_total(std::ostream &os,
	const Quote &item, std::size_t n) {

	double ret = item.net_price(n);

	os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: "
		<< ret << '\n';

	return ret;
}

void Quote::debug() const {
	std::cout << "book_no: " << book_no << '\n';
	std::cout << "price: " << price << '\n';
}