#include "texture.hpp"
#include "engine.hpp"

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

void test_extension(boost::filesystem::path& previous, const std::string& extension)
{
	boost::filesystem::path current 
		= boost::filesystem::change_extension(previous, extension);

//#ifdef _DEBUG
//	std::cerr << "Trying filename \"" << current.string() << "\"..." << std::endl;
//#endif

	if (boost::filesystem::exists(current))
		previous = current;
}

void texture::compile()
{
	static std::vector<std::string> extensions
		= boost::assign::list_of(".jpg")(".tga");

	boost::filesystem::path path(name);

	std::for_each(extensions.begin(), extensions.end(),
		boost::bind(test_extension, boost::ref(path), _1));

#ifdef _DEBUG
	std::cerr << "Loading texture \"" << path.string() << "\"..." << std::endl;
#endif

	corona::Image* image = corona::OpenImage(path.string().c_str(), corona::PF_R8G8B8);

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

void texture::draw() const
{
	glBindTexture(GL_TEXTURE_2D, id ? *id : 0);
	_ASSERTE(glGetError() == GL_NO_ERROR);
}

boost::tuple<float, float> texture::ratio(float _width, float _height) const
{
	return boost::make_tuple(width != 0 ? _width/width : 1, height != 0 ? _height/height : 1);
}
