#ifndef OBJECTS_MD3_HPP
#define OBJECTS_MD3_HPP

#include <boost/shared_ptr.hpp>
#include <boost/serialization/utility.hpp>

#include "string.hpp"
#include "vector.hpp"
#include "object.hpp"

class md3_file;
class body_wrapper;

class md3 : public object
{
public:
	std::string name;

	template<class A> 
	void serialize(A& archive, const unsigned int version)
	{
		object::serialize(archive, version);
		archive & BOOST_SERIALIZATION_NVP(name);
	}

public:
	virtual void compile(const object& parent);
	virtual void draw(const state& state) const;

	body_wrapper& body() const;

private:
	boost::shared_ptr<md3_file> _file;
	boost::shared_ptr<body_wrapper> _body;

	mutable float frame;
	mutable int time;
};

BOOST_CLASS_IMPLEMENTATION(md3, boost::serialization::object_serializable);

#endif //OBJECTS_MD3_HPP 
