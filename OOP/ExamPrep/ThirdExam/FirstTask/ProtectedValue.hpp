#pragma once

template<typename T>
class ProtectedValue {
private:
	T value;
	size_t code;
public:
	ProtectedValue(const T& value = T(), const size_t& code = 0);

	T getValue(const size_t& code) const;

};

template<typename T>
inline ProtectedValue<T>::ProtectedValue(const T& value, const size_t& code)
	:value(value), code(code)
{
}

template<typename T>
inline T ProtectedValue<T>::getValue(const size_t& code) const
{
	if (this->code == code) 
	{
		return this->value;
	}

	return T();
}
