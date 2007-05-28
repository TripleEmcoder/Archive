#ifndef OBJECTS_OBJECT_HPP
#define OBJECTS_OBJECT_HPP

#include <boost/shared_ptr.hpp>
#include <boost/serialization/utility.hpp>

#include "string.hpp"
#include "vector.hpp"
#include "map.hpp"
#include "transformation.hpp"

class state;
class level;
class matrix;
class material;

//klasa bazowa obiektow opisujacych swiat
class object
{
public:
	//lista transformacji przestrzennych
	std::vector<transformation> transformations;

	//mapa odwzorowan nazw materialow
	std::map<std::string, std::string> bindings;

	template<class A> 
	void serialize(A& archive, const unsigned int)
	{
		archive & BOOST_SERIALIZATION_NVP(transformations);
		archive & BOOST_SERIALIZATION_NVP(bindings);
	}

public:
	//utworzenie obiektu niepowiazanego w drzewie
	object();

	//przygotowanie obiektu do pierwszego uzycia
	virtual void compile(const object& parent);

	//narysowanie obiektu na ekranie
	virtual void draw(const state& state) const;

	//pobranie rodzica w drzewie obiektow
	virtual const object& parent() const;

	//pobranie korzenia drzewa obiektow
	virtual const level& root() const;

	//pobranie kompletnej macierzy transformacji
	virtual const matrix& composition() const;

	//pobranie materialu powiazanego z nazwa
	virtual const material& bound_material(std::string name) const;

protected:
	virtual void composition(const matrix& matrix);

private:
	const object* _parent;
	const level* _root;
	boost::shared_ptr<matrix> _composition;
};

BOOST_CLASS_IMPLEMENTATION(object, boost::serialization::object_serializable);

#endif //OBJECTS_OBJECT_HPP
