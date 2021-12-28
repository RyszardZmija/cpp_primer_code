#include "String.h"

#include <iostream>
#include <algorithm>

String::String() :
	elements(nullptr), first_free(nullptr), cap(nullptr) {}

String::String(const char *carr) :
	String() {

	while (*carr) {
		push_back(*carr++);
	}
}

void String::push_back(char ch) {
	check_and_alloc();
	alloc.construct(first_free++, ch);
}

std::pair<char *, char *>
String::alloc_and_copy(const char *b, const char *e) {

	auto new_data = alloc.allocate(e - b);
	auto one_past_last = std::uninitialized_copy(b, e, new_data);

	return std::make_pair(new_data, one_past_last);
}

void String::free() {
	if (elements) {
		for (auto p = first_free; p != elements;) {
			alloc.destroy(--p);
		}
		alloc.deallocate(elements, cap - elements);
	}
}

void String::reallocate() {
	auto new_capacity = size() ? 2 * size() : 1;
	auto new_data = alloc.allocate(new_capacity);

	auto dest = new_data;
	auto elem = elements;

	for (std::size_t i = 0; i != size(); ++i) {
		alloc.construct(dest++, std::move(*elem++));
	}

	free();

	elements = new_data;
	first_free = dest;
	cap = elements + new_capacity;
}

String::String(const String &s) {
	auto new_data = alloc_and_copy(s.begin(), s.end());
	elements = new_data.first;
	first_free = cap = new_data.second;
}

String::~String() {
	free();
}

String &String::operator=(const String &s) {
	auto new_data = alloc_and_copy(s.begin(), s.end());
	free();
	elements = new_data.first;
	first_free = cap = new_data.second;

	return *this;
}

std::ostream &operator<<(std::ostream &os, const String &s) {
	std::for_each(s.begin(), s.end(), [&](char ch) {os << ch; });

	return os;
}

String operator+(const String &lhs, const String &rhs) {
	String sum(lhs);
	sum += rhs;
	return sum;
}

bool operator==(const String &lhs, const String &rhs) {
	if (lhs.size() != rhs.size()) {
		return false;
	}
	else {
		auto it1 = lhs.begin(), it2 = rhs.begin();
		for (String::size_type i = 0; i != lhs.size(); ++i) {
			if (*(it1 + i) != *(it2 + i)) {
				return false;
			}
		}

		return true;
	}
}

bool operator!=(const String &lhs, const String &rhs) {
	return !(lhs == rhs);
}

bool operator<(const String &lhs, const String &rhs) {
	auto smaller_size = lhs.size() < rhs.size() ? lhs.size() : rhs.size();

	auto it1 = lhs.begin(), it2 = rhs.begin();
	for (String::size_type i = 0; i != smaller_size; ++i) {
		if (*it1 < *it2) {
			return true;
		}
		else if (*it1 > *it2) {
			return false;
		}

		++it1;
		++it2;
	}

	return lhs.size() < rhs.size();
}

char &String::operator[](size_type n) { return elements[n]; }

const char &String::operator[](size_type n) const
{ return elements[n]; }

String &String::operator+=(const String &s) {
	for (auto x : s) {
		push_back(x);
	}

	return *this;
}