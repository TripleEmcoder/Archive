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

void map::draw() const
{
	group::draw();

	glColor3d(1, 1, 1);
	auxSolidSphere(0.2);
}
