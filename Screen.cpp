#include "Screen.h"

#include <iostream>
#include <string>

void Screen::do_display(std::ostream &os) const {
	os << contents;
}

Screen &Screen::display(std::ostream &os) {
	do_display(os);

	return *this;
}

const Screen &Screen::display(std::ostream &os) const {
	do_display(os);

	return *this;
}