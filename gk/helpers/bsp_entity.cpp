#include "bsp_entity.hpp"
#include "md3_file.hpp"
#include "opengl.hpp"

#include <iostream>
#include <fstream>

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

bsp_entity* bsp_entity::read(std::string entity)
{
#ifdef _DEBUG
	std::cerr << "Loading entity:" << std::endl;
	std::cerr << entity << std::endl;
#endif

	std::map<std::string, std::string> properties;

	std::string key, value;

	rule<> item_rule = 
		confix_p("\"", (+anychar_p)[assign_a(key)], "\"") 
		>> 
		*space_p
		>>
		confix_p("\"", (+anychar_p)[assign_a(value)], "\"");

	rule<> list_rule =
		*(*space_p >> item_rule[insert_at_a(properties, key, value)] >> *space_p);

	parse(entity.c_str(), confix_p("{", list_rule, "}"));

	typedef std::pair<const std::string, std::string> pair;

#ifdef _DEBUG
	std::cerr << "Parse results:" << std::endl;

	std::for_each(properties.begin(), properties.end(),
		std::cerr 
		<< bind(&pair::first, _1) 
		<< constant("=")
		<< bind(&pair::second, _1)
		<< constant("\n"));
#endif

	if (properties["classname"] == "misc_model")
		return new bsp_model_entity(properties);
}

bsp_visible_entity::bsp_visible_entity(std::map<std::string, std::string> properties)
:
	bsp_entity(properties)
{
	rule<> origin_rule =
		real_p[assign_a(origin.x)] >> space_p
		>>
		real_p[assign_a(origin.y)] >> space_p
		>>
		real_p[assign_a(origin.z)] >> space_p;

	parse(properties["origin"].c_str(), origin_rule);

	swizzle(origin);
	scale(origin, BSP_SCALE);

	parse(properties["angle"].c_str(), real_p[assign_a(angle)]);
}

void bsp_visible_entity::draw() const
{
	glPushMatrix();
	glTranslatef(origin.x, origin.y, origin.z);
	draw_implementation();
	glPopMatrix();
}

bsp_model_entity::bsp_model_entity(std::map<std::string,std::string> properties)
:
	bsp_visible_entity(properties)
{

#ifdef _DEBUG
	std::cerr << "Loading model " << properties["model_name"] << "..." << std::endl;
#endif

	std::ifstream input(properties["model_name"].c_str(), std::ios::binary);
	
	if (!input.is_open())
	{
		std::cerr << "Failed to load model " << properties["model_name"] << "." << std::endl;
		return;
	}
	
	file.reset(new md3_file(input));
}

void bsp_model_entity::draw_implementation() const
{
	if (file)
		file->draw_frame(0);
}
