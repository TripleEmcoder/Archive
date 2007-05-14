#ifndef OBJECTS_OBJECT_HPP
#define OBJECTS_OBJECT_HPP

#include <boost/serialization/utility.hpp>

#include "../traits/string.hpp"
#include "../traits/map.hpp"

#include "vertex.hpp"

class material;
class world;

class object
{
public:
	vertex position;
	vertex rotation;
	std::map<std::string, std::string> bindings;

	template<class A> 
	void serialize(A& archive, const unsigned int)
	{
		archive & BOOST_SERIALIZATION_NVP(position);
		archive & BOOST_SERIALIZATION_NVP(rotation);
		archive & BOOST_SERIALIZATION_NVP(bindings);
	}

public:
	object();
	object(vertex position);

	virtual void draw() const;
	virtual void compile(const object* parent);

protected:
	const object* parent;
	const world* root;
	virtual const material* resolve(std::string name) const;
};

BOOST_CLASS_IMPLEMENTATION(object, boost::serialization::object_serializable);

#endif //OBJECTS_OBJECT_HPP 