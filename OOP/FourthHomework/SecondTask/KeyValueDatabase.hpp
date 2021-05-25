#pragma once
#include "Object.hpp"
#include <vector>
#include <stdexcept>
#include <sstream>

class KeyValueDatabase : public Object {
private:
    vector<pair<string, int>> dictionary;
public:
    KeyValueDatabase(const string& name, const string& location, const string& extension);

    void add_entry(const pair<string, int>& entry);
    int get_value(const string& key) const;

    Object* clone() const override;

    string to_string() const override;
    void from_string(const string& str) override;

    bool operator==(const Comparable* rhs) const override;
    bool operator!=(const Comparable* rhs) const override;

    string debug_print() const override;
};