#include "Sales_data.h"

#include <string>
#include <iostream>

double Sales_data::avg_price() const {

	if (units_sold) {
		return revenue / units_sold;
	}
	else {
		return 0;
	}
}

Sales_data::Sales_data(const std::string &s, unsigned cnt, double price) :
	book_no(s), units_sold(cnt), revenue(cnt *price) {}

Sales_data::Sales_data() : Sales_data("", 0, 0) {}

Sales_data::Sales_data(const std::string &s) : Sales_data(s, 0, 0) {}

Sales_data::Sales_data(std::istream &is) : Sales_data() {}

std::ostream &operator<<(std::ostream &os, const Sales_data &item) {
	os << item.isbn() << " " << item.units_sold << " "
		<< item.revenue << " " << item.avg_price();
	return os;
}

std::istream &operator>>(std::istream &is, Sales_data &item) {
	double price = 0;
	is >> item.book_no >> item.units_sold >> price;

	if (is) {
		item.revenue = item.units_sold * price;
	}
	else {
		item = Sales_data();
	}

	return is;
}

Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs) {
	Sales_data sum(lhs);
	sum += rhs;

	return sum;
}

bool operator==(const Sales_data &lhs, const Sales_data &rhs) {
	return lhs.isbn() == rhs.isbn() &&
		lhs.units_sold == rhs.units_sold &&
		lhs.revenue == rhs.revenue;
}

bool operator!=(const Sales_data &lhs, const Sales_data &rhs) {
	return !(lhs == rhs);
}

Sales_data &Sales_data::operator+=(const Sales_data &rhs) {
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;

	return *this;
}