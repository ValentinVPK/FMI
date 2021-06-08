#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#endif

#pragma once
#include "Container.hpp"
#include <iostream>
using namespace std;

template<typename T>
class ArrayVector : public Container<T> {
public:
	ArrayVector(const int arrSize = 10);
	ArrayVector(const ArrayVector<T>& rhs);
	ArrayVector<T>& operator=(const ArrayVector<T>& rhs);
	~ArrayVector();

	bool add(const T& element);
};

template<typename T>
inline ArrayVector<T>::ArrayVector(const int arrSize)
{
	this->arrSize = arrSize;
	this->arr = new T[arrSize];
	this->lastIndex = 0;
}

template<typename T>
inline ArrayVector<T>::ArrayVector(const ArrayVector<T>& rhs)
{
	this->arr = new T[rhs.arrSize];
	for (size_t i = 0; i < rhs.lastIndex; i++)
	{
		this->arr[i] = rhs.arr[i];
	}
}

template<typename T>
inline ArrayVector<T>& ArrayVector<T>::operator=(const ArrayVector<T>& rhs)
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
inline ArrayVector<T>::~ArrayVector()
{
	delete[] this->arr;
}

template<typename T>
inline bool ArrayVector<T>::add(const T& element)
{
	if (this->lastIndex == this->arrSize)
	{
		return false;
	}

	this->arr[this->lastIndex] = element;
	this->lastIndex++;

	return true;
}



