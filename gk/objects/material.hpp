#ifndef OBJECTS_MATERIAL_HPP
#define OBJECTS_MATERIAL_HPP

#include <boost/serialization/utility.hpp>

#include "texture.hpp"
#include "vertex.hpp"

class material
{
public:
	texture texture;	
	vertex color;

	template<class A> 
	void serialize(A& archive, const unsigned int)
	{
		archive & BOOST_SERIALIZATION_NVP(texture);
		archive & BOOST_SERIALIZATION_NVP(color);
	}

public:
	material();
	material(vertex color);

	virtual void draw() const;
};

BOOST_CLASS_IMPLEMENTATION(material, boost::serialization::object_serializable);

#endif //OBJECTS_MATERIAL_HPP 