#ifndef READ_STRING_H
#define READ_STRING_H

#include <iostream>

class Read_string {
public:
	Read_string(std::istream &is = std::cin) :
		is(is) {}

	std::string operator()() const {
		std::string s;
		is >> s;

		return s;
	}

private:
	std::istream &is;
};
#endif