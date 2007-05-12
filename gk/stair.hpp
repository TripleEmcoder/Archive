#ifndef STAIR_HPP
#define STAIR_HPP

#include <boost/serialization/utility.hpp>

#include "vertex.hpp"

class stair
{
public:
	vertex start;
	double width;
	double height;
	double depth;
	double thickness;
	double overhang;

	template<class A> 
	void serialize(A& archive, const unsigned int)
	{
		archive & BOOST_SERIALIZATION_NVP(start);
		archive & BOOST_SERIALIZATION_NVP(width);
		archive & BOOST_SERIALIZATION_NVP(height);
		archive & BOOST_SERIALIZATION_NVP(depth);
		archive & BOOST_SERIALIZATION_NVP(thickness);
		archive & BOOST_SERIALIZATION_NVP(overhang);
	}

	void draw();
};

BOOST_CLASS_IMPLEMENTATION(stair, boost::serialization::object_serializable);

#endif //STAIR_HPP 