#include <iostream>
#include <string>
#include <iomanip>

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

int main(int argc, char *argv[])
{
     showAdminOptions();
     string adminOption;
     cin >> adminOption;
     while (1)
     {
          if (
              adminOption.compare("0") == 0 || adminOption.compare("1") == 0 ||
              adminOption.compare("2") == 0 || adminOption.compare("3") == 0)
          {
               break;
          }
          else
          {
               cout << "Invalid option. Try again." << endl;
               showAdminOptions();
               cin >> adminOption;
          }
     }
}
