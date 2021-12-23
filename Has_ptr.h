#ifndef HAS_PTR_H
#define HAS_PTR_H

#include <string>

class Has_ptr {
public:
	Has_ptr();
	Has_ptr(const std::string &, int);

	// copy control members
	Has_ptr(const Has_ptr &); // copy constructor
	Has_ptr &operator=(const Has_ptr &); // copy assignment operator
	~Has_ptr(); // destructor

	std::string get_str() const { return *ps; }
	int get_val() const { return *pval; }

private:
	std::string *ps;
	int *pval;
};
#endif