#include "Document.hpp"

Document::Document(const string& name, const string& location, const string& extension)
	:Object(name,location,extension), currLine(1)
{

}

void Document::write_line(const string& line)
{
	this->lines.push_back(line);

	ofstream out(this->name, ios::ate);

	if (out.is_open()) 
	{
		for (size_t i = 0; i < this->lines.size(); i++)
		{
			if (i == 0) 
			{
				out << lines[i];
			}
			else 
			{
				out << "\n" << lines[i];
			}
		}
	}

	out.close();
}

string Document::read_line()
{
	string result;

	if (this->lines.size() == 0) 
	{
		throw std::out_of_range("Empty file!");
	}

	if (this->currLine - 1 > lines.size() - 1) 
	{
		throw std::out_of_range("No more lines!");
	}

	result = this->lines[currLine - 1];
	currLine++;
	return result;
}

string Document::read_line(const unsigned line)
{
	this->currLine = line;
	return read_line();
}

Object* Document::clone() const
{
	return new Document(*this);
}

string Document::to_string() const
{
	stringstream ss;
	ss << this->name << "\n" << this->location << "\n" << this->extension << "\n";

	for (auto line : lines)
	{
		ss << line << "\n";
	}

	return ss.str();
}

void Document::from_string(const string& str)
{
	this->lines.clear();

	stringstream ss(str);
	string to;

	getline(ss, to);
	this->name = to;

	getline(ss, to);
	this->location = to;

	getline(ss, to);
	this->extension = to;

	while (getline(ss, to)) 
	{
		this->lines.push_back(to);
	}
}

bool Document::operator==(const Comparable* rhs) const
{
	Document* rhsDoc = dynamic_cast<Document*>(const_cast<Comparable*>(rhs));
	if (this->lines.size() != rhsDoc->lines.size()) 
	{
		return false;
	}

	for (size_t i = 0; i < this->lines.size(); i++)
	{
		if (this->lines[i] != rhsDoc->lines[i]) 
		{
			return false;
		}
	}

	return true;
}

bool Document::operator!=(const Comparable* rhs) const
{
	Document* rhsDoc = dynamic_cast<Document*>(const_cast<Comparable*>(rhs));
	if (this->lines.size() != rhsDoc->lines.size())
	{
		return true;
	}

	for (size_t i = 0; i < this->lines.size(); i++)
	{
		if (this->lines[i] != rhsDoc->lines[i])
		{
			return true;
		}
	}

	return false;
}

string Document::debug_print() const
{
	stringstream ss;
	for (size_t i = 0; i < this->lines.size(); i++)
	{
		ss << "Line " << i + 1 << ":" << this->lines[i] << "\n";
	}

	return ss.str();
}
