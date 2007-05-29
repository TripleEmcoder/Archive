#ifndef INPUT_HPP
#define INPUT_HPP

void process_monostables();
void process_bistables();

void process_key_down(unsigned char key, int x, int y);
void process_key_up(unsigned char key, int x, int y);
void process_mouse_event(int button, int state, int x, int y);
void process_mouse_motion(int x, int y);

#endif //INPUT_HPP
