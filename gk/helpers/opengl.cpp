#include "opengl.hpp"
#include "matrix.hpp"

#include <iostream>

#include <boost/assign.hpp>
#include <boost/bind.hpp>
#include <boost/filesystem/convenience.hpp>

#include <crtdbg.h>
#include <corona.h>

texture_id::texture_id()
{
	glGenTextures(1, &texture);
	_ASSERTE(glGetError() == GL_NO_ERROR);
}

texture_id::~texture_id()
{
	glDeleteTextures(1, &texture);
	_ASSERTE(glGetError() == GL_NO_ERROR);
}

texture_id::operator unsigned int() const
{
	return texture;
}

list_id::list_id()
{
	list = glGenLists(1);
	_ASSERTE(glGetError() == GL_NO_ERROR);
}

list_id::~list_id()
{
	glDeleteLists(list, 1);
	_ASSERTE(glGetError() == GL_NO_ERROR);
}

list_id::operator unsigned int() const
{
	return list;
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

texture_wrapper::texture_wrapper(std::string name)
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

	glBindTexture(GL_TEXTURE_2D, id);
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

void texture_wrapper::bind() const
{
	glBindTexture(GL_TEXTURE_2D, id);
	_ASSERTE(glGetError() == GL_NO_ERROR);
}

void list_wrapper::begin() const
{
	glNewList(id, GL_COMPILE);
	_ASSERTE(glGetError() == GL_NO_ERROR);
}

void list_wrapper::call() const
{
	glCallList(id);
	_ASSERTE(glGetError() == GL_NO_ERROR);
}

texture_scope::texture_scope(const texture_wrapper& texture)
{
	glPushAttrib(GL_TEXTURE_BIT);
	_ASSERTE(glGetError() == GL_NO_ERROR);
	texture.bind();
}

texture_scope::~texture_scope()
{
	glPopAttrib();
	_ASSERTE(glGetError() == GL_NO_ERROR);
};

list_scope::list_scope(const list_wrapper& list)
{
	list.begin();
}

list_scope::~list_scope()
{
	glEndList();
	_ASSERTE(glGetError() == GL_NO_ERROR);
}

matrix_scope::matrix_scope(const matrix& matrix)
{
	glPushMatrix();
	_ASSERTE(glGetError() == GL_NO_ERROR);
	
	glMultMatrixf(matrix.row_major_data());
	_ASSERTE(glGetError() == GL_NO_ERROR);
}

matrix_scope::~matrix_scope()
{
	glPopMatrix();
	_ASSERTE(glGetError() == GL_NO_ERROR);
}
