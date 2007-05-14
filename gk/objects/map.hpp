#ifndef OBJECTS_MAP_HPP
#define OBJECTS_MAP_HPP

#include <string>
#include <istream>
#include <ostream>

#include <boost/serialization/utility.hpp>

#include <Newton.h>

#include "group.hpp"

class map : public group
{
public:
	template<class A> 
	void serialize(A& archive, const unsigned int version)
	{
		group::serialize(archive, version);
	}

	void draw() const;
	void build(NewtonWorld* world) const;
};

BOOST_CLASS_IMPLEMENTATION(map, boost::serialization::object_serializable);

std::istream& operator>> (std::istream& is, map& m);
std::ostream& operator<< (std::ostream& os, const map& m);

#endif //OBJECTS_MAP_HPP
