#ifndef OBJECTS_CEILING_HPP
#define OBJECTS_CEILING_HPP

#include <boost/shared_ptr.hpp>
#include <boost/serialization/utility.hpp>

#include "object.hpp"

class cuboid;

class ceiling : public object
{
public:
	float width;
	float depth;

	template<class A> 
	void serialize(A& archive, const unsigned int version)
	{
		object::serialize(archive, version);
		archive & BOOST_SERIALIZATION_NVP(width);
		archive & BOOST_SERIALIZATION_NVP(depth);
	}

public:
	boost::shared_ptr<cuboid> body;

	virtual void compile(const object* parent);
	virtual void draw() const;

	const material* bound_material(std::string name) const;
};

BOOST_CLASS_IMPLEMENTATION(ceiling, boost::serialization::object_serializable);

#endif //OBJECTS_CEILING_HPP 
