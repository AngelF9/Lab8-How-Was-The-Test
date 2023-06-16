# Lab 8: How Was The Test?

In this lab, you will learn how to:
- write unit tests using GoogleTest
- use `make test` to run tests

For this assignment, you will write a series of functions related to dates and leap years, then practice testing them via the GoogleTest framework.

### File structure

* `Makefile` - Configuration for `make`, which you will be using instead of `g++` to compile code today.
* `calendar.cpp` - Your code goes here.
* `calendar_test.cpp` - Your tests go here.
* `calendar.h` - Header file for `calendar.cpp`, already written for you.
* `main.cpp` - Contains main function if you want to run the functions in `calendar.cpp`.

**Do not change any files other than `calendar.cpp` and `calendar_test.cpp`!**

**Changes to any other files will create a giant mess for you and will also be ignored by the autograder.**

### Program requirements

You will be completing the following function implementations in `calendar.cpp` and writing corresponding unit tests in `calendar_test.cpp`.

#### 0. `bool is_leap_year(int year);`
  * Returns whether the given year is a [leap year](https://en.wikipedia.org/wiki/Leap_year).
  * This has already been done for you.
  * Tests for this function have already been written for you.

#### 1. `int num_days(int year);`
  * Returns the number of days that the given year contains.
  * You can assume that the input year will be valid.
  * **Hint**: you may want to call `is_leap_year` somewhere.

#### 2. `int num_days(int year, int month);`
  * Returns the number of days that the given month contains.
  * You can find out how many days are in each month [here](https://www.timeanddate.com/calendar/months/).
  * You can assume that the input year and month will be valid.
  * **Note**: We're allowed to have functions with the same name as long as the input parameters are different.
  * **Hint**: you may want to call `is_leap_year` somewhere.

#### 3. `bool is_valid_date(int year, int month, int day);`
  * Returns whether the given date is valid.
  * For the purpose of this assignment, we will consider a date to be valid if:
    * 1 <= year <= 9999 **and**
    * 1 <= month <= 12 **and**
    * 1 <= day <= however many days that year & month has (28-31)
  * **Hint**: you may want to call `num_days` somewhere.

#### 4. `int day_of_year(int year, int month, int day);`
  * Returns which day of the year the given date corresponds to.
  * If the given date is invalid, returns -1.
  * **Hint**: you may want to call `is_valid_date` and `num_days` somewhere.

#### 5. `int days_since_beginning(int year, int month, int day);`
  * Returns how many days it's been since year 1 month 1 day 1.
  * If the given date is invalid, returns -1.
  * **Hint**: you may want to call `is_valid_date`, `day_of_year` and `num_days` somewhere.

#### 6. `int days_until(int y1, int m1, int d1, int y2, int m2, int d2);`
  * Returns how many days are between the two dates.
  * If any of the dates are invalid, returns -1.
  * If the second date is before the first date, returns -1.
  * **Hint**: you may want to call `is_valid_date` and `days_since_beginning` somewhere.

**Look in `calendar_test.cpp` for example input & ouput pairs!**

### Available make commands

Below are the `make` commands available to you for this lab:
* `make format` - Automatically formats your code to meet the style guidelines.
* `make build` - Compiles all the program files into a program called `calendar` that you can run by typing `./calendar`.
* `make test` - Compiles your tests in `calendar_test.cpp` into a program called `calendar_test` and runs it using the `./calendar_test` command.
* `make all` - Runs all of the above commands, one by one, in order.
* `make clean` - Removes generated files. In this case, `calendar` and `calendar_test`.

### The GoogleTest framework

Open the `calendar_test.cpp` file. These test cases are written using the GoogleTest framework, which is how engineers at Google unit test their c++ code. You can read more about it [here](https://github.com/google/googletest/) if you're curious.

In this file, you should see a number of test cases that look like this:

```c++
TEST(CalendarTest, IsLeapYear)
{
  EXPECT_FALSE(is_leap_year(2021));
  EXPECT_TRUE(is_leap_year(2020));
  EXPECT_FALSE(is_leap_year(2100));
  EXPECT_TRUE(is_leap_year(2000));
}
```

The tests for `is_leap_year` have been written for you already. Each `EXPECT_TRUE` and `EXPECT_FALSE` statement take in a bool argument and verifies that it's equal to `true` or `false`, respectively. For example, `EXPECT_FALSE(is_leap_year(2021));` verifies that if you give `2021` as the input to `is_leap_year`, you should get `false` as the return value. Otherwise, it will fail the test.

You can use the `make test` command to run these tests. If you do that now, you should see something like this in your command line:

```
[ RUN      ] CalendarTest.IsLeapYear
[       OK ] CalendarTest.IsLeapYear (0 ms)
```

This indicates that the tests in this test case all passed. If you look further below, you'll see something like this:

```
[ RUN      ] CalendarTest.NumDaysYear
calendar_test.cpp:19: Failure
Expected equality of these values:
  num_days(2021)
    Which is: -1
  365
[  FAILED  ] CalendarTest.NumDaysYear (0 ms)
```

This is caused by the following test case:

```c++
TEST(CalendarTest, NumDaysYear) {
  EXPECT_EQ(num_days(2021), 365);
  // TODO: Add at least another good test case here.
}
```

`EXPECT_EQ` takes in two arguments and verifies that they are equal to each other. In this case, it's verifying that if you give `2021` as the input to `num_days`, you should get `365` as the return value. Since we haven't written the implementation for `num_days` yet, this test fails as expected.

**TODO**: add in more tests for each of the functions that you implement and make sure they all pass when running `make test`.
