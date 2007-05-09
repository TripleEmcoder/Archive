#ifndef MAP_HPP
#define MAP_HPP

#include <string>
#include <istream>
#include <ostream>

#include <boost/serialization/utility.hpp>

#include "vector.hpp"
#include "quad.hpp"

class map
{
public:
	std::string name;
	std::vector<quad> quads;

	template<class A> 
	void serialize(A& archive, const unsigned int)
	{
		archive & BOOST_SERIALIZATION_NVP(name);
		archive & BOOST_SERIALIZATION_NVP(quads);
	}

	void draw();
};

BOOST_CLASS_IMPLEMENTATION(map, boost::serialization::object_serializable);

std::istream& operator>> (std::istream& is, map& m);
std::ostream& operator<< (std::ostream& os, const map& m);

#endif //MAP_HPP 