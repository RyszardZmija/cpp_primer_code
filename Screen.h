#ifndef SCREEN_H
#define SCREEN_H

#include <string>
#include <iostream>
#include "Window_manager.h"

class Screen {

	friend void Window_manager::clear(screen_index);

public:
	using pos = std::string::size_type;

	Screen() = default;
	Screen(pos ht, pos wd) : height(ht), width(wd),
		contents(ht * wd, ' ') {}
	Screen(pos ht, pos wd, char c) :
		height(ht), width(wd), contents(ht * wd, c) {}

	char get() const;
	char get(pos, pos) const;
	Screen &move(pos, pos);
	Screen &set(char);
	Screen &set(pos, pos, char);
	Screen &display(std::ostream &);
	const Screen &display(std::ostream &) const;

private:
	pos cursor = 0;
	pos height = 0;
	pos width = 0;
	std::string contents;

	void do_display(std::ostream &) const;
};


inline char Screen::get() const {
	return contents[cursor];
}

inline char Screen::get(pos r, pos c) const {
	return contents[r * width + c];
}

inline Screen &Screen::move(pos r, pos c) {
	cursor = r * width + c;

	return *this;
}

inline Screen &Screen::set(char c) {
	contents[cursor] = c;

	return *this;
}

inline Screen &Screen::set(pos r, pos col, char c) {
	contents[r * width + col] = c;

	return *this;
}
#endif