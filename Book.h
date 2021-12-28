#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <iostream>
#include "Cover_type.h"

class Book {

	friend std::ostream &operator<<(std::ostream &, const Book &);
	friend std::istream &operator>>(std::istream &, Book &);
	friend bool operator==(const Book &, const Book &);

public:
	// allow the compiler to synthesize the default constructor
	Book() = default;

	Book(const std::string &title, const std::string &author, const std::string &publisher,
		unsigned no_pages, double avg_price, Cover_type cover);

	Book(const std::string &title, const std::string &author, const std::string &publisher,
		unsigned no_pages, double avg_price);

	// this conversion operator is a bad idea but we're doing it for
	// the sake of completing an exercise
	explicit operator bool() const { return !title.empty(); }

private:
	std::string title;
	std::string author;
	std::string publisher;

	unsigned number_of_pages = 0;
	double average_retail_price = 0.0;

	Cover_type cover = Cover_type::paperback;
};

std::ostream &operator<<(std::ostream &, const Book &);
std::istream &operator>>(std::istream &, Book &);
bool operator==(const Book &, const Book &);
bool operator!=(const Book &, const Book &);

#endif