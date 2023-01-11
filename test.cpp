
#include "Member.h"
#include "House.h"
#include "Request.h"
#include "Data.h"

#include <vector>
#include <iomanip>
#include <string>
#include <iostream>
#include <ctime>
#include <chrono>

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
};

void showLoginOptions()
{
     cout << "\nUse app as 1. Guest, 2. Member or 3.Admin\n";
     cout << "Enter user option: ";
};

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
};

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
          << "6. View All Occupy Request to your House\n";
     cout << setw(4) << ""
          << "7. Response to Occupy Request\n";
     cout << setw(4) << ""
          << "8. Rate Occupied House\n";
     cout << setw(4) << ""
          << "9. Rate Occupant of your House\n";
     cout << "Enter member option: ";
};

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
};

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
};

bool checkLeapYear(int yyyy)
{
     if (yyyy % 400 == 0)
          return true;
     else if (yyyy % 100 != 0 && yyyy % 4 == 0)
          return true;
     else
          return false;
};

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
};

bool checkStringDate(string date)
{
     // date must be yyyy-mm-dd for this to work
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
};

int countDayDiff(string start, string end)
{
     int ys, ms, ds, ye, me, de;
     for (int i = 0; i < start.size(); i++)
     {
          if (start[i] == '-' && i != 4)
          {
               ys = stoi(start.substr(0, 4));
               ms = stoi(start.substr(5, i - 5));
               ds = stoi(start.substr(i + 1, start.size() - i));
          }
     }
     for (int i = 0; i < end.size(); i++)
     {
          if (end[i] == '-' && i != 4)
          {
               ye = stoi(end.substr(0, 4));
               me = stoi(end.substr(5, i - 5));
               de = stoi(end.substr(i + 1, end.size() - i));
          }
     }
     return days_from_civil(ye, me, de) - days_from_civil(ys, ms, ds);
};

//  g++ test.cpp House.cpp Member.cpp Request.cpp Admin.cpp Data.cpp -o test
// ./test
int main(int argc, char *argv[])
{
     // Sample data
     Data data = Data();
     House h1 = House(1, "hanoi", "hanoi1", 5, -10, 20, "2023-2-1", "2023-2-21", false);
     House h2 = House(2, "saigon", "saigon2", 1, 2, 30, "2023-2-13", "2023-3-23", false);
     House h3 = House(3, "hue", "hue3", 0, -8, 10, "2023-1-14", "2023-2-24", false);
     House h4 = House(4, "hanoi", "hanoi4", 0, -8, 35, "2023-2-5", "2023-2-25", false);
     House h5 = House(5, "hanoi", "hanoi5", 5, -10, 20, "2023-2-1", "2023-2-21", false);
     House h6 = House(6, "saigon", "saigon6", 1, 2, 30, "2023-2-13", "2023-3-23", false);
     House h7 = House(7, "hue", "hue7", 0, -8, 10, "2023-1-14", "2023-2-24", false);
     House h8 = House(8, "hanoi", "hanoi8", 5, 8, 15, "2023-2-5", "2023-2-25", false);
     data.addHouse(h1);
     data.addHouse(h2);
     data.addHouse(h3);
     data.addHouse(h4);
     data.addHouse(h5);
     data.addHouse(h6);
     data.addHouse(h7);
     data.addHouse(h8);

     Member m1 = Member(1, "fullname1", "username1", "password1", "phone1", 100, 1, h1);
     Member m2 = Member(2, "fullname2", "username2", "password2", "phone2", 200, 2, h2);
     Member m3 = Member(3, "fullname3", "username3", "password3", "phone3", 300, 3, h3);
     Member m4 = Member(4, "fullname4", "username4", "password4", "phone4", 400, 4, h4);
     Member m5 = Member(5, "fullname5", "username5", "password5", "phone5", 500, 5, h5);
     Member m6 = Member(6, "fullname6", "username6", "password6", "phone6", 600, 6, h6);
     Member m7 = Member(7, "fullname7", "username7", "password7", "phone7", 700, 7, h7);
     Member m8 = Member(8, "fullname8", "username8", "password8", "phone8", 800, 8, h8);
     data.addMember(m1);
     data.addMember(m2);
     data.addMember(m3);
     data.addMember(m4);
     data.addMember(m5);
     data.addMember(m6);
     data.addMember(m7);
     data.addMember(m8);

     Request r1 = Request(1, m1, h8, false, 0, 0, "", "");
     Request r2 = Request(2, m2, h8, false, 0, 0, "", "");
     Request r3 = Request(3, m3, h8, false, 0, 0, "", "");
     Request r4 = Request(4, m4, h7, true, 0, 0, "", "");
     Request r5 = Request(5, m5, h7, false, 0, 0, "", "");
     data.addRequest(r1);
     data.addRequest(r2);
     data.addRequest(r3);
     data.addRequest(r4);
     data.addRequest(r5);

     // login check then use this to track member while using the app
     Member member = Member(8, "member", "member", "member", "member", 300, 7, House()); // TODO: member should be registered earlier
     data.addMember(member);
     string username; // prompt user to get username
     string password; // prompt user to get password

     // Member option 2, 3 List and UnList House for Occupant
     Member Mem = data.getMemberByUsername("member");
     House h = Mem.getHouse();
     int houseId, MemberId, RequestId;
     string locationH, descriptionH, startDateH, endDateH;
     double minOccupantScoreH, consumingPointH;

     // Member option 4 - View available house
     vector<House> houseList;
     vector<House> yourHouseList;
     string chosenSTime;    // TODO: should prompt user to get date
     string chosenETime;    // TODO: should prompt user to get date
     string chosenLocation; // TODO: should prompt user to get location
     string s, e;
     int period;

     // Member option 5 - Request To Occupy
     // member = Member(8, "member", "member", "member", "member", 600, 8, House());
     Request request;
     House chosenHouse = h1; // TODO: should prompt user to get house

     // Member option6 - View All Occupy Request to your House
     vector<Request> requestList;
     vector<Request> yourRequestList;
     int chosenRequestId;
     string chosenResponse; // TODO: should prompt user to get response

     // Member option7 - Response to Occupy Request - Only available while testing option 7
     member.setId(8);
     yourRequestList.push_back(r1);
     yourRequestList.push_back(r2);
     yourRequestList.push_back(r3);

     // Member option 8 - Rate Occupied House - Only available while testing option 8
     member.setId(4);

     // Member option 9
     member.setId(7);

     while (1)
     {
          cout << "\nLogin Section - Enter 'exitxxx' if not working\n";
          cout << setw(4) << ""
               << "Please enter your username: ";
          cin >> username;
          if (username.compare("exitxxx") == 0)
               break;
          cout << setw(4) << ""
               << "Please enter your password: ";
          cin >> password;
          if (password.compare("exitxxx") == 0)
               break;

          if (data.verifyMemberByUsername(username))
          {
               if (data.verifyMemberByUsernameAndPassword(username, password))
               {
                    cout << "Suscessfully logged in\n";
                    break;
               }
               else
               {
                    cout << "Incorrect password\n";
               }
          }
          else
          {
               cout << "Incorrect Username or Don't Have Account\n";
          }
     }

     while (1)
     {
          showMemberOptions();
          cin >> memberOption;
          if (
              memberOption.compare("0") == 0 || memberOption.compare("1") == 0 || memberOption.compare("2") == 0 ||
              memberOption.compare("3") == 0 || memberOption.compare("4") == 0 || memberOption.compare("5") == 0 ||
              memberOption.compare("6") == 0 || memberOption.compare("7") == 0 || memberOption.compare("8") == 0 ||
              memberOption.compare("9") == 0 || memberOption.compare("10") == 0 || memberOption.compare("11") == 0)
          {
               break;
          }
          else
          {
               cout << "Invalid option. Try again." << endl;
          }
     }

     // Predefine member option - Use for Testing
     string memberOption = "8";

     switch (stoi(memberOption))
     {
     case 0:
          cout << "case 0 \n";
          // Testing -- will be deleted later
          data.ViewAllHouses();
          cout << "\n";
          data.ViewAllMembers();
          cout << "\n";
          data.ViewAllRequests();
          break;
     case 1: // View Account Information
          cout << "[Account Information] \n";
          Mem.showAllMemberInfo();
          Mem.getHouse().showAllHouseInfo();
          break;
     case 2: // List House for Occupant
          cout << "[List House for Occupant] \n";
          // TODO: Check if already have house or not
          // TODO: If yes -> update house
          // TODO: If no -> add new house
          cout << "Please enter house information... \n";
          cout << "Enter house location (hanoi, saigon, hue): ";
          cin >> locationH;
          cout << "Enter start date for occupant (YYYY-MM-DD): ";
          cin >> startDateH;
          cout << "Enter end date for occupant (YYYY-MM-DD): ";
          cin >> endDateH;
          cout << "Enter min score for occupant (-10 to 10): ";
          cin >> minOccupantScoreH;
          cout << "Enter house consuming point per day: ";
          cin >> consumingPointH;
          cout << "Enter house description: ";
          cin.ignore();
          getline(cin, descriptionH);
          h = data.createHouseforOccupant(locationH, descriptionH, startDateH, endDateH, minOccupantScoreH, consumingPointH);
          h.setId(68);
          Mem.setHouse(h);
          cout << "This is your house information: \n";
          Mem.getHouse().showAllHouseInfo();
          break;
     case 3: // Unlist House for Occupant
          cout << "[Unlist House for Occupant] \n";
          // cout << "Enter house id to unlist: ";
          // cin >> houseId;
          // data.deleteHouseById(houseId);
          break;
     case 4: // View Available Houses to Occupy
          cout << "[View Available Houses to Occupy] \n";
          // in a specified time (start-end) and city + appropriate credit point and rating
          houseList = data.getHouseList();
          member.getHouse().showAllHouseAttributes();
          chosenSTime = "2023-2-11";
          chosenETime = "2023-2-16";
          chosenLocation = "hanoi";
          for (int i = 0; i < houseList.size(); i++)
          {
               s = houseList[i].getStartDate();
               e = houseList[i].getEndDate();
               period = countDayDiff(chosenSTime, chosenETime);
               if (
                   countDayDiff(chosenSTime, s) < 0 && countDayDiff(chosenETime, e) > 0 &&
                   chosenLocation.compare(houseList[i].getLocation()) == 0 &&
                   member.getCreditPoint() >= houseList[i].getConsumingPoint() * period &&
                   member.getOccupierRating() >= houseList[i].getMinOccupantScore() &&
                   member.getHouse().getId() != houseList[i].getId())
               {
                    yourHouseList.push_back(houseList[i]);
                    houseList[i].showAllHouseInfo();
               }
          }
          break;
     case 5: // Request to Occupy House
          cout << "[Request to Occupy House] \n";
          request.setId(68);
          request.setHouse(chosenHouse);
          request.setOccupant(member);
          request.setRequestStatus(false);
          data.addRequest(request);
          request.showAll();
          break;
     case 6: // View All Occupy Request to your House
          cout << "[View All Occupy Request to your House] \n";
          requestList = data.getRequestList();
          request.showAllRequestAttributes();
          for (int i = 0; i < requestList.size(); i++)
          {
               if (data.getMemberByHouseId(requestList[i].getHouse().getId()).getId() == member.getId())
               {
                    requestList[i].showAllRequestInfo();
               }
               yourRequestList.push_back(requestList[i]);
          }
          break;
     case 7: // Response to Occupy Request
          cout << "[Response to Occupy Request] \n";
          chosenResponse = "yes";
          chosenRequestId = 1;

          for (auto &Req : yourRequestList)
          {
               if (Req.getId() == chosenRequestId && chosenResponse.compare("yes") == 0)
               {
                    // change occupy status for member houses after accept one of the requests
                    member.getHouse().setOccupyStatus(true);
                    data.updateHouse(member.getHouse());
                    Req.setRequestStatus(true);
                    // delete all requests in your request list after you accept one of them
                    data.deleteOtherRequestAfterAccept(Req, yourRequestList);

                    // try to print out requests for testing -- will be delete later
                    Req.showAllRequestAttributes();
                    for (auto &r : data.getRequestList())
                    {
                         r.showAllRequestInfo();
                    }
               }
          }

          break;
     case 8: // Rate Occupied House
          cout << "[Rate Occupied House] \n";
          for (auto &r : data.getRequestList())
          {
               if (r.getOccupant().getId() == member.getId() && r.getRequestStatus() == true)
               {
                    r.setHouseRating(5);
                    r.setHouseReview("best house ever");
                    r.showAll();
               }
          }
          break;
     case 9: // Rate Occupant of your House
          cout << "[Rate Occupant of your House] \n";
          for (auto &r : data.getRequestList())
          {
               if (r.getHouse().getId() == member.getHouse().getId() && r.getRequestStatus() == true)
               {
                    r.setOccupantRating(5);
                    r.setOccupantReview("best house ever");
                    r.showAll();
               }
          }
          break;

     default:
          cout << "Other cases \n";
          break;
     }

     return 0;
};
