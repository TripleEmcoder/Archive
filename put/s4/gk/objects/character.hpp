#ifndef OBJECTS_CHARACTER_HPP
#define OBJECTS_CHARACTER_HPP

#include <boost/shared_ptr.hpp>
#include <boost/serialization/utility.hpp>

#include "object.hpp"

class box;
class sphere;

class character : public object
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
	virtual void draw(const state& state) const;

protected:
	boost::shared_ptr<box> _body;
	boost::shared_ptr<sphere> _head;
};

BOOST_CLASS_IMPLEMENTATION(character, boost::serialization::object_serializable);

#endif //OBJECTS_CHARACTER_HPP 
