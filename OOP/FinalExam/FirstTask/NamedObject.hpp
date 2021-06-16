#pragma once
#include <cstring>

template<typename T>
class NamedObject {
private:
	size_t id;
	char* name;
	T object;
public:
	NamedObject(const size_t id = 0, const char* name = "" , const T& object = T());
	NamedObject(const NamedObject<T>& rhs);
	NamedObject<T>& operator=(const NamedObject<T>& rhs);
	~NamedObject();

	size_t get_id() const;
	char* get_name() const;
	T get_object() const;

	// There's no setters in this class because the values of the fields must not be changed after NamedObject is created;
};

template<typename T>
inline NamedObject<T>::NamedObject(const size_t id, const char* name, const T& object)
{
	this->id = id;
	this->object = object;
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);

}

template<typename T>
inline NamedObject<T>::NamedObject(const NamedObject<T>& rhs)
{
	this->id = rhs.id;
	this->object = rhs.object;
	this->name = new char[strlen(rhs.name) + 1];
	strcpy(this->name, rhs.name);
}

template<typename T>
inline NamedObject<T>& NamedObject<T>::operator=(const NamedObject<T>& rhs)
{
	if (this != &rhs) {
		delete[] this->name;
		this->name = new char[strlen(rhs.name) + 1];
		strcpy(this->name, rhs.name);

		this->id = rhs.id;
		this->object = rhs.object;
	}

	return *this;
}

template<typename T>
inline NamedObject<T>::~NamedObject()
{
	delete[] this->name;
}

template<typename T>
inline size_t NamedObject<T>::get_id() const
{
	return this->id;
}

template<typename T>
inline char* NamedObject<T>::get_name() const
{
	return this->name;
}

template<typename T>
inline T NamedObject<T>::get_object() const
{
	return this->object;
}
