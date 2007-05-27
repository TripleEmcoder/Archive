#include "md3.hpp"
#include "md3_file.hpp"
#include "md3_frame.hpp"
#include "md3_surface.hpp"
#include "opengl.hpp"

#include <fstream>
#include <iostream>

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

	file.reset(new md3_file(input));

	time = glutGet(GLUT_ELAPSED_TIME);
	frame = 0;
}

void md3::draw(const state& state) const
{
	int elapsed = glutGet(GLUT_ELAPSED_TIME) - time;
	frame += elapsed * MD3_FPS / 1000;
	time = glutGet(GLUT_ELAPSED_TIME);

	if (frame >= file->frame_count())
		 frame = 0;

	object::draw(state);
	
	//matrix_scope scope(composition());
	file->draw_frame(frame);		
}
