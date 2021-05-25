#include "Object.hpp"

Object::Object(const std::string& name, const std::string& location, const std::string& extension)
	:name(name), location(location), extension(extension)
{
}

string Object::get_name() const
{
	return this->name;
}

string Object::get_location() const
{
	return this->location;
}

string Object::get_extension() const
{
	return this->extension;
}

string Object::get_fullpath() const
{
	return this->location + "/" + this->name + "." + this->extension;
}

Object::~Object()
{
}
