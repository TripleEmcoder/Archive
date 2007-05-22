#include "texture.hpp"
#include "engine.hpp"

#include <iostream>

texture::texture()
: name(""), width(0), height(0)
{
}

texture::texture(std::string name, float width, float height)
: name(name), width(width), height(height)
{
}

void texture::compile()
{
	corona::Image* image = corona::OpenImage(name.c_str(), corona::PF_R8G8B8);

	if (image == NULL)
	{
		std::cerr << "Failed to load image \"" << name << "\"." << std::endl;
		return;
	}

	id.reset(new texture_id());

	glBindTexture(GL_TEXTURE_2D, *id);
	_ASSERTE(glGetError() == GL_NO_ERROR);
	
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
	_ASSERTE(glGetError() == GL_NO_ERROR);

	delete image;
}

void texture::draw(const state& state) const
{
	glBindTexture(GL_TEXTURE_2D, id ? *id : 0);
	_ASSERTE(glGetError() == GL_NO_ERROR);
}

boost::tuple<float, float> texture::ratio(float _width, float _height) const
{
	return boost::make_tuple(width != 0 ? _width/width : 1, height != 0 ? _height/height : 1);
}
