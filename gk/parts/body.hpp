#ifndef OBJECTS_BODY_HPP
#define OBJECTS_BODY_HPP

#include <boost/shared_ptr.hpp>
#include <boost/serialization/utility.hpp>

#include "engine.hpp"

class object;
class world;
class matrix;

class body
{
public:
	float mass;

	template<class A> 
	void serialize(A& archive, const unsigned int version)
	{
		archive & BOOST_SERIALIZATION_NVP(mass);
	}

public:
	virtual void compile();
	virtual void draw() const;

	virtual const NewtonBody* newton() const;
	virtual const world& root() const = 0;
	virtual const matrix& composition() const = 0;

private:
	//boost::shared_ptr<NewtonBody> _newton;
	NewtonBody* _newton;
};

BOOST_CLASS_IMPLEMENTATION(body, boost::serialization::object_serializable);

#endif //OBJECTS_BODY_HPP 
