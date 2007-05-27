#ifndef OBJECTS_WEAPON_HPP
#define OBJECTS_WEAPON_HPP

#include <boost/shared_ptr.hpp>
#include <boost/serialization/utility.hpp>

#include "string.hpp"
#include "object.hpp"

class md3;
class body_wrapper;

class weapon : public object
{
public:
	std::string name;

	template<class A> 
	void serialize(A& archive, const unsigned int version)
	{
		object::serialize(archive, version);
		archive & BOOST_SERIALIZATION_NVP(name);
	}

public:
	virtual void compile(const object& parent);
	virtual void draw(const state& state) const;

private:
	boost::shared_ptr<md3> model;
	boost::shared_ptr<body_wrapper> body;
};

BOOST_CLASS_IMPLEMENTATION(weapon, boost::serialization::object_serializable);

#endif //OBJECTS_WEAPON_HPP 
