
#include "Member.h"
#include "House.h"
#include "Request.h"
#include "Data.h"

#include <vector>
#include <iomanip>
#include <string>
#include <iostream>

// TODO: figure out how to handle the id system of House, Member, and Request

using namespace std;

void showWelcomeScreen()
{
     cout << "EEET2482/COSC2082 ASSIGNMENT\n";
     cout << "VACATION HOUSE EXCHANGE APPLICATION\n";
     cout << "Instructors: Mr. Linh Tran & Phong Ngo\n";
     cout << "Group: Group 28\n";
     cout << "s3824892, Chau Minh Kha\n";
     cout << "s3902460, Nguyen Minh Phu\n";
     cout << "s3752577, Thai Le\n";
     cout << "s3927195, The Anh\n";
     cout << "s3915202, Trinh Viet Quy\n";
     cout << "Welcome to our House Exchange App!\n";
}

void showLoginOptions()
{
     cout << "\nUse app as 1. Guest, 2. Member or 3.Admin\n";
     cout << "Enter user option: ";
}

void showGuestOptions()
{
     cout << "\nThis is your menu:\n";
     cout << setw(4) << ""
          << "0. Go Back\n";
     cout << setw(4) << ""
          << "1. View All Houses Information (exclude reviews and occupy status)\n";
     cout << setw(4) << ""
          << "2. Register as Member\n";
     cout << "Enter guest option: ";
}

void showMemberOptions()
{
     cout << "\nThis is your menu:\n";
     cout << setw(4) << ""
          << "0. Go Back\n";
     cout << setw(4) << ""
          << "1. View Account Information\n";
     cout << setw(4) << ""
          << "2. List House for Occupant \n";
     cout << setw(4) << ""
          << "3. Unlist House for Occupant\n";
     cout << setw(4) << ""
          << "4. View Available Houses to Occupy\n";
     cout << setw(4) << ""
          << "5. Request to Occupy House\n";
     cout << setw(4) << ""
          << "6. Rate Occupied House\n";
     cout << setw(4) << ""
          << "7. View All Occupy Request to your House\n";
     cout << setw(4) << ""
          << "8. Response to Occupy Request\n";
     cout << setw(4) << ""
          << "9. Rate Occupant of your House\n";
     cout << setw(4) << ""
          << "10. Register as Member\n";
     cout << "Enter member option: ";
}

void showAdminOptions()
{
     cout << "\nThis is your menu:\n";
     cout << setw(4) << ""
          << "0. Go Back\n";
     cout << setw(4) << ""
          << "1. View All Member Information\n";
     cout << setw(4) << ""
          << "2. View All House Information\n";
     cout << setw(4) << ""
          << "3. View All Request Information\n";
     cout << "Enter admin option: ";
}
// void showMemberLogin()
// {
// }

//  g++ test.cpp House.cpp Member.cpp Request.cpp Admin.cpp Data.cpp -o test
//  g++ main.cpp House.cpp Member.cpp Request.cpp Admin.cpp Data.cpp -o test
// ./test

int main(int argc, char *argv[])
{
     Data data = Data();
     Member member = Member();
     member.setUsername("member");
     member.setPassword("member");
     data.addMember(member);

     string username;
     string password;
     string memberOption = "1";
     Member Mem = data.getMemberByUsername("member");
     House h = Mem.getHouse();
     int houseId, MemberId, RequestId;
     string locationH, descriptionH, startDateH, endDateH;
     double minOccupantScoreH, consumingPointH;
     // while (1)
     // {
     //      cout << "\nLogin Section - Enter 'exitxxx' if not working\n";
     //      cout << setw(4) << ""
     //           << "Please enter your username: ";
     //      cin >> username;
     //      if (username.compare("exitxxx") == 0)
     //           break;
     //      cout << setw(4) << ""
     //           << "Please enter your password: ";
     //      cin >> password;
     //      if (password.compare("exitxxx") == 0)
     //           break;

     //      if (data.verifyMemberByUsername(username))
     //      {
     //           if (data.verifyMemberByUsernameAndPassword(username, password))
     //           {
     //                cout << "Suscessfully logged in\n";
     //                break;
     //           }
     //           else
     //           {
     //                cout << "Incorrect password\n";
     //           }
     //      }
     //      else
     //      {
     //           cout << "Incorrect Username or Don't Have Account\n";
     //      }
     // }

     // while (1)
     // {
     //      showMemberOptions();
     //      cin >> memberOption;
     //      if (
     //          memberOption.compare("0") == 0 || memberOption.compare("1") == 0 || memberOption.compare("2") == 0 ||
     //          memberOption.compare("3") == 0 || memberOption.compare("4") == 0 || memberOption.compare("5") == 0 ||
     //          memberOption.compare("6") == 0 || memberOption.compare("7") == 0 || memberOption.compare("8") == 0 ||
     //          memberOption.compare("9") == 0 || memberOption.compare("10") == 0 || memberOption.compare("11") == 0)
     //      {
     //           break;
     //      }
     //      else
     //      {
     //           cout << "Invalid option. Try again." << endl;
     //      }
     // }

     switch (stoi(memberOption))
     {
     case 0:
          cout << "case 0 \n";
          break;
     case 1: // View Account Information
          cout << "Account Information: \n";

          Mem.showAllMemberInfo();
          Mem.getHouse().showAllHouseInfo();

          break;
     case 2: // List House for Occupant
          cout << "case 2 \n";
          // TODO: Check if already have house or not
          // TODO: If yes -> update house
          // TODO: If no -> add new house
          cout << "Please enter house information... \n";
          cout << "Enter house location (hanoi, saigon, hue): ";
          cin >> locationH;
          cout << "Enter house description: ";
          cin >> descriptionH;
          cout << "Enter start date for occupant (YYYY-MM-DD): ";
          cin >> startDateH;
          cout << "Enter end date for occupant (YYYY-MM-DD): ";
          cin >> endDateH;
          cout << "Enter min score for occupant (-10 to 10): ";
          cin >> minOccupantScoreH;
          cout << "Enter house consuming point per day: ";
          cin >> consumingPointH;

          h = data.createHouseforOccupant(locationH, descriptionH, startDateH, endDateH, minOccupantScoreH, consumingPointH);
          h.setId(68);
          Mem.setHouse(h);
          break;
     case 3: // Unlist House for Occupant
          cout << "case 3 \n";
          // cout << "Enter house id to unlist: ";
          // cin >> houseId;
          // data.deleteHouseById(houseId);
          break;
     case 4: // View Available Houses to Occupy
          cout << "case 4 \n";
          break;
     case 5: // Request to Occupy House
          cout << "case 5 \n";
          break;
     case 6: // Rate Occupied House
          cout << "case 6 \n";
          break;
     case 7:
          cout << "case 7 \n";
          break;
     case 8:
          cout << "case 8 \n";
          break;
     case 9:
          cout << "case 9 \n";
          break;
     case 10:
          cout << "case 10 \n";
          break;
     case 11:
          cout << "case 1 \n";
          break;
     default:
          cout << "Other cases \n";
          break;
     }
     return 0;
}
