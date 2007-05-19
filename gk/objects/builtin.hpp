#ifndef OBJECTS_BUILTIN_HPP
#define OBJECTS_BUILTIN_HPP

#include <boost/serialization/utility.hpp>

#include "string.hpp"
#include "object.hpp"

class builtin : public object
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
	virtual void draw() const;
};

BOOST_CLASS_IMPLEMENTATION(builtin, boost::serialization::object_serializable);

#endif //OBJECTS_BUILTIN_HPP 
