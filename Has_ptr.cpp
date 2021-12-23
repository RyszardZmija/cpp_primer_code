#include "Has_ptr.h"

// definitions default and two parameter constructors
Has_ptr::Has_ptr() :
	ps(new std::string()), pval(new int()) {}

Has_ptr::Has_ptr(const std::string &str, int val) :
	ps(new std::string(str)), pval(new int(val)) {}

// definitions of copy control members
Has_ptr::~Has_ptr() {
	delete ps;
	delete pval;
}

Has_ptr::Has_ptr(const Has_ptr &orig) :
	ps(new std::string(*orig.ps)), pval(new int(*orig.pval)) {}

// handles self-assignment without an explicit check
Has_ptr &Has_ptr::operator=(const Has_ptr &rhs) {
	std::string ns(*rhs.ps);
	int nval = *rhs.pval;

	delete ps;
	delete pval;

	ps = new std::string(ns);
	pval = new int(nval);

	return *this;
}