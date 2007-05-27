#include <boost/archive/xml_iarchive.hpp>
#include <boost/archive/xml_oarchive.hpp>
#include <boost/serialization/nvp.hpp>

#include "world.hpp"
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

std::istream& operator>> (std::istream& is, world& world)
{
	boost::archive::xml_iarchive ia(is);
	ia >> boost::serialization::make_nvp("world", world);

	return is;
}

std::ostream& operator<< (std::ostream& os, const world& world)
{
	boost::archive::xml_oarchive oa(os);
	oa << boost::serialization::make_nvp("world", world);

	return os;
}

#include "../Character.hpp"
Character* player;

int GenericContactBegin(const NewtonMaterial* material, const NewtonBody* body0, const NewtonBody* body1)
{
	player = (Character*)(NewtonBodyGetUserData(body0));
	return 1;
}

int  GenericContactProcess(const NewtonMaterial* material, const NewtonContact* contact)
{
	player->processCollision(material);
	return 1;	
}

void compile_second(std::map<std::string, material>& m, const std::pair<std::string, material>& p)
{
	m[p.first].compile();
	//p.second.compile();
}

void world::compile()
{
	float minPoint[] = {-1000, -1000, -1000};
	float maxPoint[] = {1000, 1000, 1000};
	NewtonSetWorldSize(_newton, minPoint, maxPoint);

	// get the default material ID
	int defaultID = NewtonMaterialGetDefaultGroupID (_newton);

	// set default material properties
	NewtonMaterialSetDefaultSoftness(_newton, defaultID, defaultID, 0.05f);
	NewtonMaterialSetDefaultElasticity(_newton, defaultID, defaultID, 0.0f);
	NewtonMaterialSetDefaultCollidable(_newton, defaultID, defaultID, 1);
	//NewtonMaterialSetDefaultFriction(_newton, defaultID, defaultID, 0.0f, 0.0f);
	NewtonMaterialSetCollisionCallback(_newton, defaultID, defaultID, NULL, GenericContactBegin, GenericContactProcess, NULL); 

	std::for_each(materials.begin(), materials.end(), bind(compile_second, var(materials), _1));

	object::compile(*this);
	player.compile(*this);
	
	std::for_each(groups.begin(), groups.end(), bind(&object::compile, _1, ref(*this)));
}

void world::draw(const state& state) const
{
	object::draw(state);
	player.draw(state);

	std::for_each(groups.begin(), groups.end(), bind(&object::draw, _1, ref(state)));
}

const world_id& world::newton() const
{
	return _newton;
}

const material& world::bound_material(std::string name) const
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