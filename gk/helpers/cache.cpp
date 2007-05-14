#include "cache.hpp"

#include <iostream>
#include <memory>

#include <windows.h>
#include <GL/gl.h>

#include <corona.h>

std::map<std::string, int> cache::textures;

int cache::texture(std::string name)
{
	if (name == "")
		return 0;

	if (textures.count(name) != 0)
		return textures[name];

	corona::Image* image = corona::OpenImage(name.c_str(), corona::PF_R8G8B8);

	if (image == NULL)
	{
		std::cerr << "Failed to load image " << name << "." << std::endl;
		return textures[name] = 0;
	}

	unsigned int id = 0;
	glGenTextures(1, &id);
	glBindTexture(GL_TEXTURE_2D, id);

	int width = image->getWidth();
	int height = image->getHeight();
	void* pixels = image->getPixels();

	glTexImage2D(GL_TEXTURE_2D, 0, 3, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, pixels);
	delete image;

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	return textures[name] = id;
}