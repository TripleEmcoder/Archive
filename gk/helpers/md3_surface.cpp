#include "md3_surface.hpp"
#include "texture.hpp"
#include "engine.hpp"

#include <iostream>
#include <algorithm>

#include <boost/bind.hpp>

void md3_surface::read(std::istream &input)
{
	int start = input.tellg();
	binary_read(input, header);

	_ASSERTE(header.magic == MD3_MAGIC);

#ifdef _DEBUG
	std::cerr << "Surface name: " << header.name << std::endl;
	std::cerr << "Frame count: " << header.frame_count << std::endl;
	std::cerr << "Shader count: " << header.shader_count << std::endl;
	std::cerr << "Vertex count: " << header.vertex_count << std::endl;
	std::cerr << "Triangle count: " << header.triangle_count << std::endl;
#endif

	shaders.resize(header.shader_count);
	input.seekg(start + header.shader_offset);
	
	std::for_each(shaders.begin(), shaders.end(),
		boost::bind(&md3_shader::read, _1, boost::ref(input)));

	xyzns.resize(header.frame_count*header.vertex_count);
	input.seekg(start + header.xyzn_offset);

	std::for_each(xyzns.begin(), xyzns.end(),
		boost::bind(binary_read<md3_xyzn>, boost::ref(input), _1));

	sts.resize(header.vertex_count);
	input.seekg(start + header.st_offset);

	std::for_each(sts.begin(), sts.end(),
		boost::bind(binary_read<md3_st>, boost::ref(input), _1));
	
	triangles.resize(header.triangle_count);
	input.seekg(start + header.triangle_offset);

	std::for_each(triangles.begin(), triangles.end(),
		boost::bind(binary_read<md3_triangle>, boost::ref(input), _1));

	input.seekg(start + header.end_offset);
}

void md3_surface::draw(int frame) const
{	glVertexPointer(3, GL_SHORT, sizeof(md3_xyzn), &xyzns[frame*header.vertex_count]);
	glTexCoordPointer(2, GL_FLOAT, sizeof(md3_st), &sts[0]);
	glDrawElements(GL_TRIANGLES, 3*triangles.size(), GL_UNSIGNED_INT, &triangles[0]);
}

std::string md3_surface::shader() const
{
	return shaders[0].name();
}
