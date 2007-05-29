#ifndef HELPERS_OPENGL_HPP
#define HELPERS_OPENGL_HPP

#include <string>

#include <boost/utility.hpp>

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <GL/glew.h>	
#include <GL/glut.h>

//(de)alokacja identyfikatora tekstury
class texture_id : private boost::noncopyable
{
public:
	texture_id();
	~texture_id();
	operator unsigned int() const;

private:
	unsigned int texture;
};

//(de)alokacja identyfikatora listy
class list_id : private boost::noncopyable
{
public:
	list_id();
	~list_id();
	operator unsigned int() const;

private:
	unsigned int list;
};

class shader_id : private boost::noncopyable
{
public:
	shader_id(unsigned int type);
	~shader_id();
	operator unsigned int() const;

private:
	unsigned int shader;
};

class program_id : private boost::noncopyable
{
public:
	program_id();
	~program_id();
	operator unsigned int() const;

private:
	unsigned int program;
};

//operacje na pojedynczej teksturze
class texture_wrapper
{
public:
	texture_wrapper(std::string name);
	void bind() const;

private:
	texture_id id;
};

//operacje na pojedynczej liscie
class list_wrapper
{
public:
	void begin() const;
	void call() const;
	//void end();

private:
	list_id id;
};

class shader_wrapper
{
public:
	shader_wrapper(unsigned int type, std::string name);

private:
	friend class program_wrapper;
	shader_id id;
};

class program_wrapper
{
public:
	void attach(const shader_wrapper& shader);
	void detach(const shader_wrapper& shader);
	void link();
	void use() const;

private:
	program_id id;
};

class display_wrapper
{
public:
	virtual ~display_wrapper();
};

class window_wrapper : public display_wrapper
{
public:
	window_wrapper(std::string title, int x, int y, int width, int height);
	virtual ~window_wrapper();

private:
	int window;
};

class fullscreen_wrapper : public display_wrapper
{
public:
	fullscreen_wrapper(int width, int height, int depth, int frequency);
	virtual ~fullscreen_wrapper();
};

//obsluga obszaru obiazywania tekstury
class texture_scope
{
public:
	texture_scope(const texture_wrapper& texture);
	~texture_scope();
};

//obsluga obszaru budowania listy
class list_scope
{
public:
	list_scope(list_wrapper& list);
	~list_scope();
};

class program_scope
{
public:
	program_scope(const program_wrapper& program);
	~program_scope();
};

class matrix;

//obsluga obszaru obowiazywania przeksztalcen
class matrix_scope
{
public:
	matrix_scope(const matrix& matrix);
	~matrix_scope();
};

#endif //HELPERS_OPENGL_HPP
