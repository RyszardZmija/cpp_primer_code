#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>

class Person {

	friend std::istream &read(std::istream &, Person &);
	friend std::ostream &print(std::ostream &, const Person &);

public:
	Person() = default;
	Person(const std::string &, const std::string &, const std::string &);

	std::string get_first_name() const { return first_name; }
	std::string get_last_name() const { return last_name; }
	std::string get_address() const { return address; }

private:
	// data members
	std::string first_name;
	std::string last_name;
	std::string address;
};

std::istream &read(std::istream &, Person &);
std::ostream &print(std::ostream &, const Person &);

#endif