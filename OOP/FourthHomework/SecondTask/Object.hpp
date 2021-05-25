#pragma once
#include <string>
#include "Comparable.hpp"
#include "Debug.hpp"
#include "Serializable.hpp"
using namespace std;

class Object : public Comparable, public Debug, public Serializable {
protected:
    string name;
    string location;
    string extension;
public:
    Object(const string& name = "", const string& location = "", 
        const string& extension = "");

    string get_name() const;

    string get_location() const;

    string get_extension() const;

    string get_fullpath() const;

    virtual Object* clone() const = 0; 

    virtual ~Object();
};
