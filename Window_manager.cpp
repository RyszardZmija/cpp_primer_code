#include "Screen.h"

// this member function is specified as friend member function
// by Screen class, hence it can access the private members
// of Screen to reset a Screen to its default state
void Window_manager::clear(screen_index i) {
	Screen &s = screens[i];
	s.contents = std::string(s.height * s.width, ' ');
}