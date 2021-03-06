#ifndef HELPERS_TEXTURE_HPP
#define HELPERS_TEXTURE_HPP

#include <boost/shared_ptr.hpp>
#include <boost/serialization/utility.hpp>
#include <boost/tuple/tuple.hpp>

#include "string.hpp"

class state;
class texture_wrapper;

class texture
{
public:
	std::string name;
	float width;
	float height;

	template<class A> 
	void serialize(A& archive, const unsigned int)
	{
		archive & BOOST_SERIALIZATION_NVP(name);
		archive & BOOST_SERIALIZATION_NVP(width);
		archive & BOOST_SERIALIZATION_NVP(height);
	}

public:
	texture();
	texture(std::string name, float width = 0, float height = 0);

	virtual void compile();
	virtual void draw() const;
	
	boost::tuple<float, float> ratio(float width, float height) const;

private:
	boost::shared_ptr<texture_wrapper> wrapper;
};

BOOST_CLASS_IMPLEMENTATION(texture, boost::serialization::object_serializable);

#endif //HELPERS_TEXTURE_HPP
