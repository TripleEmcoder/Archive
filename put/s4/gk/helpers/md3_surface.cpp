#include "md3_surface.hpp"
#include "opengl.hpp"

#include <iostream>
#include <algorithm>
#include <cmath>

#include <boost/bind.hpp>

md3_vector convert_vertex(const md3_xyzn& xyzn)
{
	md3_vector vertex;
	
	vertex.x = xyzn.x * MD3_SCALE;
	vertex.y = xyzn.y * MD3_SCALE;
	vertex.z = xyzn.z * MD3_SCALE;

	return vertex;
}

/*
lat <- ((normal shift-right 8) binary-and 255) * (2 * pi ) / 255
lng <- (normal binary-and 255) * (2 * pi) / 255
x <- cos ( lat ) * sin ( lng )
y <- sin ( lat ) * sin ( lng )
z <- cos ( lng )
*/

md3_vector convert_normal(const md3_xyzn& xyzn)
{
	md3_vector normal;

	float latitude = ((xyzn.n >> 8) & 255) * 2 * MD3_PI / 255;
	float longitude = (xyzn.n & 255) * 2 * MD3_PI / 255;

	normal.x = cos(latitude) * sin(longitude);
	normal.y = sin(latitude) * cos(longitude);
	normal.z = cos(longitude);

	return normal;
}

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

	vertices.resize(header.frame_count*header.vertex_count);
	std::transform(xyzns.begin(), xyzns.end(), vertices.begin(), convert_vertex);

	normals.resize(header.frame_count*header.vertex_count);
	std::transform(xyzns.begin(), xyzns.end(), normals.begin(), convert_normal);

	std::for_each(xyzns.begin(), xyzns.end(), convert_normal);

	sts.resize(header.vertex_count);
	input.seekg(start + header.st_offset);

	std::for_each(sts.begin(), sts.end(),
		boost::bind(binary_read<md3_st>, boost::ref(input), _1));
	
	triangles.resize(header.triangle_count);
	input.seekg(start + header.triangle_offset);

	std::for_each(triangles.begin(), triangles.end(),
		boost::bind(binary_read<md3_triangle>, boost::ref(input), _1));

	input.seekg(start + header.end_offset);

	texture.reset(new texture_wrapper(shaders[0].name()));
}

int md3_surface::frame_count() const
{
	return header.frame_count;
}

void md3_surface::draw_frame(int frame) const
{
	texture_scope scope(*texture);

	glVertexPointer(3, GL_FLOAT, sizeof(md3_vector), &vertices[frame*header.vertex_count]);
	glNormalPointer(GL_FLOAT, sizeof(md3_vector), &normals[frame*header.vertex_count]);
	glTexCoordPointer(2, GL_FLOAT, sizeof(md3_st), &sts[0]);
	glDrawElements(GL_TRIANGLES, 3*triangles.size(), GL_UNSIGNED_INT, &triangles[0]);
}
