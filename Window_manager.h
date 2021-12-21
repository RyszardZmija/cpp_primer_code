#ifndef WINDOW_MANAGER_H
#define WINDOW_MANAGER_H

#include <vector>
#include <string>

class Screen;

class Window_manager {
public:
	using screen_index = std::vector<Screen>::size_type;

	void clear(screen_index);
private:
	std::vector<Screen> screens;
};

#endif