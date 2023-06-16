/** Implementation for calendar related functions.
@file calendar.cpp
@author Angel Fuentes
*/

#include "calendar.h"
#include <iostream>
using namespace std;

bool is_leap_year(int year) {
  return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
}

int num_days(int year) {
  if (is_leap_year(year)) {
    return 366;
  } else {
    return 365;
  }
}

int num_days(int year, int month) {
  switch (month) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
      return 31;
    case 4:
    case 6:
    case 9:
    case 11:
      return 30;
    case 2:
      if (is_leap_year(year)) {
        return 29;
      }
      return 28;
    default:
      return -1;
  }
}

bool is_valid_date(int year, int month, int day) {
  if (year < 1 || year > 9999 || month < 1 || month > 12) {
    return false;
  }
  return day <= num_days(year, month) && day > 0;
}

int day_of_year(int year, int month, int day) {
  if (!is_valid_date(year, month, day)) {
    return -1;
  }
  int result = day;
  for (int i = 1; i < month; i++) {
    result += num_days(year, i);
  }
  return result;
}

int days_since_beginning(int year, int month, int day) {
  if (!is_valid_date(year, month, day)) {
    return -1;
  }
  int result = day_of_year(year, month, day) - 1;
  for (int i = 1; i < year; i++) {
    result += num_days(i);
  }
  return result;
}

int days_until(int y1, int m1, int d1, int y2, int m2, int d2) {
  if (!is_valid_date(y1, m1, d1) || !is_valid_date(y2, m2, d2)) {
    return -1;
  }
  int diff =
      days_since_beginning(y2, m2, d2) - days_since_beginning(y1, m1, d1);
  if (diff < 0) {
    return -1;
  }
  return diff;
}
