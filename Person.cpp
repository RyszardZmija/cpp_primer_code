#include "Person.h"

std::istream &read(std::istream &is, Person &p) {

	is >> p.first_name >> p.last_name;
	std::getline(is, p.address);

	return is;
}

std::ostream &print(std::ostream &os, const Person &p) {

	os << p.first_name << " " << p.last_name << " " << p.address;

	return os;
}

Person::Person(const std::string &fn, const std::string &ln, const std::string &addr) :
	first_name(fn), last_name(ln), address(addr) {}