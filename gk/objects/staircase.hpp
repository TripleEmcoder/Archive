#ifndef OBJECTS_STAIRCASE_HPP
#define OBJECTS_STAIRCASE_HPP

#include <boost/serialization/utility.hpp>

#include "stair.hpp"

class staircase
{
public:
	stair model;
	unsigned int count;

	template<class A> 
	void serialize(A& archive, const unsigned int)
	{
		archive & BOOST_SERIALIZATION_NVP(model);
		archive & BOOST_SERIALIZATION_NVP(count);
	}

	void draw() const;
};

BOOST_CLASS_IMPLEMENTATION(staircase, boost::serialization::object_serializable);

#endif //OBJECTS_STAIRCASE_HPP 