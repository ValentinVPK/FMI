
#include <iostream>
#include "Document.hpp"
#include <sstream>

int main()
{
    Document temp("example", "/example", "doc");

    temp.write_line("This is an example doc");
    temp.write_line("This is another example line");
    temp.write_line("This is a third example line");
    temp.write_line("This is a forth example line");

    cout << temp.read_line() << endl;//This is an example doc
    cout << temp.read_line() << endl;//This is another example line
   
    cout << temp.read_line(3) << endl;//This is a third example line
    cout << temp.read_line() << endl; //This is a forth example line

    cout << temp.read_line(1) << endl; //This is an example doc
    cout << temp.read_line() << endl; //This is another example line

    cout << temp.to_string();
  
}

