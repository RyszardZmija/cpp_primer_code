#include "Book.h"

Book::Book(const std::string &title, const std::string &author,
	const std::string &publisher, unsigned no_pages, double avg_price,
	Cover_type cover) :
	title(title), author(author), publisher(publisher), number_of_pages(no_pages),
	average_retail_price(avg_price), cover(cover) {}

Book::Book(const std::string &title, const std::string &author,
	const std::string &publisher, unsigned no_pages, double avg_price) :
	Book(title, author, publisher, no_pages, avg_price, Cover_type::paperback) {}

std::ostream &operator<<(std::ostream &os, const Book &b) {
	os << b.title << "\t" << b.author << "\t" << b.publisher << "\n";
	os << "Number of pages: " << b.number_of_pages << '\n';
	os << "Retail price: " << b.average_retail_price << '\n';
	os << "Type of cover: ";

	switch (b.cover) {
	case Cover_type::paperback:
		os << "paperback";
		break;
	case Cover_type::hardcover:
		os << "hardcover";
		break;
	default:
		break;
	}

	return os;
}

std::istream &operator>>(std::istream &is, Book &b) {
	std::string c;
	std::getline(is, b.title);
	std::getline(is, b.author);
	std::getline(is, b.publisher);

	is >> b.number_of_pages >> b.average_retail_price >> c;

	if (is) {
		b.cover = c == "hardcover" ?
			Cover_type::hardcover : Cover_type::paperback;
	}
	else {
		b = Book();
	}

	return is;
}

bool operator==(const Book &lhs, const Book &rhs) {
	return lhs.title == rhs.title &&
		lhs.author == rhs.author &&
		lhs.publisher == rhs.publisher &&
		lhs.number_of_pages == rhs.number_of_pages &&
		lhs.average_retail_price == rhs.average_retail_price &&
		lhs.cover == rhs.cover;
}

bool operator!=(const Book &lhs, const Book &rhs) {
	return !(lhs == rhs);
}