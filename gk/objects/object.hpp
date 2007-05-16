#ifndef OBJECTS_OBJECT_HPP
#define OBJECTS_OBJECT_HPP

#include <boost/shared_ptr.hpp>
#include <boost/serialization/utility.hpp>

#include "map.hpp"
#include "string.hpp"
#include "vertex.hpp"

class material;
class world;
class transformation;

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
	virtual void compile(const object& parent);
	virtual void draw() const;

	virtual const object& parent() const;
	virtual const world& root() const;
	virtual const transformation& composition() const;
	virtual const material& bound_material(std::string name) const;

//private:
protected:
	const object* _parent;
	const world* _root;
	boost::shared_ptr<transformation> _composition;
};

BOOST_CLASS_IMPLEMENTATION(object, boost::serialization::object_serializable);

#endif //OBJECTS_OBJECT_HPP
