#include <boost/archive/xml_iarchive.hpp>
#include <boost/archive/xml_oarchive.hpp>
#include <boost/serialization/nvp.hpp>

#include "map.hpp"

std::istream& operator>> (std::istream& is, map& m)
{
	boost::archive::xml_iarchive ia(is);
	ia >> boost::serialization::make_nvp("map", m);

	return is;
}

std::ostream& operator<< (std::ostream& os, const map& m)
{
	boost::archive::xml_oarchive oa(os);
	oa << boost::serialization::make_nvp("map", m);

	return os;
}

#include <windows.h>
#include <GL/gl.h>
#include <GL/glaux.h>

void map::draw()
{
	for (size_t i=0; i<quads.size(); i++)
		quads[i].draw();

	for (size_t i=0; i<cuboids.size(); i++)
		cuboids[i].draw();

	for (size_t i=0; i<stairs.size(); i++)
		stairs[i].draw();

	for (size_t i=0; i<staircases.size(); i++)
		staircases[i].draw();

	glColor3d(1, 1, 1);
	auxSolidSphere(0.2);
}
