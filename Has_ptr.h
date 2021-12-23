#ifndef HAS_PTR_H
#define HAS_PTR_H

#include <string>
#include <cstddef>

class Has_ptr {
public:
	Has_ptr() : ps(new std::string()), ref_count(new std::size_t(1)) {}
	Has_ptr(const std::string &str) :
		ps(new std::string(str)), ref_count(new std::size_t(1)) {}

	// copy control members
	Has_ptr(const Has_ptr &);
	Has_ptr &operator=(const Has_ptr &);
	~Has_ptr();

private:
	std::string *ps;
	int val = 0;
	std::size_t *ref_count;
};
#endif