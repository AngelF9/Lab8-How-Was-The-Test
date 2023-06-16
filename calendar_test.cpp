/** Tests for calendar related functions.
@file calendar_test.cpp
@author Angel Fuentes
*/

#include "calendar.h"
#include <gtest/gtest.h>
using namespace std;

TEST(CalendarTest, IsLeapYear) {
  EXPECT_FALSE(is_leap_year(2021));
  EXPECT_TRUE(is_leap_year(2020));
  EXPECT_FALSE(is_leap_year(2100));
  EXPECT_TRUE(is_leap_year(2000));
}

TEST(CalendarTest, NumDaysYear) {
  EXPECT_EQ(num_days(2021), 365);
  EXPECT_EQ(num_days(2020), 366);
}

TEST(CalendarTest, NumDaysMonth) {
  EXPECT_EQ(num_days(2021, 1), 31);
  EXPECT_EQ(num_days(2021, 2), 28);
  EXPECT_EQ(num_days(2021, 3), 31);
  EXPECT_EQ(num_days(2021, 4), 30);
  EXPECT_EQ(num_days(2021, 5), 31);
  EXPECT_EQ(num_days(2021, 6), 30);
  EXPECT_EQ(num_days(2021, 7), 31);
  EXPECT_EQ(num_days(2021, 8), 31);
  EXPECT_EQ(num_days(2021, 9), 30);
  EXPECT_EQ(num_days(2021, 10), 31);
  EXPECT_EQ(num_days(2021, 11), 30);
  EXPECT_EQ(num_days(2021, 12), 31);
  EXPECT_EQ(num_days(2020, 2), 29);
}

TEST(CalendarTest, IsValidDate) {
  EXPECT_TRUE(is_valid_date(2021, 10, 11));
  EXPECT_FALSE(is_valid_date(0, 10, 11));
  EXPECT_FALSE(is_valid_date(10000, 10, 11));
  EXPECT_FALSE(is_valid_date(2021, 0, 11));
  EXPECT_FALSE(is_valid_date(2021, 13, 11));
  EXPECT_FALSE(is_valid_date(2021, 10, 0));
  EXPECT_FALSE(is_valid_date(2021, 10, 32));
}

TEST(CalendarTest, DayOfYear) {
  EXPECT_EQ(day_of_year(2021, 10, 11), 284);
  EXPECT_EQ(day_of_year(2021, 1, 1), 1);
  EXPECT_EQ(day_of_year(0, 10, 11), -1);
}

TEST(CalendarTest, DaysSinceBeginning) {
  EXPECT_EQ(days_since_beginning(2021, 10, 11), 738073);
  EXPECT_EQ(days_since_beginning(1, 1, 1), 0);
  EXPECT_EQ(days_since_beginning(0, 10, 11), -1);
}

TEST(CalendarTest, DaysUntil) {
  EXPECT_EQ(days_until(2021, 10, 11, 2021, 10, 18), 7);
  EXPECT_EQ(days_until(2021, 10, 11, 2021, 10, 11), 0);
  EXPECT_EQ(days_until(2021, 10, 11, 2021, 10, 4), -1);
  EXPECT_EQ(days_until(0, 10, 11, 2021, 10, 11), -1);
  EXPECT_EQ(days_until(2021, 10, 11, 0, 10, 11), -1);
}
