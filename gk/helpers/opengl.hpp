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

private:
	list_id id;
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
	list_scope(const list_wrapper& list);
	~list_scope();
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
