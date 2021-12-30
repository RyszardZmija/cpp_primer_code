#include "Limited_quote.h"

Limited_quote::Limited_quote(const std::string &book_no, double price,
	std::size_t quantity, double discount) :
	Discounted_quote(book_no, price, quantity, discount) {}

double Limited_quote::net_price(std::size_t n) const {
	if (n > quantity) {
		return (1 - discount) * price * quantity +
			(n - quantity) * price;
	}
	else {
		return (1 - discount) * price * n;
	}
}