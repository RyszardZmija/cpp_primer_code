#include "Has_ptr.h"

Has_ptr::Has_ptr(const Has_ptr &orig) :
	ps(orig.ps), val(orig.val), ref_count(orig.ref_count) {

	++ *ref_count;
}

Has_ptr::~Has_ptr() {
	if (-- *ref_count == 0) {
		delete ps;
		delete ref_count;
	}
}

Has_ptr &Has_ptr::operator=(const Has_ptr &rhs) {
	++ *rhs.ref_count;
	if (-- * ref_count == 0) {
		delete ps;
		delete ref_count;
	}

	ps = rhs.ps;
	val = rhs.val;
	ref_count = rhs.ref_count;

	return *this;
}