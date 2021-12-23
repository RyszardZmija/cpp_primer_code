#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <string>
#include <iostream>

class Sales_data {
	
	friend std::istream &read(std::istream &, Sales_data &);
	friend std::ostream &print(std::ostream &, const Sales_data &);
	friend Sales_data add(const Sales_data &, const Sales_data &);

public: // interface
	// special member functions that construct objects of this
	// class
	Sales_data(const std::string &, unsigned, double);
	Sales_data();
	explicit Sales_data(const std::string &);
	explicit Sales_data(std::istream &);

	// function members (operations)
	std::string isbn() const { return book_no; }
	
	Sales_data &combine(const Sales_data &);
	
private: // implementation
	double avg_price() const;

	// data members
	std::string book_no;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

Sales_data add(const Sales_data &, const Sales_data &);
std::istream &read(std::istream &, Sales_data &);
std::ostream &print(std::ostream &, const Sales_data &);

#endif