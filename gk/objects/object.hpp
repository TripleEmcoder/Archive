#ifndef OBJECTS_OBJECT_HPP
#define OBJECTS_OBJECT_HPP

#include <boost/serialization/utility.hpp>

#include "../traits/map.hpp"

#include "vertex.hpp"
#include "material.hpp"

class object
{
public:
	vertex position;
	vertex rotation;
	std::map<std::string, material> materials;

	object();
	object(vertex position);

	template<class A> 
	void serialize(A& archive, const unsigned int)
	{
		archive & BOOST_SERIALIZATION_NVP(position);
		archive & BOOST_SERIALIZATION_NVP(rotation);
		archive & BOOST_SERIALIZATION_NVP(materials);
	}

	void draw() const;
};

BOOST_CLASS_IMPLEMENTATION(object, boost::serialization::object_serializable);

#endif //OBJECTS_OBJECT_HPP 