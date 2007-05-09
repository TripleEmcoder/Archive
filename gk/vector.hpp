#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <vector>

#include <boost/serialization/vector.hpp>

namespace boost 
{ 
	namespace serialization 
	{ 
		template<class T> 
		struct implementation_level<std::vector<T> > 
		{ 
			typedef mpl::integral_c_tag tag; 
			typedef mpl::int_< boost::serialization::object_serializable > type; 
			static const int value = implementation_level::type::value; 
		}; 
	}
}

#endif //VECTOR_HPP