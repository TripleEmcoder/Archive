#ifndef HELPERS_SCOPE_HPP
#define HELPERS_SCOPE_HPP

class transformation;

class transformation_scope
{
public:
	transformation_scope(const transformation& composition);
	~transformation_scope();
};

class list_id;

class list_scope
{
public:
	list_scope(const list_id& id);
	~list_scope();
};

#endif //HELPERS_SCOPE_HPP
