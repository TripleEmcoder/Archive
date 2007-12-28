#pragma once

#include <vector>
#include <iterator>

template<class T> class set_vector
{
private:
	std::vector<T>* ref;
	std::vector<bool> set;
	std::vector<T*> vec;
public:
	typedef typename std::vector<T*>::iterator set_vector<T>::iterator;
	typedef typename std::vector<T*>::const_iterator set_vector<T>::const_iterator;
	void reset(std::vector<T>* ref);
	void clear();
	void push_back(int elem);
	size_t size() const;
	typename set_vector<T>::iterator begin();
	typename set_vector<T>::iterator end();
	typename set_vector<T>::const_iterator begin() const;
	typename set_vector<T>::const_iterator end() const;
};

template <class T> void set_vector<T>::reset(std::vector<T>* ref)
{
	this->ref = ref;
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
		vec.push_back(&((*ref)[elem]));
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
