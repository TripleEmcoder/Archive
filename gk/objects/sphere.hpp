#ifndef OBJECTS_SPHERE_HPP
#define OBJECTS_SPHERE_HPP

#include <boost/serialization/utility.hpp>

#include "object.hpp"

class sphere : public object
{
public:
	float radius;

	template<class A> 
	void serialize(A& archive, const unsigned int version)
	{
		object::serialize(archive, version);
		archive & BOOST_SERIALIZATION_NVP(radius);
	}

public:
	virtual void compile(const object& parent);
	virtual void draw() const;
};

BOOST_CLASS_IMPLEMENTATION(sphere, boost::serialization::object_serializable);

#endif //OBJECTS_SPHERE_HPP 
