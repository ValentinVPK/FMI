#pragma once
#include "NamedObject.hpp"


template<typename T>
class NamedObjectArray {
private:
	NamedObject<T>* arr = nullptr;
	size_t size;
public:
	NamedObjectArray();
	NamedObjectArray(const NamedObjectArray<T>& rhs);
	NamedObjectArray<T>& operator=(const NamedObjectArray<T>& rhs);
	~NamedObjectArray();


	void add(const NamedObject<T>& namedObject);
	size_t get_size() const;

	NamedObject<T>& operator[](const int index);
	
};

template<typename T>
inline NamedObjectArray<T>::NamedObjectArray()
	:size(0)
{
}

template<typename T>
inline NamedObjectArray<T>::NamedObjectArray(const NamedObjectArray<T>& rhs)
{
	this->size = rhs.size;
	this->arr = new NamedObject<T>[this->size];

	for (size_t i = 0; i < this->size; i++)
	{
		this->arr[i] = rhs.arr[i];
	}
}

template<typename T>
inline NamedObjectArray<T>& NamedObjectArray<T>::operator=(const NamedObjectArray<T>& rhs)
{
	if (this != &rhs) {
		delete[] this->arr;
		this->size = rhs.size;
		this->arr = new NamedObject<T>[this->size];

		for (size_t i = 0; i < this->size; i++)
		{
			this->arr[i] = rhs.arr[i];
		}
	}

	return *this;
}

template<typename T>
inline NamedObjectArray<T>::~NamedObjectArray()
{
	delete[] this->arr;
}

template<typename T>
inline void NamedObjectArray<T>::add(const NamedObject<T>& namedObject)
{
	NamedObject<T>* tempArr = new NamedObject<T>[this->size];

	for (size_t i = 0; i < this->size; i++)
	{
		tempArr[i] = this->arr[i];
	}

	delete[] this->arr;

	this->size++;
	this->arr = new NamedObject<T>[this->size];

	for (size_t i = 0; i < this->size - 1; i++)
	{
		this->arr[i] = tempArr[i];
	}

	this->arr[this->size - 1] = namedObject;

	delete[] tempArr;
}

template<typename T>
inline size_t NamedObjectArray<T>::get_size() const
{
	return this->size;
}

template<typename T>
inline NamedObject<T>& NamedObjectArray<T>::operator[](const int index)
{
	if (index < 0 || index >= this->size) {
		throw std::out_of_range("Invalid index!");
	}

	return this->arr[index];
}
