#ifndef STR_VEC_H
#define STR_VEC_H

#include <string>
#include <memory>
#include <utility>
#include <cstddef>
#include <initializer_list>

class Str_vec {

	friend bool operator==(const Str_vec &, const Str_vec &);
	friend bool operator<(const Str_vec &, const Str_vec &);

public:
	// the allocator member is default initialized
	Str_vec() :
		elements(nullptr), first_free(nullptr), cap(nullptr) {}

	Str_vec(std::initializer_list<std::string> il);

	// copy control
	Str_vec(const Str_vec &);
	Str_vec &operator=(const Str_vec &);
	~Str_vec();

	// mark as not throwing exceptions so it can be safely
	// used by various classess e.g. vector template won't use
	// move constructor during reallocation unless it's sure it
	// doesn't throw any exceptions (because of the guarantees it
	// provides)
	Str_vec(Str_vec &&) noexcept;
	Str_vec &operator=(Str_vec &&) noexcept;

	void push_back(const std::string &);
	void push_back(std::string &&);

	std::size_t size() const { return first_free - elements; }
	std::size_t capacity() const { return cap - elements; }
	std::string *begin() const { return elements; }
	std::string *end() const { return first_free; }

	void reserve(std::size_t);
	void resize(std::size_t);

	Str_vec &operator=(std::initializer_list<std::string>);
	std::string &operator[](std::size_t);
	const std::string &operator[](std::size_t) const;

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

bool operator==(const Str_vec &, const Str_vec &);
bool operator!=(const Str_vec &, const Str_vec &);
bool operator<(const Str_vec &, const Str_vec &);

#endif