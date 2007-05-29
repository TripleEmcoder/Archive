#include "bsp_entity.hpp"
#include "opengl.hpp"

#include <iostream>
#include <map>

#include <boost/lambda/lambda.hpp>
#include <boost/lambda/bind.hpp>

#include <boost/spirit.hpp>
#include <boost/spirit/actor.hpp>

using namespace boost::lambda;
using namespace boost::spirit;

std::vector<std::string> bsp_entity::split(std::string entities)
{
	std::vector<std::string> result;

	rule<> item_rule =
		confix_p("{", +anychar_p, "}");

	rule<> list_rule =
		*(*space_p >> item_rule[push_back_a(result)] >> *space_p);

	parse(entities.c_str(), list_rule);

	return result;
}

/*
{
"classname" "misc_model"
"model" "models/mapobjects/skull/skull_tilt1.md3"
"angle" "135"
"origin" "-972 -1908 -104"
}
*/

bsp_entity::bsp_entity(std::string entity)
{
#ifdef _DEBUG
	std::cerr << "Loading entity:" << std::endl;
	std::cerr << entity << std::endl;
#endif

	std::map<std::string, std::string> values;

	std::string key, value;

	rule<> item_rule = 
		confix_p("\"", (+anychar_p)[assign_a(key)], "\"") 
		>> 
		*space_p
		>>
		confix_p("\"", (+anychar_p)[assign_a(value)], "\"");

	rule<> list_rule =
		*(*space_p >> item_rule[insert_at_a(values, key, value)] >> *space_p);

	parse(entity.c_str(), confix_p("{", list_rule, "}"));

	typedef std::pair<const std::string, std::string> pair;

#ifdef _DEBUG
	std::cerr << "Parse results:" << std::endl;

	std::for_each(values.begin(), values.end(),
		std::cerr 
		<< bind(&pair::first, _1) 
		<< constant("=")
		<< bind(&pair::second, _1)
		<< constant("\n"));
#endif

	rule<> origin_rule =
		real_p[assign_a(origin.x)] >> space_p
		>>
		real_p[assign_a(origin.y)] >> space_p
		>>
		real_p[assign_a(origin.z)] >> space_p;

	parse(values["origin"].c_str(), origin_rule);

	origin.x *= BSP_SCALE;
	origin.y *= BSP_SCALE;
	origin.z *= BSP_SCALE;

	parse(values["angle"].c_str(), real_p[assign_a(angle)]);
}

void bsp_entity::draw() const
{
	glPushMatrix();
	glTranslatef(origin.x, origin.y, origin.z);
	glutSolidSphere(0.2, 20, 20);
	glPopMatrix();
}
