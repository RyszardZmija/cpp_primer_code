#ifndef SMALL_INT_H
#define SMALL_INT_H

#include <cstddef>
#include <stdexcept>

class Small_int {
public:
	Small_int(int i = 0) :
		val(i) {

		if (i < 0 || i > 255) {
			throw std::out_of_range("Bad Small_int value");
		}
	}

	operator int() const { return val; }
	explicit operator bool() const { return val; }

private:
	std::size_t val;
};
#endif