#include <iostream>
#include <cmath>
using namespace std;

// Returns the number of days that Gregorian calendar has diverged from Julian calendar up to the given year.
int secularDiff(int year)
{
    return floor(year / 100) - floor(year / 400) - 2;
}

/**
 * @brief Convert Date Time to Julian Day Number.
 * @param year The year of the date.
 * @param month The month of the date.
 * @param date The day of the date.
 * @param ct The calendar type. ct = 0 for Julian, ct = 1 for British, and ct = 2 for Gregorian.
 * @return The Julian Day Number of the given date.
 */
int toJdn(int year, int month, int date, int ct)
{
    int df = secularDiff(year);
    int a = (month - 3) / 12;
    int x4 = year + a;
    int x3 = floor(x4 / 100);
    int x2 = x4 % 100;
    int x1 = month - 12 * a - 3;
    int _jdn = floor((146097 * x3) / 4) +
               floor((36525 * x2) / 100) +
               floor((153 * x1 + 2) / 5) +
               date +
               1721119;
    return ct == 0 || (ct == 1 && _jdn < 2361222) ? _jdn + df : _jdn;
}

/**
 * @brief Test program to verify the toJdn() function.
 *
 * Reads 4 integers from standard input: a year, month, day, and calendar type.
 * Outputs the Julian Day Number of the given date according to the given calendar type.
 */
int main()
{
    int y, m, d, ct;
    cout << "Year: ";
    cin >> y;
    cout << "Month[1=Jan,...,12=DEC]: ";
    cin >> m;
    cout << "Date[1-31]: ";
    cin >> d;
    cout << "Calandar Type(optional)[0 = Julian,1=British,2=Gregorian(default)]: ";
    cin >> ct;
    cout << "Julian Day Number: " << toJdn(y, m, d, ct);
    return 0;
}