#ifndef PRINT_STRING_H
#define PRINT_STRING_H

#include <iostream>
#include <string>

class Print_string {
public:
	Print_string(std::ostream &os = std::cout, char sep = ' ') :
		os(os), sep(sep) {}

	void operator()(const std::string &s) const {
		os << s << sep;
	}

private:
	std::ostream &os; // stream on which to write
	char sep;
};
#endif