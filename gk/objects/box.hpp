#ifndef OBJECTS_BOX_HPP
#define OBJECTS_BOX_HPP

#include <boost/serialization/utility.hpp>

#include "object.hpp"
#include "body.hpp"
#include "id.hpp"

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

private:
	list_id list;

	void draw_faces() const;
	void draw_left_face() const;
	void draw_right_face() const;
	void draw_bottom_face() const;
	void draw_top_face() const;
	void draw_front_face() const;
	void draw_back_face() const;
};

BOOST_CLASS_IMPLEMENTATION(box, boost::serialization::object_serializable);

#endif //OBJECTS_BOX_HPP 
