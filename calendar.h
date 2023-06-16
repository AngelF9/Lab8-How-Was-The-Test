/** Header file for calendar.cpp. Do not alter this file.
@file calendar.h
@author Hong Tai Wei
*/

#include <iostream>

#ifndef CALENDAR_H
#define CALENDAR_H

// Returns whether the given year is a leap year.
bool is_leap_year(int year);

// Returns the number of days that the given year contains.
int num_days(int year);

// Returns the number of days that the given month contains.
int num_days(int year, int month);

// Returns whether the given date is valid.
// The year has to be between 1 and 9999.
// The month has to be between 1 and 12.
// The day can't be greater than the number of days that month has.
bool is_valid_date(int year, int month, int day);

// Returns which day of the year the given date corresponds to.
// If the given date is invalid, returns -1.
int day_of_year(int year, int month, int day);

// Returns how many days it's been since year 1 month 1 day 1.
// If the given date is invalid, returns -1.
int days_since_beginning(int year, int month, int day);

// Returns how many days are between the two dates.
// If any of the dates are invalid, returns -1.
// If the second date is before the first date, returns -1.
int days_until(int y1, int m1, int d1, int y2, int m2, int d2);

#endif  // CALENDAR_H
