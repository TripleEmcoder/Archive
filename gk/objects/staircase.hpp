#ifndef OBJECTS_STAIRCASE_HPP
#define OBJECTS_STAIRCASE_HPP

#include <boost/serialization/utility.hpp>

#include "object.hpp"

class staircase : public object
{
public:
	class stair
	{
	public:
		float width;
		float height;
		float depth;
		float thickness;
		float overhang;

		template<class A> 
		void serialize(A& archive, const unsigned int)
		{
			archive & BOOST_SERIALIZATION_NVP(width);
			archive & BOOST_SERIALIZATION_NVP(height);
			archive & BOOST_SERIALIZATION_NVP(depth);
			archive & BOOST_SERIALIZATION_NVP(thickness);
			archive & BOOST_SERIALIZATION_NVP(overhang);
		}
	};

	stair model;
	int count;

	template<class A> 
	void serialize(A& archive, const unsigned int version)
	{
		object::serialize(archive, version);
		archive & BOOST_SERIALIZATION_NVP(model);
		archive & BOOST_SERIALIZATION_NVP(count);
	}

public:
	virtual void compile(const object* parent);
	virtual void draw() const;
};

BOOST_CLASS_IMPLEMENTATION(staircase::stair, boost::serialization::object_serializable);
BOOST_CLASS_IMPLEMENTATION(staircase, boost::serialization::object_serializable);

#endif //OBJECTS_STAIRCASE_HPP 
