#ifndef OBJECTS_BOX_HPP
#define OBJECTS_BOX_HPP

#include <boost/serialization/utility.hpp>

#include "object.hpp"
#include "vertex.hpp"

class list_wrapper;
class body_wrapper;

//klasa reprezentujaca prostopadloscian
class box : public object
{
public:
	//rozmiary prostopadloscianu
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

private:
	boost::shared_ptr<list_wrapper> _list;
	boost::shared_ptr<body_wrapper> _body;

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
