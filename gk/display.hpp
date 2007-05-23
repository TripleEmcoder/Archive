#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include <string>

bool setup_window(std::string title, int x, int y, int width, int height);
void cleanup_window();

bool setup_fullscreen(int width, int height, int depth, int frequency);
void cleanup_fullscreen();

void reshape_window(int w, int height);

#endif //DISPLAY_HPP
