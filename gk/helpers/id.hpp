#ifndef HELPERS_ID_HPP
#define HELPERS_ID_HPP

//(de)alokacja identyfikatora tekstury
class texture_id
{
public:
	texture_id();
	~texture_id();
	operator unsigned int() const;

private:
	unsigned int id;
};

//(de)alokacja identyfikatora listy
class list_id
{
public:
	list_id();
	~list_id();
	operator unsigned int() const;

private:
	unsigned int id;
};

#endif //HELPERS_ID_HPP
