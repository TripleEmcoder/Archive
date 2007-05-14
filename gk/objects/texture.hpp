#ifndef OBJECTS_TEXTURE_HPP
#define OBJECTS_TEXTURE_HPP

#include <boost/serialization/utility.hpp>
#include <boost/tuple/tuple.hpp>

#include "../traits/string.hpp"

class texture
{
public:
	std::string image;
	float width;
	float height;

	template<class A> 
	void serialize(A& archive, const unsigned int)
	{
		archive & BOOST_SERIALIZATION_NVP(image);
		archive & BOOST_SERIALIZATION_NVP(width);
		archive & BOOST_SERIALIZATION_NVP(height);
	}

public:
	texture();
	texture(std::string image, float width, float height);

	virtual void draw() const;
	virtual boost::tuple<float, float> ratio(float width, float height) const;
};

BOOST_CLASS_IMPLEMENTATION(texture, boost::serialization::object_serializable);

#endif //OBJECTS_TEXTURE_HPP 