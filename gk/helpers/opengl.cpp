#include "opengl.hpp"
#include "matrix.hpp"

#include <iostream>
#include <fstream>

#include <boost/algorithm/string.hpp>
#include <boost/assign.hpp>
#include <boost/bind.hpp>
#include <boost/filesystem/convenience.hpp>
#include <boost/format.hpp>

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

shader_id::shader_id(unsigned int type)
{
	shader = glCreateShader(type);
	_ASSERTE(glGetError() == GL_NO_ERROR);
}

shader_id::~shader_id()
{
	glDeleteShader(shader);
	_ASSERTE(glGetError() == GL_NO_ERROR);
}

shader_id::operator unsigned int() const
{
	return shader;
}

program_id::program_id()
{
	program = glCreateProgram();
	_ASSERTE(glGetError() == GL_NO_ERROR);
}

program_id::~program_id()
{
	glDeleteProgram(program);
	_ASSERTE(glGetError() == GL_NO_ERROR);
}

program_id::operator unsigned int() const
{
	return program;
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

	corona::Image* image = corona::OpenImage(path.string().c_str(), corona::PF_R8G8B8A8);

	if (image == NULL)
	{
		std::cerr << "Failed to load image \"" << name << "\"." << std::endl;
		return;
	}

	int width = image->getWidth();
	int height = image->getHeight();
	void* pixels = image->getPixels();

#ifdef _DEBUG
	std::cerr << "Width: " << width << std::endl;
	std::cerr << "Height: " << height << std::endl;
#endif

	glBindTexture(GL_TEXTURE_2D, id);
	_ASSERTE(glGetError() == GL_NO_ERROR);
	
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	//glTexImage2D(GL_TEXTURE_2D, 0, 4, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixels);
	gluBuild2DMipmaps(GL_TEXTURE_2D, 4, width, height, GL_RGBA, GL_UNSIGNED_BYTE, pixels);
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

void write_log(std::string text)
{
	boost::trim(text);

	if (text.size() > 0)
		std::cerr << text << std::endl;
}

shader_wrapper::shader_wrapper(unsigned int type, std::string name)
:
	id(type)
{
#ifdef _DEBUG
	std::cerr << "Loading shader \"" << name << "\"..." << std::endl;
#endif

	std::ifstream file(name.c_str());

	if (file.fail())
	{
		std::cerr << "Failed to load shader \"" << name << "\"." << std::endl;
		return;
	}

	std::string code;
	std::getline(file, code, '\0');

	const char* hack = code.c_str();

	glShaderSource(id, 1, &hack, NULL);
	_ASSERTE(glGetError() == GL_NO_ERROR);

	glCompileShader(id);

	int total = 0;
	int written = 0;
	char* log = NULL;

	glGetShaderiv(id, GL_INFO_LOG_LENGTH, &total);
	
	if (total > 0)
	{
		log = new char[total];
		glGetShaderInfoLog(id, total, &written, log);
		write_log(log);		
		delete[] log;
	}
}

void program_wrapper::attach(const shader_wrapper& shader)
{
	glAttachShader(id, shader.id);
	_ASSERTE(glGetError() == GL_NO_ERROR);
}

void program_wrapper::detach(const shader_wrapper& shader)
{
	glDetachShader(id, shader.id);
	_ASSERTE(glGetError() == GL_NO_ERROR);
}

void program_wrapper::link()
{
	glLinkProgram(id);

	int total = 0;
	int written = 0;
	char* log = NULL;

	glGetProgramiv(id, GL_INFO_LOG_LENGTH, &total);
	
	if (total > 0)
	{
		log = new char[total];
		glGetProgramInfoLog(id, total, &written, log);
		write_log(log);
		delete[] log;
	}
}

void program_wrapper::use() const
{
	glUseProgram(id);
}

display_wrapper::~display_wrapper()
{
}

window_wrapper::window_wrapper(std::string title, int x, int y, int width, int height)
{
	glutInitWindowSize(width, height);
	glutInitWindowPosition(x, y);
	
	window = glutCreateWindow(title.c_str());
	
	if (window == 0)
		throw std::exception((boost::format(
			"Failed to initialize window \"%1%\".") % title).str().c_str());
}

window_wrapper::~window_wrapper()
{
	glutDestroyWindow(window);
}

fullscreen_wrapper::fullscreen_wrapper(int width, int height, int depth, int frequency)
{
	std::string mode = (boost::format("%1%x%2%:%3%") % width % height % depth).str();
	
	glutGameModeString(mode.c_str());

	if (!glutGameModeGet(GLUT_GAME_MODE_POSSIBLE))
		throw std::exception((boost::format(
			"Failed to initialize mode \"%1%\".") % mode).str().c_str());
	
	glutEnterGameMode();
}

fullscreen_wrapper::~fullscreen_wrapper()
{
	glutLeaveGameMode();
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

list_scope::list_scope(list_wrapper& list)
{
	list.begin();
}

list_scope::~list_scope()
{
	glEndList();
	_ASSERTE(glGetError() == GL_NO_ERROR);
}

program_scope::program_scope(const program_wrapper& program)
{
	program.use();
}

program_scope::~program_scope()
{
	glUseProgram(0);
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
