#ifndef OBJECTS_GROUP_HPP
#define OBJECTS_GROUP_HPP

#include <boost/serialization/utility.hpp>

#include "string.hpp"
#include "vector.hpp"

#include "object.hpp"
#include "builtin.hpp"
#include "ground.hpp"
#include "ceiling.hpp"
#include "wall.hpp"
#include "bsp.hpp"
#include "md3.hpp"
#include "weapon.hpp"

class group : public object
{
public:
	std::string name;
	bool visible;

	std::vector<builtin> builtins;
	std::vector<ground> grounds;
	std::vector<ceiling> ceilings;
	std::vector<wall> walls;
	std::vector<bsp> bsps;
	std::vector<md3> md3s;
	std::vector<weapon> weapons;

	std::vector<group> groups;

	template<class A> 
	void serialize(A& archive, const unsigned int version)
	{
		archive & BOOST_SERIALIZATION_NVP(name);
		archive & BOOST_SERIALIZATION_NVP(visible);

		object::serialize(archive, version);

		archive & BOOST_SERIALIZATION_NVP(builtins);
		archive & BOOST_SERIALIZATION_NVP(grounds);
		archive & BOOST_SERIALIZATION_NVP(ceilings);
		archive & BOOST_SERIALIZATION_NVP(walls);
		archive & BOOST_SERIALIZATION_NVP(bsps);
		archive & BOOST_SERIALIZATION_NVP(md3s);
		archive & BOOST_SERIALIZATION_NVP(weapons);

		archive & BOOST_SERIALIZATION_NVP(groups);
	}

public:
	virtual void compile(const object& parent);
	virtual void draw(const state& state) const;
};

BOOST_CLASS_IMPLEMENTATION(group, boost::serialization::object_serializable);

#endif //OBJECTS_GROUP_HPP
