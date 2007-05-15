#include "texture.hpp"
#include "cache.hpp"
#include "engine.hpp"

texture::texture()
: image(""), width(0), height(0)
{

}

texture::texture(std::string image, float width, float height)
: image(image), width(width), height(height)
{
}

void texture::compile()
{
	cache::texture(image);
}

void texture::draw() const
{
	glBindTexture(GL_TEXTURE_2D, cache::texture(image));
}

boost::tuple<float, float> texture::ratio(float _width, float _height) const
{
	if (width == 0)
		_width = width;

	if (height == 0)
		_height = height;

	return boost::make_tuple(_width/width, _height/height);
}
