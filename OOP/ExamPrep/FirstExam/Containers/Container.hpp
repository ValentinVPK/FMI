#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#endif

#pragma once

template<typename T>
class Container {
protected:
	T* arr;
	int arrSize;
	int lastIndex;
public:
	bool member(const T& element) const;
	virtual bool add(const T& element) = 0;
	bool remove(const T& element);
	int size() const;
	T& operator [] (int i);
	virtual ~Container() = default;

	void print() const;
};

template<typename T>
inline bool Container<T>::member(const T& element) const
{
	for (int i = 0; i < lastIndex; i++)
	{
		if (this->arr[i] == element) 
		{
			return true;
		}
	}

	return false;
}

template<typename T>
inline bool Container<T>::remove(const T& element)
{
	T* tempArr = new T[this->lastIndex];
	for (int i = 0; i < this->lastIndex; i++)
	{
		if (this->arr[i] == element)
		{
			for (int j = i; j < this->lastIndex - 1; j++)
			{
				tempArr[j] = this->arr[j + 1];
			}

			for (int t = 0; t < this->lastIndex - 1; t++)
			{
				this->arr[t] = tempArr[t];
			}

			delete[] tempArr;
			this->lastIndex--;
			return true;
		}

		tempArr[i] = this->arr[i];
	}

	delete[] tempArr;
	return false;
}

template<typename T>
inline int Container<T>::size() const
{
	return this->lastIndex;
}

template<typename T>
inline T& Container<T>::operator[](int i)
{
	return this->arr[i]; // Could change;
}

template<typename T>
inline void Container<T>::print() const
{
	for (int i = 0; i < this->lastIndex; i++)
	{
		cout << this->arr[i] << " ";
	}
	cout << endl;
}
