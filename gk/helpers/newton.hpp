#ifndef HELPERS_NEWTON_HPP
#define HELPERS_NEWTON_HPP

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

class matrix;
class vertex;

class body_wrapper
{
public:
	body_wrapper(const world_id& world);
	
	void transformation(const matrix& value);
	boost::signal<void(const matrix& matrix)> transformation_changed;

	void mass(float mass, const vertex& inertia);
	void omega(const vertex& value);

private:
	body_id body;
};

#endif //HELPERS_NEWTON_HPP
