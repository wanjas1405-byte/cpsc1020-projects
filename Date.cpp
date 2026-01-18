#include "Date.h"
#include <iostream>
using namespace std;
// Jason Wan
// 9/7/25
// Date.cpp
//
// Purpose: Define the Date class functions
// Steps: create dates, set/get values, add days, show date

// Default constructor sets 01/01/2023
Date::Date(int d, int m, int y) : day(d), month(m), year(y) {}

// Check leap year
bool Date::isLeapYear() const {
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

// Setters


bool Date::setDay(int d) {
    int maxDay;

    if (month == 2) {
        maxDay = isLeapYear() ? 29 : 28;
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        maxDay = 30;
    } else {
        maxDay = 31;
    }

    if (d >= 1 && d <= maxDay) {
        day = d;
        return true;
    }
    return false;
}

bool Date::setMonth(int m) {
    if (m >= 1 && m <= 12) {
        month = m;
        return true;
    }
    return false;
}

bool Date::setYear(int y) {
    if (y == 2023 || y == 2024) { // matches your assignment range
        year = y;
        return true;
    }
    return false;
}

// Getters

int Date::getDay() const { return day; }
int Date::getMonth() const { return month; }
int Date::getYear() const { return year; }

void Date::addDays(int d) {
    day += d;
    while (true) {
    int maxDay;
    if (month == 2)
        maxDay = isLeapYear() ? 29 : 28;
    else if (month == 4 || month == 6 || month == 9 || month == 11)
        maxDay = 30;
    else
        maxDay = 31;

    if (day <= maxDay) break;

        day -= maxDay;
        month++;
        if (month > 12) {
            month = 1;
            year++;
        }

        
    }
}

// Show date
void Date::showDate() const {
    if (month < 10) cout << "0";
    cout << month << "/";

    if (day < 10) cout << "0";
    cout << day << "/";

    cout << year << endl;
}