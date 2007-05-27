#include "texture.hpp"
#include "opengl.hpp"

#include <iostream>

#include <boost/assign.hpp>
#include <boost/bind.hpp>
#include <boost/filesystem/convenience.hpp>

texture::texture()
: name(""), width(0), height(0)
{
}

texture::texture(std::string name, float width, float height)
: name(name), width(width), height(height)
{
	compile();
}

void texture::compile()
{
	wrapper.reset(new texture_wrapper(name));
}

void texture::draw() const
{
	wrapper->bind();
}

boost::tuple<float, float> texture::ratio(float _width, float _height) const
{
	return boost::make_tuple(width != 0 ? _width/width : 1, height != 0 ? _height/height : 1);
}
