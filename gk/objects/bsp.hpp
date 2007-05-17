#ifndef OBJECTS_BSP_HPP
#define OBJECTS_BSP_HPP

#include <boost/shared_ptr.hpp>
#include <boost/serialization/utility.hpp>

#include "string.hpp"
#include "vector.hpp"
#include "object.hpp"

class bsp_vertex;
class bsp_face;

class bsp : public object
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
	virtual void draw() const;

private:
	std::vector<boost::shared_ptr<material> > _materials;
	std::vector<boost::shared_ptr<bsp_vertex> > _vertices;
	std::vector<boost::shared_ptr<bsp_face> > _faces;
};

BOOST_CLASS_IMPLEMENTATION(bsp, boost::serialization::object_serializable);

#endif //OBJECTS_BSP_HPP 
