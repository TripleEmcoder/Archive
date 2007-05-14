#ifndef OBJECTS_STAIRCASE_HPP
#define OBJECTS_STAIRCASE_HPP

#include <boost/serialization/utility.hpp>

#include "object.hpp"
#include "stair.hpp"

class staircase : public object
{
public:
	stair model;
	int count;

	template<class A> 
	void serialize(A& archive, const unsigned int version)
	{
		object::serialize(archive, version);
		archive & BOOST_SERIALIZATION_NVP(model);
		archive & BOOST_SERIALIZATION_NVP(count);
	}

public:
	virtual void draw() const;
	virtual void compile(const object* parent);
};

BOOST_CLASS_IMPLEMENTATION(staircase, boost::serialization::object_serializable);

#endif //OBJECTS_STAIRCASE_HPP 