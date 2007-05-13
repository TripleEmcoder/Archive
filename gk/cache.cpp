#include "cache.hpp"

#include <iostream>

#include <windows.h>
#include <GL/gl.h>

#include "tga.h"

std::map<std::string, int> cache::textures;

int cache::texture(std::string name)
{
	if (textures.count(name) == 0)
	{
		unsigned int id;
		glGenTextures(1, &id);
		glBindTexture(GL_TEXTURE_2D, id);

		TGAImg img;

		if (img.Load((char*)name.c_str()) == IMG_OK) 
		{
			switch (img.GetBPP())
			{
			case 24:
			case 32:
				{
					int bpp = img.GetBPP()/8;
					glTexImage2D(GL_TEXTURE_2D, 0, bpp, img.GetWidth(), img.GetHeight(),
						0, GL_RGB,GL_UNSIGNED_BYTE,img.GetImg());

					glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
					glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
					glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
					glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

					break;
				}

			default:
				{
					std::cerr << "Texture " << name << " has invalid BPP." << std::endl;
					break;
				}
			}
		}
		else
		{
			std::cerr << "Failed to load texture " << name << "." << std::endl;
		}

		textures[name] = id;
	}

	return textures[name];
}