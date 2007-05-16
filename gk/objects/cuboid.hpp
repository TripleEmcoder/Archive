#ifndef OBJECTS_CUBOID_HPP
#define OBJECTS_CUBOID_HPP

#include <boost/serialization/utility.hpp>

#include "object.hpp"

class cuboid : public object
{
public:
	vertex size;

	template<class A> 
	void serialize(A& archive, const unsigned int version)
	{
		object::serialize(archive, version);
		archive & BOOST_SERIALIZATION_NVP(size);
	}

public:
	virtual void compile(const object* parent);
	virtual void draw() const;
};

BOOST_CLASS_IMPLEMENTATION(cuboid, boost::serialization::object_serializable);

#endif //OBJECTS_CUBOID_HPP 
