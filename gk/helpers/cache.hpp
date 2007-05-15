#ifndef HELPERS_CACHE_HPP
#define HELPERS_CACHE_HPP

#include <string>
#include <map>

class cache
{
public:
	static int texture(std::string name);

private:
	static std::map<std::string, int> textures;
};

#endif //HELPERS_CACHE_HPP
