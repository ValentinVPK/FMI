#pragma once
#include "ProtectedValue.hpp"
#include <iostream>

template<typename T>
class ProtectedArray {
private:
	ProtectedValue<T>* arr;
	size_t size = 0;
public:
	ProtectedArray();
	ProtectedArray(const ProtectedArray<T>& rhs);
	ProtectedArray<T>& operator=(const ProtectedArray<T>& rhs);
	~ProtectedArray();

	void add(const ProtectedValue<T>& value);

	ProtectedValue<T>& getProtectedValue(const size_t& index, const size_t& code);
};

template<typename T>
inline ProtectedArray<T>::ProtectedArray()
{
	this->arr = nullptr;
}

template<typename T>
inline ProtectedArray<T>::ProtectedArray(const ProtectedArray<T>& rhs)
{
	this->arr = new ProtectedValue<T>[rhs.size];
	this->size = rhs.size;
	for (size_t i = 0; i < size; i++)
	{
		this->arr[i] = rhs.arr[i];
	}
}

template<typename T>
inline ProtectedArray<T>& ProtectedArray<T>::operator=(const ProtectedArray<T>& rhs)
{
	if (this != &rhs) 
	{
		delete[] this->arr;
		this->arr = new ProtectedValue<T>[rhs.size];
		this->size = rhs.size;
		for (size_t i = 0; i < size; i++)
		{
			this->arr[i] = rhs.arr[i];
		}
	}

	return *this;
}

template<typename T>
inline ProtectedArray<T>::~ProtectedArray()
{
	delete[] this->arr;
}

template<typename T>
inline void ProtectedArray<T>::add(const ProtectedValue<T>& value)
{
	ProtectedValue<T>* tempArr = new ProtectedValue<T>[this->size];
	for (size_t i = 0; i < this->size; i++)
	{
		tempArr[i] = this->arr[i];
	}

	delete[] this->arr;
	this->arr = new ProtectedValue<T>[this->size + 1];

	for (size_t i = 0; i < this->size - 1; i++)
	{
		this->arr[i] = tempArr[i];
	}

	this->arr[this->size - 1] = value;

	delete[] tempArr;
}

template<typename T>
inline ProtectedValue<T>& ProtectedArray<T>::getProtectedValue(const size_t& index, const size_t& code)
{
	if (this->arr[index].code == code) 
	{
		return this->arr[index];
	}

	std::cout << "Wrong code!";
	return ProtectedValue<T>();
}
