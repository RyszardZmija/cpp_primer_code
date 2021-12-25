#ifndef STR_VEC_H
#define STR_VEC_H

#include <string>
#include <memory>
#include <utility>
#include <cstddef>
#include <initializer_list>

class Str_vec {
public:
	// the allocator member is default initialized
	Str_vec() :
		elements(nullptr), first_free(nullptr), cap(nullptr) {}

	Str_vec(std::initializer_list<std::string> il);

	// copy control
	Str_vec(const Str_vec &);
	Str_vec &operator=(const Str_vec &);
	~Str_vec();

	void push_back(const std::string &);
	
	std::size_t size() const { return first_free - elements; }
	std::size_t capacity() const { return cap - elements; }
	std::string *begin() const { return elements; }
	std::string *end() const { return first_free; }

	void reserve(std::size_t);
	void resize(std::size_t);

private:
	std::allocator<std::string> alloc;
	
	std::string *elements;
	std::string *first_free;
	std::string *cap;
	
	void check_and_alloc() {
		if (cap == first_free) {
			reallocate();
		}
	}

	std::pair<std::string *, std::string *>
		alloc_and_copy(const std::string *, const std::string *);

	void free();
	void reallocate();
};
#endif