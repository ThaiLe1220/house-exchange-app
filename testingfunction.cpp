// #include "Member.h"
// #include "House.h"
// #include "Request.h"
// #include "Data.h"

#include <vector>
#include <iomanip>
#include <string>
#include <iostream>
#include <ctime>
#include <chrono>

#include <conio.h>
#include <stdlib.h>

using namespace std;

void showLoginOptions()
{
     cout << "\nUse app as 1. Guest, 2. Member or 3.Admin" << endl;
     cout << "Enter user option: ";
}

void showGuestOptions()
{
     cout << "This is your menu: " << endl;
     cout << setw(4) << ""
          << "0. Go Back " << endl;
     cout << setw(4) << ""
          << "1. View All Houses Information (exclude reviews and occupy status)  " << endl;
     cout << setw(4) << ""
          << "2. Register as Member  " << endl;
     cout << "Enter guest option: ";
}
void showMemberOptions()
{
     cout << "This is your menu: " << endl;
     cout << setw(4) << ""
          << "0. Go Back " << endl;
     cout << setw(4) << ""
          << "1. View Account Information  " << endl;
     cout << setw(4) << ""
          << "2. List House for Occupy  " << endl;
     cout << setw(4) << ""
          << "3. Unlist House for Occupy  " << endl;
     cout << setw(4) << ""
          << "4. View Available Houses Information  " << endl;
     cout << setw(4) << ""
          << "5. Request to Occupy House  " << endl;
     cout << setw(4) << ""
          << "6. Rate Occupied House  " << endl;
     cout << setw(4) << ""
          << "7. View All Occupy Request to your House  " << endl;
     cout << setw(4) << ""
          << "8. Response to Occupy Request  " << endl;
     cout << setw(4) << ""
          << "9. Rate Occupant of your House  " << endl;
     cout << setw(4) << ""
          << "10. Register as Member  " << endl;
     cout << "Enter member option: ";
}

void showAdminOptions()
{
     cout << "This is your menu: " << endl;
     cout << setw(4) << ""
          << "0. Go Back " << endl;
     cout << setw(4) << ""
          << "1. View All Member Information  " << endl;
     cout << setw(4) << ""
          << "2. View All House Information   " << endl;
     cout << setw(4) << ""
          << "3. View All Request Information   " << endl;
     // cout << setw(4) << ""
     //      << "4.  " << endl;
     // cout << setw(4) << ""
     //      << "5.  " << endl;
     // cout << setw(4) << ""
     //      << "6.  " << endl;
     // cout << setw(4) << ""
     //      << "7.  " << endl;
     // cout << setw(4) << ""
     //      << "8.  " << endl;
     cout << "Enter admin option: ";
}

// soruce: https://howardhinnant.github.io/date_algorithms.html#days_from_civil
// Returns number of days since civil 1970-01-01.  Negative values indicate days prior to 1970-01-01.
template <class Int>
constexpr Int
days_from_civil(Int y, unsigned m, unsigned d) noexcept
{
     static_assert(std::numeric_limits<unsigned>::digits >= 18,
                   "This algorithm has not been ported to a 16 bit unsigned integer");
     static_assert(std::numeric_limits<Int>::digits >= 20,
                   "This algorithm has not been ported to a 16 bit signed integer");
     y -= m <= 2;
     const Int era = (y >= 0 ? y : y - 399) / 400;
     const unsigned yoe = static_cast<unsigned>(y - era * 400);            // [0, 399]
     const unsigned doy = (153 * (m > 2 ? m - 3 : m + 9) + 2) / 5 + d - 1; // [0, 365]
     const unsigned doe = yoe * 365 + yoe / 4 - yoe / 100 + doy;           // [0, 146096]
     return era * 146097 + static_cast<Int>(doe) - 719468;
}

bool checkLeapYear(int yyyy)
{
     if (yyyy % 400 == 0)
          return true;
     else if (yyyy % 100 != 0 && yyyy % 4 == 0)
          return true;
     else
          return false;
}

bool checkDate(int yyyy, int mm, int dd)
{
     if (yyyy >= 2023)
     {
          if (mm >= 1 && mm <= 12)
          {
               if (mm == 2 && checkLeapYear(yyyy) == false && dd >= 1 && dd <= 28)
                    return true;
               else if (mm == 2 && checkLeapYear(yyyy) == true && dd >= 1 && dd <= 29)
                    return true;
               else if ((mm == 1 || mm == 3 || mm == 5 || mm == 7 || mm == 8 || mm == 10 || mm == 12) && (dd >= 1 && dd <= 31))
                    return true;
               else if ((mm == 4 || mm == 6 || mm == 9 || mm == 11) && (dd >= 1 && dd <= 30))
                    return true;
               else
                    return false;
          }
          else
               return false;
     }
     else
          return false;
}

bool checkStringDate(string date)
{
     int y, m, d;
     for (int i = 0; i < date.size(); i++)
     {
          if (date[i] == '-' && i != 4)
          {
               y = stoi(date.substr(0, 4));
               m = stoi(date.substr(5, i - 5));
               d = stoi(date.substr(i + 1, date.size() - i));
          }
     }
     return checkDate(y, m, d);
}

int countDayDiff(string start, string end)
{
     int ys = stoi(start.substr(0, 4));
     int ms = stoi(start.substr(5, 2));
     int ds = stoi(start.substr(8, 2));
     int ye = stoi(end.substr(0, 4));
     int me = stoi(end.substr(5, 2));
     int de = stoi(end.substr(8, 2));
     return days_from_civil(ye, me, de) - days_from_civil(ys, ms, ds);
}

// g++ testingfunction.cpp Member.cpp House.cpp Data.cpp Admin.cpp Request.cpp -o tf

int main(int argc, char *argv[])
{
     cout << checkStringDate("2023-1-1") << endl;
     cout << checkStringDate("2023-12-31") << endl;

     return 0;
}