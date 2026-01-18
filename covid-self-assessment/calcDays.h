#ifndef CALCDAYS_H
#define CALCDAYS_H
#include "Date.h"

// calcDays function → calculates how many days are between two dates
// ----------------------------------------------------------
// What this function does:
// - Takes two Date objects: startDate and endDate
// - Counts the number of days from startDate to endDate
// - Returns the count as an integer
// ----------------------------------------------------------
// Steps in simple terms:
// 1. Get the day, month, year from both dates
// 2. Convert each date into a total number of days since 01/01/2023
//    (years * 365 + months * 31 + days)
// 3. Subtract startDate total from endDate total
// 4. Return the difference


int calcDays(const Date &startDate, const Date &endDate);

#endif
