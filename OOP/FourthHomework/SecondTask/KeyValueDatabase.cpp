#include "KeyValueDatabase.hpp"

KeyValueDatabase::KeyValueDatabase(const string& name, const string& location, const string& extension)
	:Object(name, location, extension)
{
}

void KeyValueDatabase::add_entry(const pair<string, int>& entry)
{
	for (auto pair : dictionary)
	{
		if (pair.first == entry.first) 
		{
			throw invalid_argument("Key already exists");
		}
	}

	this->dictionary.push_back(entry);
}

int KeyValueDatabase::get_value(const string& key) const
{
	for (auto pair : dictionary)
	{
		if (pair.first == key) 
		{
			return pair.second;
		}
	}

	throw invalid_argument("Key is not found!");
}

Object* KeyValueDatabase::clone() const
{
	return new KeyValueDatabase(*this);
}

string KeyValueDatabase::to_string() const
{
	stringstream ss;
	ss << this->name << "\n" << this->location << "\n" << this->extension << "\n";

	for (auto pair : dictionary)
	{
		ss << pair.first << ":" << pair.second << "\n";
	}

	return ss.str();
}

void KeyValueDatabase::from_string(const string& str)
{
	stringstream ss(str);
	this->dictionary.clear();

	string to;

	getline(ss, to);
	this->name = to;

	getline(ss, to);
	this->location = to;

	getline(ss, to);
	this->extension = to;

	string delimiter = ":";
	while (getline(ss, to)) 
	{
		string key;
		key = to.substr(0, to.find(delimiter));

		string valueStr;
		valueStr = to.substr(to.find(delimiter) + 1, to.size() - 1);

		stringstream ssTmp(valueStr);   // Needed to convert string to int;
		int valueInt;
		ssTmp >> valueInt;

		this->dictionary.push_back(pair<string, int>(key, valueInt));
	}
}

bool KeyValueDatabase::operator==(const Comparable* rhs) const
{
	KeyValueDatabase* keyValueDatabase = dynamic_cast<KeyValueDatabase*>(const_cast<Comparable*>(rhs));
	if (this->dictionary.size() != keyValueDatabase->dictionary.size()) 
	{
		return false;
	}

	for (size_t i = 0; i < this->dictionary.size(); i++)
	{
		if (this->dictionary[i] != keyValueDatabase->dictionary[i]) 
		{
			return false;
		}
	}

	return true;
}

bool KeyValueDatabase::operator!=(const Comparable* rhs) const
{
	KeyValueDatabase* keyValueDatabase = dynamic_cast<KeyValueDatabase*>(const_cast<Comparable*>(rhs));
	if (this->dictionary.size() != keyValueDatabase->dictionary.size())
	{
		return true;
	}

	for (size_t i = 0; i < this->dictionary.size(); i++)
	{
		if (this->dictionary[i] != keyValueDatabase->dictionary[i])
		{
			return true;
		}
	}

	return false;
}

string KeyValueDatabase::debug_print() const
{
	stringstream ss;

	for (auto pair : dictionary)
	{
		ss << "{" << pair.first << ":" << pair.second << '}' << "\n";
	}

	return ss.str();
}
