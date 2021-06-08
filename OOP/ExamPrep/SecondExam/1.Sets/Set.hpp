#pragma once
#include <iostream>
using namespace std;

template <typename T>
class Set;

template <typename T>
Set<T> unioon(const Set<T>& set1, const Set<T>& set2);

template <typename T>
Set<T> intersection(const Set<T>& set1, const Set<T>& set2);

template<typename T>
class Set {
private:
	T* arr;
	size_t arrSize = 0;
	T* createCopyArr() const;
public:
	Set();
	Set(const Set<T>& rhs);
	Set<T>& operator=(const Set<T>& rhs);
	~Set();


	void insert(const T& element);
	void erase(const T& element);
	bool contains(const T& element) const;
	size_t size() const;

	T& operator[](const size_t& index);
	void setSize(const size_t& size);
	void print() const;

	friend Set<T> unioon<T>(const Set<T>& set1, const Set<T>& set2);
	friend Set<T> intersection<T>(const Set<T>& set1, const Set<T>& set2);
};

template<typename T>
inline T* Set<T>::createCopyArr() const
{
	T* tempArr = new T[this->arrSize];
	for (size_t i = 0; i < this->arrSize; i++)
	{
		tempArr[i] = this->arr[i];
	}

	return tempArr;
}

template<typename T>
inline Set<T>::Set()
{
	this->setSize(0);
}

template<typename T>
inline Set<T>::Set(const Set<T>& rhs)
{
	this->setSize(rhs.arrSize);
	for (size_t i = 0; i < rhs.arrSize; i++)
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
		setSize(rhs.arrSize);
		for (size_t i = 0; i < rhs.arrSize; i++)
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
inline void Set<T>::insert(const T& element)
{
	if (!this->contains(element)) 
	{
		T* tempArr = this->createCopyArr();

		delete[] this->arr;
		setSize(this->arrSize + 1);

		for (size_t i = 0; i < this->arrSize - 1; i++)
		{
			this->arr[i] = tempArr[i];
		}
		this->arr[this->arrSize - 1] = element;

		delete[] tempArr;
	}
}

template<typename T>
inline void Set<T>::erase(const T& element)
{
	if (this->contains(element)) 
	{
		T* tempArr = this->createCopyArr(); 

		delete[] this->arr;
		this->setSize(this->arrSize - 1); 

		for (size_t i = 0; i < this->arrSize + 1; i++)
		{
			if (tempArr[i] == element) 
			{
				for (size_t j = i; j < this->arrSize; j++)
				{
					this->arr[j] == tempArr[j + 1];
				}

				delete[] tempArr;
				return;
			}

			this->arr[i] = tempArr[i];
		}
	}
}

template<typename T>
inline bool Set<T>::contains(const T& element) const
{
	for (size_t i = 0; i < this->arrSize; i++)
	{
		if (this->arr[i] == element) 
		{
			return true;
		}
	}

	return false;
}

template<typename T>
inline size_t Set<T>::size() const
{
	return this->arrSize;
}

template<typename T>
inline T& Set<T>::operator[](const size_t& index)
{
	return this->arr[index];
}

template<typename T>
inline void Set<T>::setSize(const size_t& size)
{
	this->arr = new T[size];
	this->arrSize = size;
}

template<typename T>
inline void Set<T>::print() const
{
	for (size_t i = 0; i < this->arrSize; i++)
	{
		cout << this->arr[i] << " ";
	}
	cout << endl;
}


template<typename T>
Set<T> unioon(const Set<T>& set1, const Set<T>& set2)
{
	Set<T> newSet;
	for (size_t i = 0; i < set1.arrSize; i++)
	{
		newSet.insert(set1.arr[i]);
	}

	for (size_t i = 0; i < set2.arrSize; i++)
	{
		newSet.insert(set2.arr[i]);
	}

	return newSet;
}

template<typename T>
Set<T> intersection(const Set<T>& set1, const Set<T>& set2)
{
	Set<T> newSet;
	for (size_t i = 0; i < set1.arrSize; i++)
	{
		if (set2.contains(set1.arr[i])) 
		{
			newSet.insert(set1.arr[i]);
		}
	}

	return newSet;
}