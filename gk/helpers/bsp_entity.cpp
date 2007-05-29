#include "bsp_entity.hpp"

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

	rule<> set_rule
		= conf

	parse(entities.c_str(), set_rule);
	return result;
	
	//std::cerr << entities << std::endl;
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
	std::map<std::string, std::string> values;

	std::string key, value;

	rule<> pair_rule = 
		confix_p("\"", (+anychar_p)[assign_a(key)], "\"") 
		>> 
		*space_p
		>>
		confix_p("\"", (+anychar_p)[assign_a(value)], "\"");

	rule<> row_rule =
		*space_p >> pair_rule >> *space_p;

	rule<> table_rule =
		confix_p("{", *row_rule[insert_at_a(values, key, value)], "}");

	 parse(entity.c_str(), table_rule);

	 typedef std::pair<const std::string, std::string> pair;

	 std::for_each(values.begin(), values.end(),
		 std::cerr 
			<< bind(&pair::first, _1) 
			<< constant("=")
			<< bind(&pair::second, _1)
			<< constant("\n"));
}

void bsp_entity::draw() const
{
}
