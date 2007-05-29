#ifndef GAME_HPP
#define GAME_HPP

#include <string>
#include <vector>

#include <boost/shared_ptr.hpp>

class display_wrapper;
class vertex;
class Camera;
class Character;
class level;
class projector;
class fps_meter;
class crosshair;
class compass;

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

	void draw_level(const vertex& offset, float x, float y) const;
	void draw_projector() const;

private:
	boost::shared_ptr<level> level;
	boost::shared_ptr<Camera> camera;
	boost::shared_ptr<Character> character;
	boost::shared_ptr<projector> projector;
	boost::shared_ptr<fps_meter> fps_meter;
	boost::shared_ptr<crosshair> crosshair;
	boost::shared_ptr<compass> compass;

	void load_level(std::string name);
	void setup_widgets();
	void setup_lights();
	void setup_shaders();
};

#endif //GAME_HPP
