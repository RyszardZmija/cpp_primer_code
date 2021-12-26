#ifndef STRING_H
#define STRING_H

#include <memory>
#include <cstddef>
#include <utility>

class String {
public:
	using size_type = std::size_t;
	
	String();
	String(const char *);

	String(const String &);
	String &operator=(const String &);
	~String();

	void push_back(char);

	size_type size() const { return first_free - elements; }
	size_type capacity() const { return cap - elements; }
	char *begin() const { return elements; }
	char *end() const { return first_free; }

private:
	std::allocator<char> alloc;

	char *elements;
	char *first_free;
	char *cap;

	void check_and_alloc() {
		if (first_free == cap) {
			reallocate();
		}
	}

	std::pair<char *, char *> alloc_and_copy(const char *, const char *);
	void free();
	void reallocate();
};
#endif