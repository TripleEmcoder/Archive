#ifndef HELPERS_MATERIAL_HPP
#define HELPERS_MATERIAL_HPP

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
	material(const vertex& color);

	virtual void compile();
	virtual void draw() const;
};

BOOST_CLASS_IMPLEMENTATION(material, boost::serialization::object_serializable);

#endif //HELPERS_MATERIAL_HPP
