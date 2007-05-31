#ifndef HELPERS_BSP_ENTITY_HPP
#define HELPERS_BSP_ENTITY_HPP

#include <string>
#include <vector>
#include <map>

#include <boost/shared_ptr.hpp>

#include "bsp_common.hpp"

class bsp_entity
{
public:
	static std::vector<std::string> split(std::string entities);
	static bsp_entity* read(std::string entity);
	
	virtual ~bsp_entity();

protected:
	bsp_entity(std::map<std::string, std::string> properties);
};

class bsp_visible_entity : public bsp_entity
{
public:
	bsp_visible_entity(std::map<std::string, std::string> properties);
	void draw() const;

protected:
	virtual void draw_implementation() const = 0;

private:
	bsp_vector3f origin;
};

class md3_file;

class bsp_model_entity : public bsp_visible_entity
{
public:
	bsp_model_entity(std::map<std::string, std::string> properties);
	
protected:
	void load(std::string name);
	virtual void draw_implementation() const;

private:
	boost::shared_ptr<md3_file> file;
};

class bsp_misc_entity : public bsp_model_entity
{
public:
	bsp_misc_entity(std::map<std::string, std::string> properties);

protected:
	virtual void draw_implementation() const;

private:
	float angle;
};

class bsp_weapon_entity : public bsp_model_entity
{
public:
	bsp_weapon_entity(std::map<std::string, std::string> properties);

protected:
	virtual void draw_implementation() const;
};

#endif //HELPERS_BSP_ENTITY_HPP
