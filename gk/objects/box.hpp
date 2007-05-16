#ifndef OBJECTS_BOX_HPP
#define OBJECTS_BOX_HPP

#include <boost/serialization/utility.hpp>

#include "object.hpp"
#include "body.hpp"

class box : public body, public object
{
public:
	vertex size;

	template<class A> 
	void serialize(A& archive, const unsigned int version)
	{
		object::serialize(archive, version);
		archive & BOOST_SERIALIZATION_NVP(size);
	}

public:
	virtual void compile(const object& parent);
	virtual void draw() const;

	virtual const world& root() const;
	virtual const transformation& composition() const;
};

BOOST_CLASS_IMPLEMENTATION(box, boost::serialization::object_serializable);

#endif //OBJECTS_BOX_HPP 
