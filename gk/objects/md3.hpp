#ifndef OBJECTS_MD3_HPP
#define OBJECTS_MD3_HPP

#include <boost/shared_ptr.hpp>
#include <boost/serialization/utility.hpp>

#include "string.hpp"
#include "vector.hpp"
#include "object.hpp"

class list_id;
class texture;

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

private:
	std::vector<boost::shared_ptr<list_id> > lists;
	std::vector<boost::shared_ptr<texture> > textures;
	mutable int index;
	mutable int previous;
};

BOOST_CLASS_IMPLEMENTATION(md3, boost::serialization::object_serializable);

#endif //OBJECTS_MD3_HPP 
