#ifndef HELPERS_SCOPE_HPP
#define HELPERS_SCOPE_HPP

class matrix;

//obsluga obszaru obowiazywania macierzy
class matrix_scope
{
public:
	matrix_scope(const matrix& composition);
	~matrix_scope();
};

class list_id;

//obsluga obszaru budowania listy
class list_scope
{
public:
	list_scope(const list_id& id);
	~list_scope();
};

#endif //HELPERS_SCOPE_HPP
