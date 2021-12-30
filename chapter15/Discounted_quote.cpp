#include "Discounted_quote.h"

Discounted_quote::Discounted_quote(const std::string &book_no,
	double price, std::size_t quantity, double discount) :
	Quote(book_no, price), quantity(quantity), discount(discount) {}

void Discounted_quote::debug() const {
	Quote::debug();
	std::cout << "quantity: " << quantity << '\n';
	std::cout << "discount: " << discount << '\n';
}