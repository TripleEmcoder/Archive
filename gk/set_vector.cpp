#include "set_vector.hpp"

template <class T> void set_vector<T>::reset(const std::vector<T>& ref)
{
	this->ref = &ref;
	clear();
}

template <class T> void set_vector<T>::clear()
{
	set.assign(ref->size(), false);
	vec.clear();
}

template <class T> void set_vector<T>::push_back(int elem)
{
	if (!set[elem])
	{
		set[elem] = true;
		vec.push_back(&(*ref[elem]));
	}
}

template <class T> size_t set_vector<T>::size() const
{
	return vec.size();
}

template <class T> typename set_vector<T>::iterator set_vector<T>::begin()
{
	return vec.begin();
}

template <class T> typename set_vector<T>::iterator set_vector<T>::end()
{
	return vec.end();
}

template <class T> typename set_vector<T>::const_iterator set_vector<T>::begin() const
{
	return vec.begin();
}

template <class T> typename set_vector<T>::const_iterator set_vector<T>::end() const
{
	return vec.end();
}

