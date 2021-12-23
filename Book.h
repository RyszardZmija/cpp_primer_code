#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <iostream>
#include "Cover_type.h"

class Book {

	friend std::ostream &print(std::ostream &, const Book &);

public:
	// allow the compiler to synthesize the default constructor
	Book() = default;

	Book(const std::string &title, const std::string &author, const std::string &publisher,
		unsigned no_pages, double avg_price, Cover_type cover);

	Book(const std::string &title, const std::string &author, const std::string &publisher,
		unsigned no_pages, double avg_price);

private:
	std::string title;
	std::string author;
	std::string publisher;

	unsigned number_of_pages = 0;
	double average_retail_price = 0.0;
	
	Cover_type cover = Cover_type::paperback;
};

std::ostream &print(std::ostream &, const Book &);
#endif