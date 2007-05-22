#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include <string>

int setup_window(std::string title, int x, int y, int width, int height);
void setup_fullscreen(int width, int height, int depth, int frequency);
void reshape_window(int w, int height);

#endif //DISPLAY_HPP
