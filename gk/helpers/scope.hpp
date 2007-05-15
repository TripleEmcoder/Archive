#ifndef HELPERS_SCOPE_HPP
#define HELPERS_SCOPE_HPP

//class transformation;
class object;

class scope
{
public:
	//scope(const transformation& composition);
	scope(const object& owner);
	~scope();
};

#endif //HELPERS_SCOPE_HPP
