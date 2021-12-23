#include "Book.h"

Book::Book(const std::string &title, const std::string &author,
	const std::string &publisher, unsigned no_pages, double avg_price,
	Cover_type cover) :
	title(title), author(author), publisher(publisher), number_of_pages(no_pages),
	average_retail_price(avg_price), cover(cover) {}

Book::Book(const std::string &title, const std::string &author,
	const std::string &publisher, unsigned no_pages, double avg_price) :
	Book(title, author, publisher, no_pages, avg_price, Cover_type::paperback) {}

std::ostream &print(std::ostream &os, const Book &b) {
	os << b.title << " " << b.author << " " << b.publisher << '\n';
	os << "Number of pages: " << b.number_of_pages << '\n';
	os << "Price = " << b.average_retail_price << " for ";
	switch (b.cover) {
	case Cover_type::hardcover:
		os << "hardcover\n";
		break;
	case Cover_type::paperback:
		os << "paperback\n";
		break;
	default:
		os << "Error!\n";
		break;
	}

	return os;
}