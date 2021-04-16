#pragma once
// Add whatever else is required to exist in or out the class
// as well as whatever you think is good to be declared too

template <typename T>

class Optional {
private:
    bool is_empty;
    T object;
public:
    Optional();
    Optional(const T& value);

    bool is_none() const;
    T get_value() const;
};

template<typename T>
inline Optional<T>::Optional()
{
    this->is_empty = true;
}

template<typename T>
inline Optional<T>::Optional(const T& value)
{
    this->object = value;
    this->is_empty = false;
}

template<typename T>
inline bool Optional<T>::is_none() const
{
    return this->is_empty;
}

template<typename T>
inline T Optional<T>::get_value() const
{
    if (this->is_empty) 
    {
        return T();
    }
    
    return this->object;
}
