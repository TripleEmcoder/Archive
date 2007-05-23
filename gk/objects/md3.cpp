#include "md3.hpp"
#include "md3_common.hpp"
#include "md3_frame.hpp"
#include "md3_surface.hpp"
#include "id.hpp"
#include "scope.hpp"
#include "engine.hpp"

#include <fstream>
#include <iostream>

#include <boost/bind.hpp>

void md3::compile(const object& parent)
{
	object::compile(parent);

#ifdef _DEBUG
	std::cerr << "Loading model " << name << "..." << std::endl;
#endif

	std::ifstream input(name.c_str(), std::ios::binary);
	
	if (!input.is_open())
	{
		std::cerr << "Failed to load model " << name << "." << std::endl;
		return;
	}

	md3_header header;
	binary_read(input, header);

	_ASSERTE(header.magic == MD3_MAGIC);
	_ASSERTE(header.version == MD3_VERSION);

#ifdef _DEBUG
	std::cerr << "Model name: " << header.name << std::endl;
	std::cerr << "Frame count: " << header.frame_count << std::endl;
	std::cerr << "Tag count: " << header.tag_count << std::endl;
	std::cerr << "Surface count: " << header.surface_count << std::endl;
	std::cerr << "Skin count: " << header.skin_count << std::endl;
#endif
	
	std::vector<md3_frame> frames(header.frame_count);
	input.seekg(header.frame_offset);
	
	std::for_each(frames.begin(), frames.end(),
		boost::bind(&md3_frame::read, _1, boost::ref(input)));

	std::vector<md3_surface> surfaces(header.surface_count);
	input.seekg(header.surface_offset);
	
	std::for_each(surfaces.begin(), surfaces.end(),
		boost::bind(&md3_surface::read, _1, boost::ref(input)));

	lists.resize(header.frame_count);

	for (int index=0; index<header.frame_count; index++)
	{
		lists[index].reset(new list_id());
		list_scope scope(*lists[index]);

		glPushClientAttrib(GL_CLIENT_VERTEX_ARRAY_BIT);
		glEnableClientState(GL_VERTEX_ARRAY);

		std::for_each(surfaces.begin(), surfaces.end(),
			boost::bind(&md3_surface::draw, _1, index));

		glPopClientAttrib();
	}
	previous = glutGet(GLUT_ELAPSED_TIME);
}

void md3::draw(const state& state) const
{
	object::draw(state);
	
	matrix_scope scope(composition());
	
	int current = glutGet(GLUT_ELAPSED_TIME);
	
	if (current - previous > 100) 
	{
		previous = current;
		index++;
	}

	if (index < 0 || lists.size() <= index)
		 index = 0;

	if (lists.size() > 0)
		glCallList(*lists[index]);
}
