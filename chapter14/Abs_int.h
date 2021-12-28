#ifndef ABS_INT_H
#define ABS_INT_H

struct Abs_int {
	int operator()(int val) const {
		return val < 0 ? -val : val;
	}
};
#endif