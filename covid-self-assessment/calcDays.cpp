#include "calcDays.h"


// Jason Wan
// 9/7/25
// calcDays.cpp
//
// Purpose: Calculate how many days are between two Date objects
//
// Steps inside the function:
// 1. Get the year, month, day from the first date (startDate)
// 2. Get the year, month, day from the second date (endDate)
// 3. Convert both dates into total days since 01/01/2023
//      - total_days = (years passed * 365) + (months passed * 31) + (days passed)
// 4. Subtract startDate total from endDate total
// 5. Return the difference (number of days between the two dates)

// Return number of days in a given month (handle leap year for February)
int daysInMonth(int month, int year) {
    if (month == 2) {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
            return 29;
        else
            return 28;
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11)
        return 30;
    else
        return 31;
}  

int calcDays(const Date &startDate, const Date &endDate) {
    // Get day, month, year from both dates
    int d1 = startDate.getDay();
    int m1 = startDate.getMonth();
    int y1 = startDate.getYear();

    int d2 = endDate.getDay();
    int m2 = endDate.getMonth();
    int y2 = endDate.getYear();

    // If end date is before start date, swap them
    if (y2 < y1 || (y2 == y1 && m2 < m1) || (y2 == y1 && m2 == m1 && d2 < d1)) {
        int temp;
        temp = d1; d1 = d2; d2 = temp;
        temp = m1; m1 = m2; m2 = temp;
        temp = y1; y1 = y2; y2 = temp;
    }

    int days = 0;

    // Loop until the first date reaches the second date
    while (y1 < y2 || m1 < m2 || d1 < d2) {
        days = days + 1;   // add one day
        d1 = d1 + 1;       // move to next day

        // If day exceeds the days in month, go to next month
        if (d1 > daysInMonth(m1, y1)) {
            d1 = 1;
            m1 = m1 + 1;

            // If month exceeds 12, go to next year
            if (m1 > 12) {
                m1 = 1;
                y1 = y1 + 1;
            }
        }
    }

    return days;
}
