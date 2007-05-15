#ifndef OBJECTS_WALL_HPP
#define OBJECTS_WALL_HPP

#include <boost/serialization/utility.hpp>

#include "vector.hpp"
#include "object.hpp"

class wall : public object
{
public:
	class door
	{
	public:
		float offset;
		float width;
		float height;

		template<class A> 
		void serialize(A& archive, const unsigned int)
		{
			archive & BOOST_SERIALIZATION_NVP(offset);
			archive & BOOST_SERIALIZATION_NVP(width);
			archive & BOOST_SERIALIZATION_NVP(height);
		}

	public:
		door();
		door(float offset, float width, float height);
	};

	float length;
	float height;
	float thickness;
	std::vector<door> doors;

	template<class A> 
	void serialize(A& archive, const unsigned int version)
	{
		object::serialize(archive, version);
		archive & BOOST_SERIALIZATION_NVP(length);
		archive & BOOST_SERIALIZATION_NVP(height);
		archive & BOOST_SERIALIZATION_NVP(thickness);
		archive & BOOST_SERIALIZATION_NVP(doors);
	}

public:
	virtual void draw() const;
	virtual void compile(const object* parent);
};

BOOST_CLASS_IMPLEMENTATION(wall::door, boost::serialization::object_serializable);
BOOST_CLASS_IMPLEMENTATION(wall, boost::serialization::object_serializable);

#endif //OBJECTS_WALL_HPP
