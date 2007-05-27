#include "md3_file.hpp"
#include "opengl.hpp"

#include <iostream>
#include <algorithm>

#include <boost/bind.hpp>

md3_file::md3_file(std::istream& input)
{
	read(input);
}

void md3_file::read(std::istream& input)
{
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
	
	frames.resize(header.frame_count);
	input.seekg(header.frame_offset);
	
	std::for_each(frames.begin(), frames.end(),
		boost::bind(&md3_frame::read, _1, boost::ref(input)));

	surfaces.resize(header.surface_count);
	input.seekg(header.surface_offset);
	
	std::for_each(surfaces.begin(), surfaces.end(),
		boost::bind(&md3_surface::read, _1, boost::ref(input)));

	lists.resize(header.frame_count);

	for (int frame=0; frame<header.frame_count; frame++)
	{
		lists[frame].reset(new list_wrapper());
		list_scope scope(*lists[frame]);

		glPushMatrix();
		glScalef(MD3_SCALE, MD3_SCALE, MD3_SCALE);
		glRotatef(-90, 1, 0, 0);

		glPushAttrib(GL_ENABLE_BIT);
		glEnable(GL_TEXTURE_2D);

		glPushClientAttrib(GL_CLIENT_VERTEX_ARRAY_BIT);
		glEnableClientState(GL_VERTEX_ARRAY);
		glEnableClientState(GL_NORMAL_ARRAY);
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);

		for (int surface=0; surface<header.surface_count; surface++)
			surfaces[surface].draw_frame(frame);

		glPopClientAttrib();
		glPopAttrib();
		glPopMatrix();
	}
}

int md3_file::frame_count() const
{
	return header.frame_count;
}

void md3_file::draw_frame(int frame) const
{
	lists[frame]->call();
}
