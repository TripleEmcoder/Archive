#ifndef OBJECTS_STAIR_HPP
#define OBJECTS_STAIR_HPP

#include <boost/serialization/utility.hpp>

class stair
{
public:
	float width;
	float height;
	float depth;
	float thickness;
	float overhang;

	template<class A> 
	void serialize(A& archive, const unsigned int)
	{
		archive & BOOST_SERIALIZATION_NVP(width);
		archive & BOOST_SERIALIZATION_NVP(height);
		archive & BOOST_SERIALIZATION_NVP(depth);
		archive & BOOST_SERIALIZATION_NVP(thickness);
		archive & BOOST_SERIALIZATION_NVP(overhang);
	}
};

BOOST_CLASS_IMPLEMENTATION(stair, boost::serialization::object_serializable);

#endif //OBJECTS_STAIR_HPP 