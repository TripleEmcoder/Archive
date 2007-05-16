#ifndef OBJECTS_OBJECT_HPP
#define OBJECTS_OBJECT_HPP

#include <boost/shared_ptr.hpp>
#include <boost/serialization/utility.hpp>

#include "map.hpp"
#include "string.hpp"
#include "transformation.hpp"
#include "vertex.hpp"

class material;
class world;

class object
{
public:
	vertex translation;
	vertex rotation;
	std::map<std::string, std::string> bindings;

	template<class A> 
	void serialize(A& archive, const unsigned int)
	{
		archive & BOOST_SERIALIZATION_NVP(translation);
		archive & BOOST_SERIALIZATION_NVP(rotation);
		archive & BOOST_SERIALIZATION_NVP(bindings);
	}

public:
	boost::shared_ptr<transformation> composition;

	virtual void compile(const object* parent);
	virtual void draw() const;

protected:
	const object* parent;
	const world* root;
	virtual const material* bound_material(std::string name) const;
};

BOOST_CLASS_IMPLEMENTATION(object, boost::serialization::object_serializable);

#endif //OBJECTS_OBJECT_HPP
