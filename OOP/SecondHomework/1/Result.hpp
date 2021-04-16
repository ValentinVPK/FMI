#pragma once

// Add whatever else is required to exist in or out the class
// as well as whatever you think is good to be declared too

#include "Error.hpp"
#include "Optional.hpp"

template<typename T>
class Result {
private:
    Optional<T> optional_result;
    Optional<Error> optional_error;
public:
    Result();
    Result(const T& result);
    Result(const std::string& error_message);

    Optional<T> get_result() const;
    Optional<Error> get_error() const;
    
    bool has_Error() const;

    bool operator== (const T& rhs);
    bool operator== (const Error& rhs);
};

template<typename T>
inline Result<T>::Result()
{
    this->optional_result = Optional<T>();
    this->optional_error = Optional<Error>();
}

template<typename T>
inline Result<T>::Result(const T& result)
{
    this->optional_result = Optional<T>(result);
    this->optional_error = Optional<Error>();
}

template<typename T>
inline Result<T>::Result(const std::string& error_message)
{
    this->optional_result = Optional<T>();
    this->optional_error = Optional<Error>(Error(error_message));
}

template<typename T>
inline Optional<T> Result<T>::get_result() const
{
    return this->optional_result;
}

template<typename T>
inline Optional<Error> Result<T>::get_error() const
{
    return this->optional_error;
}

template<typename T>
bool Result<T>::has_Error() const
{
    return !optional_error.is_none();
}

template<typename T>
inline bool Result<T>::operator==(const Error& rhs)
{
    if (this->has_Error())
    {
        return true;
    }

    return false;
}

template<typename T>
inline bool Result<T>::operator==(const T& rhs)
{
    if (this->has_Error())
    {
       return false;
    }
   
    return true;
}




//template<typename T>
//bool operator==(const Result<T>& lhs, const T& rhs) 
//{
//    if (lhs.has_Error()) 
//    {
//        return false;
//    }
//
//    return true;
//}
//
//template<typename T>
//bool operator==(const Result<T>& lhs, const Error& rhs) 
//{
//    if (lhs.has_Error())
//    {
//        return true;
//    }
//
//    return false;
//}