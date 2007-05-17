#include "texture.hpp"
#include "engine.hpp"

#include <iostream>
#include <cassert>

texture::texture()
: name(""), width(0), height(0), id(new unsigned int(0))
{
}

texture::texture(std::string name, float width, float height)
: name(name), width(width), height(height), id(new unsigned int(0))
{
}

unsigned int* create_single_texture()
{
	unsigned int* id = new unsigned int(0);
	
	glGenTextures(1, id);
	assert(glGetError() == GL_NO_ERROR);

	return id;
}

void delete_single_texture(unsigned int* id)
{
	glDeleteTextures(1, id);
	assert(glGetError() == GL_NO_ERROR);

	delete id;
}

void texture::compile()
{
	corona::Image* image = corona::OpenImage(name.c_str(), corona::PF_R8G8B8);

	if (image == NULL)
	{
		std::cerr << "Failed to load image \"" << name << "\"." << std::endl;
		return;
	}
	
	id.reset(create_single_texture(), delete_single_texture);
	
	glBindTexture(GL_TEXTURE_2D, *id);
	assert(glGetError() == GL_NO_ERROR);
	
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	int width = image->getWidth();
	int height = image->getHeight();
	void* pixels = image->getPixels();
	
	//glTexImage2D(GL_TEXTURE_2D, 0, 3, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, pixels);
	gluBuild2DMipmaps(GL_TEXTURE_2D, 3, width, height, GL_RGB, GL_UNSIGNED_BYTE, pixels);
	assert(glGetError() == GL_NO_ERROR);

	delete image;
}

void texture::draw() const
{
	glBindTexture(GL_TEXTURE_2D, *id);
	assert(glGetError() == GL_NO_ERROR);
}

boost::tuple<float, float> texture::ratio(float _width, float _height) const
{
	return boost::make_tuple(width ? _width/width : 1, height ? _height/height : 1);
}
