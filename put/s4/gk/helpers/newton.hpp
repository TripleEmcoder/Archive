#ifndef HELPERS_world_HPP
#define HELPERS_world_HPP

#include <boost/signal.hpp>
#include <boost/utility.hpp>

#include <Newton.h>

//(de)alokacja swiata silnika fizycznego 
class world_id : private boost::noncopyable
{
public:
	world_id();
	~world_id();
	operator NewtonWorld*() const;

private:
	NewtonWorld* world;
};

//(de)alokacja ciala silnika fizycznego 
class body_id : private boost::noncopyable
{
public:
	body_id(const world_id& world);
	~body_id();
	operator NewtonBody*() const;

private:
	NewtonBody* body;
};

class vertex;
class body_wrapper;

class world_wrapper
{
public:
	world_wrapper();

	const world_id& id() const;

	void size(const vertex& lower_bound, const vertex& upper_bound);

private:
	world_id world;

	static int contact_started_callback(const NewtonMaterial* material, const NewtonBody* body0, const NewtonBody* body1);
	static int contact_running_callback(const NewtonMaterial* material, const NewtonContact* contact);
	static void contact_stopped_callback(const NewtonMaterial* material);
	body_wrapper* body0;
	body_wrapper* body1;
};

class matrix;

class body_wrapper
{
public:
	body_wrapper(const world_wrapper& world, std::string tag);

	const body_id& id() const;
	
	void transformation(const matrix& value);
	boost::signal<void(const matrix& value)> transformation_changed;

	boost::signal<void()> simulation_starting;

	boost::signal<void(const body_wrapper& party)> contact_started;
	boost::signal<void(const body_wrapper& party)> contact_running;
	boost::signal<void(const body_wrapper& party)> contact_stopped;

	void mass(float mass, const vertex& inertia);
	void omega(const vertex& value);

private:
	body_id body;
	std::string tag;

	static void transformation_changed_callback(const NewtonBody* body, const float* matrix);
	static void simulation_starting_callback(const NewtonBody* body);

	void contact_started_debug(const body_wrapper& party) const;
	void contact_running_debug(const body_wrapper& party) const;
	void contact_stopped_debug(const body_wrapper& party) const;
};

#endif //HELPERS_world_HPP
