#include "weapon.hpp"
#include "md3.hpp"
#include "world.hpp"
#include "newton.hpp"

#include <boost/bind.hpp>
#include <boost/format.hpp>

const std::string WEAPON_PATH = "models/weapons2/%1%/%1%.md3";
const float WEAPON_OMEGA = 2.0f;

void weapon::compile(const object& parent)
{
	object::compile(parent);

	model.reset(new md3());
	model->name = (boost::format(WEAPON_PATH) % name).str();
	model->compile(*this);

	body.reset(new body_wrapper(root().newton()));
	body->transformation_matrix(composition());
	
	body->transformation_matrix_changed.connect(
		boost::bind(&weapon::composition, this, _1));

	body->omega(vertex(1, 1, 1));
}

void weapon::draw(const state& state) const
{
	matrix_scope scope(composition());
	object::draw(state);
	model->draw(state);
}