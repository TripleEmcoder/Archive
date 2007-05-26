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
	void reset(const std::vector<T>& ref);
	void clear();
	void push_back(int elem);
	size_t size() const;
	typename set_vector<T>::iterator begin();
	typename set_vector<T>::iterator end();
	typename set_vector<T>::const_iterator begin() const;
	typename set_vector<T>::const_iterator end() const;
};
