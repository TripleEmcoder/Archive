#ifndef MATERIAL_HPP
#define MATERIAL_HPP

#include <boost/serialization/utility.hpp>

#include <string>

class material
{
public:
	std::string texture;

	material(std::string texture);

	template<class A> 
	void serialize(A& archive, const unsigned int)
	{
		archive & BOOST_SERIALIZATION_NVP(texture);
	}

	void draw() const;
};

BOOST_CLASS_IMPLEMENTATION(material, boost::serialization::object_serializable);

#endif //MATERIAL_HPP 