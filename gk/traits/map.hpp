#ifndef TRAITS_LIST_HPP
#define TRAITS_LIST_HPP

#include <map>

#include <boost/serialization/map.hpp>

namespace boost 
{ 
	namespace serialization 
	{ 
		template<class K, class V> 
		struct implementation_level<std::map<K, V> > 
		{ 
			typedef mpl::integral_c_tag tag; 
			typedef mpl::int_<boost::serialization::object_serializable> type; 
			static const int value = implementation_level::type::value; 
		}; 

		template<class K, class V> 
		struct implementation_level<std::pair<K, V> > 
		{ 
			typedef mpl::integral_c_tag tag; 
			typedef mpl::int_<boost::serialization::object_serializable> type; 
			static const int value = implementation_level::type::value; 
		}; 
	}
}

#endif //TRAITS_LIST_HPP