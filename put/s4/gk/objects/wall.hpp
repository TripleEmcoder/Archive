#ifndef OBJECTS_WALL_HPP
#define OBJECTS_WALL_HPP

#include <boost/shared_ptr.hpp>
#include <boost/serialization/utility.hpp>

#include "object.hpp"

class box;

class wall : public object
{
public:
	float length;
	float height;

	template<class A> 
	void serialize(A& archive, const unsigned int version)
	{
		object::serialize(archive, version);
		archive & BOOST_SERIALIZATION_NVP(length);
		archive & BOOST_SERIALIZATION_NVP(height);
	}

public:
	virtual void compile(const object& parent);
	virtual void draw(const state& state) const;

	const material& bound_material(std::string name) const;

private:
	boost::shared_ptr<box> _body;
};

BOOST_CLASS_IMPLEMENTATION(wall, boost::serialization::object_serializable);

#endif //OBJECTS_WALL_HPP
