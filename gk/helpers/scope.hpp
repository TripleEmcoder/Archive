#ifndef HELPERS_SCOPE_HPP
#define HELPERS_SCOPE_HPP

class transformation;

class scope
{
public:
	scope(const transformation& composition);
	~scope();
};

#endif //HELPERS_SCOPE_HPP
