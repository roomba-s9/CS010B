#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Date {
 private:
   unsigned day;
   unsigned month;
   string monthName;
   unsigned year;

 public:
   // creates the date January 1st, 2000.
   Date();

   /* parameterized constructor: month number, day, year 
       - e.g. (3, 1, 2010) will construct the date March 1st, 2010

       If any of the arguments are invalid (e.g. 15 for month or 32 for day)
       then the constructor will construct instead a valid Date as close
       as possible to the arguments provided - e.g. in above example,
       Date(15, 32, 2010), the Date would be corrected to Dec 31st, 2010.
       In case of such invalid input, the constructor will issue a console error message: 

       Invalid date values: Date corrected to 12/31/2010.
       (with a newline at the end).
   */
   Date(unsigned m, unsigned d, unsigned y);


   /* parameterized constructor: month name, day, year
      - e.g. (December, 15, 2012) will construct the date December 15th, 2012

       If the constructor is unable to recognize the string argument as a valid month name,
       then it will issue a console error message: 

       Invalid month name: the Date was set to 1/1/2000.
       (with a newline at the end).
 
       If the day argument is invalid for the given month (but the month name was valid),
       then the constructor will handle this error in the same manner as the other
       parameterized constructor. 

       This constructor will recognize both "december" and "December"
       as month name.
   */
   Date(const string &mn, unsigned d, unsigned y);


   /* Outputs to the console (cout) a Date exactly in the format "3/15/2012". 
      Does not output a newline at the end.
   */
   void printNumeric() const;


   /* Outputs to the console (cout) a Date exactly in the format "March 15, 2012".
      The first letter of the month name is upper case, and the month name is
      printed in full - January, not Jan, jan, or january. 
      Does not output a newline at the end.
   */
   void printAlpha() const;

 private:

   /* Returns true if the year passed in is a leap year, otherwise returns false.
   */
   bool isLeap(unsigned y) const;


   /* Returns number of days allowed in a given month
      -  e.g. daysPerMonth(9, 2000) returns 30.
      Calculates February's days for leap and non-leap years,
      thus, the reason year is also a parameter.
   */
   unsigned daysPerMonth(unsigned m, unsigned y) const;

   /* Returns the name of a given month
      - e.g. name(12) returns the string "December"
   */
   string name(unsigned m) const;

   /* Returns the number of a given named month
      - e.g. number("March") returns 3
   */
   unsigned number(const string &mn) const;
};


// Implement the Date member functions here

   // Public functions
Date::Date() {
   day = 1;
   month = 1;
   monthName = "January";
   year = 2000;
}

Date::Date(unsigned m, unsigned d, unsigned y) {
   bool monthCorrected = false;
   bool dayCorrected = false;
   year = y;
   month = m;
   day = d;
   monthName = name(m);
   if (m < 1) {
      m = 1;
      month = 1;
      monthName = "January";
      monthCorrected = true;
   }
   if (m > 12) {
      m = 12;
      month = 12;
      monthName = "December";
      monthCorrected = true;
   }
   unsigned maxDays = daysPerMonth(m, y);
   if (d < 1) {
      d = 1;
      day = 1;
      dayCorrected = true;
   }
   if (d > maxDays) {
      d = maxDays;
      day = maxDays;
      dayCorrected = true;
   }
   if (monthCorrected || dayCorrected) {
      cout << "Invalid date values: Date corrected to ";
      cout << month << '/' << day << '/' << year << '.' << endl;
   }
}

Date::Date(const string &mn, unsigned d, unsigned y) {
   unsigned m = number(mn);
   bool monthCorrected = false;
   bool dayCorrected = false;
   year = y;
   month = m;
   day = d;
   monthName = name(m);
   if (m < 1) {
      m = 1;
      month = 1;
      monthName = "January";
      monthCorrected = true;
   }
   if (m > 12) {
      m = 12;
      month = 12;
      monthName = "December";
      monthCorrected = true;
   }
   unsigned maxDays = daysPerMonth(m, y);
   if (d < 1) {
      d = 1;
      day = 1;
      dayCorrected = true;
   }
   if (d > maxDays) {
      d = maxDays;
      day = maxDays;
      dayCorrected = true;
   }
   if (dayCorrected && !monthCorrected) {
      cout << "Invalid date values: Date corrected to ";
      cout << month << '/' << day << '/' << year << '.' << endl;
   }
   if (monthCorrected) {
      cout << "Invalid month name: the Date was set to 1/1/2000." << endl;
      year = 2000;
      month = 1;
      day = 1;
      monthName = name(1);
   }

}

void Date::printNumeric() const {
   cout << month << '/' << day << '/' << year;
}

void Date::printAlpha() const {
   cout << monthName << ' ' << day << ", " << year;
}

   // Private functions

/*

isLeap: The rule for whether a year is a leap year is:

(year % 4 == 0) implies leap year
except (year % 100 == 0) implies NOT leap year
except (year % 400 == 0) implies leap year

So, for instance, year 2000 is a leap year, but 1900 is
NOT a leap year. Years 2004, 2008, 2012, 2016, etc. are
all leap years. Years 2005, 2006, 2007, 2009, 2010, etc.
are NOT leap years.

*/

bool Date::isLeap(unsigned y) const {
   bool isLeap = false;
   if (y % 4 == 0) {
      isLeap = true;
   }
   if (y % 100 == 0) {
      isLeap = false;
      if (y % 400 == 0) {
         isLeap = true;
      }
   }
   return isLeap;
}

unsigned Date::daysPerMonth(unsigned m, unsigned y) const {
   int days = 1;

   if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) {
      days = 31;
   } else {
      days = 30;
   }
   if (m == 2) {
      days = 28;
   }

   if (isLeap(y)) {
      if (m == 2) {
         days = 29;
      }
   }
   
   return days;
}

string Date::name(unsigned m) const {
   if (m == 1) return "January";
   if (m == 2) return "February";
   if (m == 3) return "March";
   if (m == 4) return "April";
   if (m == 5) return "May";
   if (m == 6) return "June";
   if (m == 7) return "July";
   if (m == 8) return "August";
   if (m == 9) return "September";
   if (m == 10) return "October";
   if (m == 11) return "November";
   if (m == 12) return "December";
   else return "uh oh";
}

unsigned Date::number(const string &mn) const {
   string temp = "";
   for (auto x : mn) {
      temp.push_back(tolower(x));
   }
   if (temp == "january") return 1;
   if (temp == "february") return 2;
   if (temp == "march") return 3;
   if (temp == "april") return 4;
   if (temp == "may") return 5;
   if (temp == "june") return 6;
   if (temp == "july") return 7;
   if (temp == "august") return 8; 
   if (temp == "september") return 9;
   if (temp == "october") return 10;
   if (temp == "november") return 11;
   if (temp == "december") return 12;
   else return 1000000000;
}

// Don't change the code below this line.
// You may comment them out if you want to build your own test harness
// while in developer mode, but you will need these to pass tests in submit mode.

Date getDate();

int main() {
   Date testDate;
   testDate = getDate();
   cout << endl;
   cout << "Numeric: ";
   testDate.printNumeric();
   cout << endl;
   cout << "Alpha:   ";
   testDate.printAlpha();
   cout << endl;
   
   return 0;
}

Date getDate() {
   int choice;
   unsigned monthNumber, day, year;
   string monthName;

   cout << "Which Date constructor? (Enter 1, 2, or 3)" << endl
      << "1 - Month Number" << endl
      << "2 - Month Name" << endl
      << "3 - default" << endl;
   cin >> choice;
   cout << endl;

   if (choice == 1) {
      cout << "month number? ";
      cin >> monthNumber;
      cout << endl;
      cout << "day? ";
      cin >> day;
      cout << endl;
      cout << "year? ";
      cin >> year;
      cout << endl;
      return Date(monthNumber, day, year);
   } else if (choice == 2) {
      cout << "month name? ";
      cin >> monthName;
      cout << endl;
      cout << "day? ";
      cin >> day;
      cout << endl;
      cout << "year? ";
      cin >> year;
      cout << endl;
      return Date(monthName, day, year);
   } else {
      return Date();
   }
  //return -1;
}
