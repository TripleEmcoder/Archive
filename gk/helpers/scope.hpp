#ifndef HELPERS_SCOPE_HPP
#define HELPERS_SCOPE_HPP

class matrix;

//obsluga obszaru obowiazywania macierzy
class matrix_scope
{
public:
	matrix_scope(const matrix& matrix);
	~matrix_scope();
};

class material;

//obsluga obszaru obowiazywania materialu
class material_scope
{
public:
	material_scope(const material& material);
	~material_scope();
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
