#include "weapon.hpp"
#include "md3.hpp"
#include "newton.hpp"

#include <boost/format.hpp>

const std::string WEAPON_PATH = "models/weapons2/%1%/%1%.md3";
const float WEAPON_OMEGA = 2.0f;

void weapon::compile(const object& parent)
{
	object::compile(parent);

	_model.reset(new md3());
	_model->name = (boost::format(WEAPON_PATH) % name).str();
	_model->compile(*this);

	_model->body().mass(5.0f, vertex(0, 0, 0));
	_model->body().omega(vertex(0, WEAPON_OMEGA, 0));
}

void weapon::draw(const state& state) const
{
	object::draw(state);
	_model->draw(state);
}