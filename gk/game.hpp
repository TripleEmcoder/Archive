#ifndef GAME_HPP
#define GAME_HPP

#include <string>
#include <vector>

#include <boost/shared_ptr.hpp>

class vertex;

#include "Character.hpp"
#include "level.hpp"
#include "Camera.hpp"
#include "projector.hpp"
#include "compass.hpp"
#include "crosshair.hpp"
#include "fps_meter.hpp"
#include "state.hpp"

class game
{
public:
	game(std::string name);
	~game();

	void process_mouse_event(int button, int state, int x, int y);
	void process_mouse_motion(int x, int y);

	void process_monostable_keys(const std::vector<bool>& keys);
	void process_bistable_keys(const std::vector<bool>& keys);

	void process_physics();

	void update_viewport(int width, int height);

	void draw_level(const vertex& offset, float x, float y);
	void draw_projector();

private:
	level level;
	boost::shared_ptr<Character> character;
	Camera camera;
	projector projector;
	fps_meter fps_meter;
	crosshair crosshair;
	compass compass;
	state state;

	void load_level(std::string name);
	void setup_widgets();
	void setup_lights();
	void setup_shaders();
};

#endif //GAME_HPP
