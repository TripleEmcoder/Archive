#ifndef HELPERS_MATERIAL_HPP
#define HELPERS_MATERIAL_HPP

#include <boost/serialization/utility.hpp>

#include "texture.hpp"
#include "vertex.hpp"

class material
{
public:
	texture texture;	
	vertex ambient;
	vertex diffuse;
	vertex specular;
	vertex emission;
	float shininess;

	template<class A> 
	void serialize(A& archive, const unsigned int)
	{
		archive & BOOST_SERIALIZATION_NVP(texture);
		archive & BOOST_SERIALIZATION_NVP(ambient);
		archive & BOOST_SERIALIZATION_NVP(diffuse);
		archive & BOOST_SERIALIZATION_NVP(specular);
		archive & BOOST_SERIALIZATION_NVP(emission);
		archive & BOOST_SERIALIZATION_NVP(shininess);
	}

public:
	material();

	virtual void compile();
	virtual void draw() const;
};

BOOST_CLASS_IMPLEMENTATION(material, boost::serialization::object_serializable);

class material_scope
{
public:
	material_scope(const material& material);
	~material_scope();
};

#endif //HELPERS_MATERIAL_HPP
