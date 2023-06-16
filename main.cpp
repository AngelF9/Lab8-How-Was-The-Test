/**
Interactive way to run the functions implemented in calendar.cpp
Do not change anything in this file.

@file main.cpp
@author Hong Tai Wei
*/

#include <iostream>
#include "calendar.h"
using namespace std;

// Prints a prompt and returns a user's int input.
int get_input(string var) {
  int x;
  cout << "Enter a value for " << var << ":" << endl;
  cin >> x;
  return x;
}

// Gives calendar information based on user input.
int main() {
  while (true) {
    cout << "Enter an operation (info, until, help, quit):" << endl;
    string op;
    cin >> op;

    if (op == "info") {
      int year = get_input("year");
      int month = get_input("month");
      int day = get_input("day");
      if (is_valid_date(year, month, day)) {
        cout << "You've entered a valid date." << endl;
      } else {
        cout << "You've entered an invalid date. The rest of this info may not "
                "be accurate."
             << endl;
      }
      if (is_leap_year(year)) {
        cout << "Year " << year << " is a leap year ";
      } else {
        cout << "Year " << year << " is not a leap year ";
      }
      cout << "and it contains " << num_days(year) << " days." << endl;
      cout << "Year " << year << " month " << month << " contains "
           << num_days(year, month) << " days." << endl;
      cout << "The date you entered is the " << day_of_year(year, month, day)
           << "th day of the year and it's been "
           << days_since_beginning(year, month, day)
           << " days since year 1 month 1 day 1." << endl;
    } else if (op == "until") {
      int y1 = get_input("y1");
      int m1 = get_input("m1");
      int d1 = get_input("d1");
      int y2 = get_input("y2");
      int m2 = get_input("m2");
      int d2 = get_input("d2");
      int until = days_until(y1, m1, d1, y2, m2, d2);
      if (until == -1) {
        cout << "Either at least one of the dates are invalid or the second "
                "date is before the first date."
             << endl;
      } else {
        cout << "The second date is " << until << " days after the first date."
             << endl;
      }
    } else if (op == "quit") {
      cout << "Goodbye!" << endl;
      break;
    } else if (op == "help") {
      cout << "info: prints info regarding a date" << endl;
      cout << "until: prints how many days there are between an earlier date "
              "and a later date."
           << endl;
      cout << "help: displays this help message" << endl;
      cout << "quit: quits this program" << endl;
    } else {
      cout << "Invalid operation. Try again." << endl;
    }
  }
  return 0;
}
