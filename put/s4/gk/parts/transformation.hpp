#ifndef HELPERS_TRANSFORMATION_HPP
#define HELPERS_TRANSFORMATION_HPP

#include <boost/shared_ptr.hpp>
#include <boost/serialization/utility.hpp>

#include "vertex.hpp"

class matrix;

class transformation
{
public:
	std::string name;
	vertex description;

	template<class A>
	void serialize(A& archive, const unsigned int)
	{
		archive & BOOST_SERIALIZATION_NVP(name);
		archive & BOOST_SERIALIZATION_NVP(description);
	}

public:
	virtual void compile();

	const matrix& composition() const;
	
private:
	boost::shared_ptr<matrix> _composition;
};

BOOST_CLASS_IMPLEMENTATION(transformation, boost::serialization::object_serializable);

#endif //HELPERS_TRANSFORMATION_HPP
