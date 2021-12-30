#include "Bulk_quote.h"

Bulk_quote::Bulk_quote(const std::string &book_no, double price,
	std::size_t quantity, double discount) :
	Discounted_quote(book_no, price, quantity, discount) {}

double Bulk_quote::net_price(std::size_t n) const {
	if (n >= quantity) {
		return (1 - discount) * price * n;
	}
	else {
		return price * n;
	}
}