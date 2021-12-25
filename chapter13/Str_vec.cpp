#include "Str_vec.h"

#include <algorithm>

void Str_vec::push_back(const std::string &s) {
	check_and_alloc();
	alloc.construct(first_free++, s);
}

std::pair<std::string *, std::string *>
Str_vec::alloc_and_copy(const std::string *b, const std::string *e) {
	// allocate space to hold as many elements as are in the range
	auto data = alloc.allocate(e - b);

	// initialize and return a pair of constructed from data and the value
	// returned by uninitialized_copy
	return { data, std::uninitialized_copy(b, e, data) };
}

void Str_vec::free() {
	if (elements) {
		std::for_each(begin(), end(), [=](std::string &s) { alloc.destroy(&s); });
		alloc.deallocate(elements, cap - elements);
	}
}

Str_vec::Str_vec(const Str_vec &s) {
	auto new_data = alloc_and_copy(s.begin(), s.end());
	elements = new_data.first;
	first_free = cap = new_data.second;
}

Str_vec::~Str_vec() {
	free();
}

Str_vec &Str_vec::operator=(const Str_vec &rhs) {
	auto new_data = alloc_and_copy(rhs.begin(), rhs.end());
	free();
	elements = new_data.first;
	first_free = cap = new_data.second;

	return *this;
}

void Str_vec::reallocate() {
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

void Str_vec::reserve(std::size_t sz) {
	if (sz > capacity()) {
		auto new_data = alloc.allocate(sz);

		auto dest = new_data;
		auto elem = elements;

		for (std::size_t i = 0; i != size(); ++i) {
			alloc.construct(dest++, std::move(*elem++));
		}

		free();

		elements = new_data;
		first_free = dest;
		cap = elements + sz;
	}
}

void Str_vec::resize(std::size_t sz) {
	if (size() > sz) {
		first_free -= size() - sz;
	}
	else if (size() < sz) {
		while (size() != sz) {
			push_back(std::string());
		}
	}
}

Str_vec::Str_vec(std::initializer_list<std::string> il) :
	Str_vec() {

	for (auto it = il.begin(); it != il.end(); ++it) {
		push_back(*it);
	}
}