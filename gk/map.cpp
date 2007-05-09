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
