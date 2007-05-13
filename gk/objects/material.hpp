#ifndef OBJECTS_MATERIAL_HPP
#define OBJECTS_MATERIAL_HPP

#include <boost/serialization/utility.hpp>

#include <string>

#include "vertex.hpp"

class material
{
public:
	std::string texture;
	vertex color;

	material();
	material(std::string texture);

	template<class A> 
	void serialize(A& archive, const unsigned int)
	{
		archive & BOOST_SERIALIZATION_NVP(texture);
		archive & BOOST_SERIALIZATION_NVP(color);
	}

	void draw() const;
};

BOOST_CLASS_IMPLEMENTATION(material, boost::serialization::object_serializable);

#endif //OBJECTS_MATERIAL_HPP 