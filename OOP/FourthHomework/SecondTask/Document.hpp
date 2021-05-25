#pragma once
#include <string>
#include "Object.hpp"
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>


class Document : public Object {
private:
    vector<string> lines;
    size_t currLine;
public:
    Document(const string& name, const string& location, const string& extension);

    void write_line(const string& line);

    string read_line();
    string read_line(const unsigned line);

    Object* clone() const override;

    string to_string() const override;
    void from_string(const string& str) override;

    bool operator==(const Comparable* rhs) const override;
    bool operator!=(const Comparable* rhs) const override;

    string debug_print() const override;
};
