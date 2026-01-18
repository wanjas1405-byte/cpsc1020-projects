#ifndef DATE_H
#define DATE_H



// Date class → stores and works with day, month, and year
// ----------------------------------------------------------
// What this class does:
// - keeps track of a date (day, month, year)
// - lets you set and get day/month/year
// - can add a few days to the date
// - can show the date on the screen
// ----------------------------------------------------------

class Date {
    private:
        int day;    // number for day
        int month;  // number for month
        int year;   // number for year
    
    public:
        // Constructors
        // -------------------------
        // Date() → makes default date (01/01/2023)
        // Date(d, m, y) → makes a date using numbers you give it
        Date(int d = 1, int m = 1, int y = 2023);
    
        // Setters (change the values)
        // -------------------------
        // setDay(d) → changes the day if it’s valid (1–31)
        // setMonth(m) → changes the month if it’s valid (1–12)
        // setYear(y) → changes the year if it’s 2023 or 2024
        bool setDay(int d);
        bool setMonth(int m);
        bool setYear(int y);
    
        // Getters (look at the values)
        // -------------------------
        // getDay() → gives back the day
        // getMonth() → gives back the month
        // getYear() → gives back the year
        int getDay() const;
        int getMonth() const;
        int getYear() const;
    
        // Extra functions
        // -------------------------
        // addDays(d) → move the date forward by d days
        // showDate() → print the date to the screen
        void addDays(int d);
        void showDate() const;
        bool isLeapYear() const;
    };
    
    #endif
