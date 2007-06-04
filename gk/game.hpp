#ifndef GAME_HPP
#define GAME_HPP

#include <string>
#include <vector>

#include <boost/shared_ptr.hpp>

#include "Character.hpp"
#include "level.hpp"
#include "Camera.hpp"
#include "projector.hpp"
#include "crosshair.hpp"
#include "compass.hpp"
#include "fps_meter.hpp"
#include "about.hpp"
#include "state.hpp"
#include "vertex.hpp"


class game
{
public:
	static void set_respawn_point(const vertex& position);
	static void set_respawn_angle(float angle);

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
	static vertex respawn_point;
	static float respawn_angle;

	level level;
	boost::shared_ptr<Character> character;
	Camera camera;
	projector projector;
	crosshair crosshair;
	compass compass;
	fps_meter fps_meter;
	about about;
	state state;
	
	void load_level(std::string name);
	void setup_character();
	void setup_widgets();
	void setup_lights();
	void setup_shaders();
};

#endif //GAME_HPP
