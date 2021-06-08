#pragma once

#include "Container.hpp"
template<typename T>
class Set : public Container<T> {
	Set(const int arrSize = 10);
	Set(const Set<T>& rhs);
	Set<T>& operator=(const Set<T>& rhs);
	~Set();

	bool add(const T& element);
};

template<typename T>
inline Set<T>::Set(const int arrSize)
{
	this->arrSize = arrSize;
	this->arr = new T[arrSize];
	this->lastIndex = 0;
}

template<typename T>
inline Set<T>::Set(const Set<T>& rhs)
{
	this->arr = new T[rhs.arrSize];
	for (size_t i = 0; i < rhs.lastIndex; i++)
	{
		this->arr[i] = rhs.arr[i];
	}
}

template<typename T>
inline Set<T>& Set<T>::operator=(const Set<T>& rhs)
{
	if (this != &rhs)
	{
		delete[] this->arr;
		this->arr = new T[rhs.arrSize];
		for (size_t i = 0; i < rhs.lastIndex; i++)
		{
			this->arr[i] = rhs.arr[i];
		}
	}

	return *this;
}

template<typename T>
inline Set<T>::~Set()
{
	delete[] this->arr;
}

template<typename T>
inline bool Set<T>::add(const T& element)
{
	if (this->lastIndex == this->arrSize)
	{
		return false;
	}

	for (int i = 0; i < lastIndex; i++)
	{
		if (this->arr[i] == element) 
		{
			return false;
		}
	}

	this->arr[this->lastIndex] = element;
	this->lastIndex++;

	return true;
}


