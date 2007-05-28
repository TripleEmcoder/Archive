#include <boost/archive/xml_iarchive.hpp>
#include <boost/archive/xml_oarchive.hpp>
#include <boost/serialization/nvp.hpp>

#include "level.hpp"
#include "transformation.hpp"
#include "state.hpp"
#include "opengl.hpp"
#include "newton.hpp"

#include <algorithm>

#include <boost/lambda/lambda.hpp>
#include <boost/lambda/bind.hpp>

using boost::ref;
using boost::lambda::bind;
using boost::lambda::var;
using boost::lambda::_1;

std::istream& operator>> (std::istream& is, level& value)
{
	boost::archive::xml_iarchive ia(is);
	ia >> boost::serialization::make_nvp("level", value);

	return is;
}

std::ostream& operator<< (std::ostream& os, const level& value)
{
	boost::archive::xml_oarchive oa(os);
	oa << boost::serialization::make_nvp("level", value);

	return os;
}

void compile_second(std::map<std::string, material>& m, const std::pair<std::string, material>& p)
{
	m[p.first].compile();
	//p.second.compile();
}

void level::compile()
{
	_world.size(vertex(-1000, -1000, -1000), vertex(1000, 1000, 1000));

	std::for_each(materials.begin(), materials.end(), bind(compile_second, var(materials), _1));

	object::compile(*this);
	player.compile(*this);
	
	std::for_each(groups.begin(), groups.end(), bind(&object::compile, _1, ref(*this)));
}

void level::draw(const state& state) const
{
	object::draw(state);
	player.draw(state);

	std::for_each(groups.begin(), groups.end(), bind(&object::draw, _1, ref(state)));
}

const world_wrapper& level::world() const
{
	return _world;
}

const material& level::bound_material(std::string name) const
{
	if (bindings.count(name))
		name = bindings.find(name)->second;

	else if (bindings.count("default"))
		name = bindings.find("default")->second;

	if (materials.count(name))
		return materials.find(name)->second;

	static const material none;
	
	return none;
}