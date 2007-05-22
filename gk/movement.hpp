#ifndef MOVEMENT_HPP
#define MOVEMENT_HPP

void process_active_keys();

void process_key_down(unsigned char key, int x, int y);
void process_key_up(unsigned char key, int x, int y);
void process_mouse_event(int button, int state, int x, int y);
void process_mouse_motion(int x, int y);

#endif //MOVEMENT_HPP
