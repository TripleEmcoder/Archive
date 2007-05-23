#ifndef HELPERS_ID_HPP
#define HELPERS_ID_HPP

#include <boost/utility.hpp>

//(de)alokacja identyfikatora tekstury
class texture_id : private boost::noncopyable
{
public:
	texture_id();
	~texture_id();
	operator unsigned int() const;

private:
	unsigned int texture;
};

//(de)alokacja identyfikatora listy
class list_id : private boost::noncopyable
{
public:
	list_id();
	~list_id();
	operator unsigned int() const;

private:
	unsigned int list;
};

struct NewtonWorld;

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

struct NewtonBody;

//(de)alokacja ciala silnika fizycznego 
class body_id : private boost::noncopyable
{
public:
	body_id(world_id& world);
	~body_id();
	operator NewtonBody*() const;

private:
	world_id& world;
	NewtonBody* body;
};

#endif //HELPERS_ID_HPP
