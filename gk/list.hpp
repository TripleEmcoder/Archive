#ifndef LIST_HPP
#define LIST_HPP

#include <list>

#include <boost/serialization/list.hpp>

namespace boost 
{ 
	namespace serialization 
	{ 
		template<class T> 
		struct implementation_level<std::list<T> > 
		{ 
			typedef mpl::integral_c_tag tag; 
			typedef mpl::int_< boost::serialization::object_serializable > type; 
			static const int value = implementation_level::type::value; 
		}; 
	}
}

#endif //LIST_HPP