#include <iostream>
#include <cmath>

/**
 * @brief Calculate the secular difference between the Gregorian and Julian calendars.
 * @details This is the number of days by which the Gregorian calendar is ahead of the Julian calendar.
 * @param year The year for which to calculate the secular difference.
 * @return The secular difference in days.
 */
int secularDiff(int year)
{
    return floor(year / 100) - floor(year / 400) - 2;
}
/**
 * @brief Calculate the Julian Day Number (JDN) for a given year, month, and day.
 * @details This function calculates the Julian Day Number (JDN) for a given year, month, and day. The JDN is the number of days since the beginning of the Julian period (4713 BC). The secular difference between the Gregorian and Julian calendars is taken into account.
 * @param year The year for which to calculate the JDN.
 * @param month The month for which to calculate the JDN.
 * @param date The day for which to calculate the JDN.
 * @param ct The century type (0 for Gregorian, 1 for Julian).
 * @return The JDN for the given year, month and day.
 */
int jdn(int year, int month, int date, int ct)
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