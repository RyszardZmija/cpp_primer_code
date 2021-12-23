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

Sales_data &Sales_data::combine(const Sales_data &rhs) {

	units_sold += rhs.units_sold;
	revenue += rhs.revenue;

	return *this;
}

std::istream &read(std::istream &is, Sales_data &item) {

	double price = 0.0;
	is >> item.book_no >> item.units_sold >> price;
	item.revenue = item.units_sold * price;

	return is;
}

std::ostream &print(std::ostream &os, const Sales_data &item) {

	os << item.isbn() << " " << item.units_sold << " "
		<< item.revenue << " " << item.avg_price();

	return os;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs) {

	Sales_data sum(lhs);
	sum.combine(rhs);

	return sum;
}

Sales_data::Sales_data(const std::string &s, unsigned cnt, double price) :
	book_no(s), units_sold(cnt), revenue(cnt * price) {}

Sales_data::Sales_data() : Sales_data("", 0, 0) {}

Sales_data::Sales_data(const std::string &s) : Sales_data(s, 0, 0) {}

Sales_data::Sales_data(std::istream &is) : Sales_data() {}