/**
* Solution to homework assignment 1
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021
*
* @author Valentin Krumov
* @idnumber 62539
* @task 1
* @compiler VC
*/
#include "Date.hpp"

int main()
{
    Date d1(31, 3, 2014);
    Date d2;
    d1.addDays(1);
    d1.printDate();
    d1.removeDays(1);
    d1.printDate();

    cout << d1.daysToXmas() << endl;
    cout << d1.isLeapYear() << endl;
    cout << d1.isLaterThen(d2) << endl;
}

