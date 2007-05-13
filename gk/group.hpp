#ifndef GROUP_HPP
#define GROUP_HPP

#include <boost/serialization/utility.hpp>

#include "vector.hpp"
#include "quad.hpp"
#include "cuboid.hpp"
#include "staircase.hpp"
#include "wall.hpp"

class group
{
public:
	std::string name;
	bool visible;

	std::vector<quad> quads;
	std::vector<cuboid> cuboids;
	std::vector<staircase> staircases;
	std::vector<wall> walls;

	std::vector<group> groups;

	template<class A> 
	void serialize(A& archive, const unsigned int)
	{
		archive & BOOST_SERIALIZATION_NVP(name);
		archive & BOOST_SERIALIZATION_NVP(visible);

		archive & BOOST_SERIALIZATION_NVP(quads);
		archive & BOOST_SERIALIZATION_NVP(cuboids);
		archive & BOOST_SERIALIZATION_NVP(staircases);
		archive & BOOST_SERIALIZATION_NVP(walls);

		archive & BOOST_SERIALIZATION_NVP(groups);
	}

	void draw() const;
};

BOOST_CLASS_IMPLEMENTATION(group, boost::serialization::object_serializable);

#endif //GROUP_HPP
