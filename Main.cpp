
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

#include <conio.h>
#include <stdlib.h>

// TODO: figure out how to handle the id system of House, Member, and Request

using namespace std;

void showWelcomeScreen()
{
    cout << "EEET2482/COSC2082 ASSIGNMENT\n"
         << "VACATION HOUSE EXCHANGE APPLICATION\n"
         << "Instructors: Mr. Linh Tran & Phong Ngo\n"
         << "Group: Group 28\n"
         << "s3824892, Chau Minh Kha\n"
         << "s3902460, Nguyen Minh Phu\n"
         << "s3752577, Thai Le\n"
         << "s3927195, The Anh\n"
         << "s3915202, Trinh Viet Quy\n"
         << "Welcome to our House Exchange App!\n";
}

void showLoginOptions()
{
    cout << "\nUse app as 1. Guest, 2. Member, 3.Admin or 4.Exit\n";
    cout << "Enter user option: ";
}

void showGuestOptions()
{
    cout << "\n[Guest Menu]\n";
    cout << setw(4) << ""
         << "0. Go Back\n"
         << setw(4) << ""
         << "1. View All Houses Information (exclude reviews and occupy status)\n"
         << setw(4) << ""
         << "2. Register as Member\n"
         << setw(4) << ""
         << "3. Exit\n"
         << "Enter guest option: ";
}

void showMemberOptions()
{
    cout << "\n[Member Menu]\n";
    cout << setw(4) << ""
         << "0. Log Out\n"
         << setw(4) << ""
         << "1. View Account Information\n"
         << setw(4) << ""
         << "2. List House for Occupant \n"
         << setw(4) << ""
         << "3. Unlist House for Occupant\n"
         << setw(4) << ""
         << "4. View Available Houses to Occupy\n"
         << setw(4) << ""
         << "5. Request to Occupy House\n"
         << setw(4) << ""
         << "6. View All Occupy Request to your House\n"
         << setw(4) << ""
         << "7. Response to Occupy Request\n"
         << setw(4) << ""
         << "8. Rate Occupied House\n"
         << setw(4) << ""
         << "9. Rate Occupant of your House\n"
         << setw(4) << ""
         << "10. Exit\n"
         << "Enter member option: ";
}

void showAdminOptions()
{
    cout << "\n[Admin Menu]\n";
    cout << setw(4) << ""
         << "0. Go Back\n"
         << setw(4) << ""
         << "1. View All Member Information\n"
         << setw(4) << ""
         << "2. View All House Information\n"
         << setw(4) << ""
         << "3. View All Request Information\n"
         << setw(4) << ""
         << "4. Exit\n"
         << "Enter admin option: ";
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

/** Main Start - Our application run here **/

/** How to compile and run **/
/*  g++ Main.cpp House.cpp Member.cpp Request.cpp Admin.cpp Data.cpp -o Main
/* ./Main
*/

int main(int argc, char *argv[])
{ // Data class to store all data
    Data data = Data();
    data.readDataFromFile("Application.dat");

    vector<Member> memberList;
    vector<House> houseList;
    vector<Request> requestList;
    House emptyHouse = House();
    Member emptyMember = Member();

    // register member
    string fullnameR;
    string usernameR;
    string passwordR;
    string phoneR;

    // login check then use this to track member while using the app
    string username;
    string password;

    // the same go for admin
    string usernameAdmin;
    string passwordAdmin;

    // Member option 1, 2, 3 // View account + List and UnList House for Occupant
    Member Mem;
    House Hou;
    bool hasHouse;
    string hasHouseResponse;
    string locationH, descriptionH, startDateH, endDateH;
    double minOccupantScoreH, consumingPointH;
    int houseId;

    // Member option 4 - View available house
    vector<House> yourHouseList;
    string chosenSTime;
    string chosenETime;
    string chosenLocation;
    string s, e;
    int period;

    // Member option 5 - Request to Occupy
    Request req;
    int chosenHouseId;
    House chosenHouse;

    // Member option 6, 7 - View All Occupy Request to your House + Response to Occupy Request
    vector<Request> yourRequestList;
    int chosenRequestId;
    string chosenResponse;

    // Member option 8, 9 - Rate Occupied House and Rate Occupant of your House
    double occupantRatingM;
    double houseRatingM;
    string houseReviewM;
    string occupantReviewM;

    // logic to change stage
    bool appRunning = true;
    bool guestRunning = true;
    bool memberRunning = true;
    bool memberRunningAfterLogin = true;
    bool adminRunningAfterLogin = false;
    bool adminRunning = true;
    int loginOption;
    int guestOption;
    int memberOption;
    int adminOption;

    system("cls");
    showWelcomeScreen();
    cout << "Press any key to continue..." << endl;
    getch();
    while (appRunning)
    {
        // Initialize data
        data.readDataFromFile("Application.dat");
        memberList = data.getMemberList();
        houseList = data.getHouseList();
        requestList = data.getRequestList();

        system("cls");
        showLoginOptions();
        cin >> loginOption;
        switch (loginOption)
        {
        case 1: // Go as Guest
            guestRunning = true;
            while (guestRunning)
            {
                cout << "Press any key to continue..." << endl;
                getch();
                system("cls");
                showGuestOptions();
                cin >> guestOption;

                switch (guestOption)
                {
                case 0: // Go Back
                    guestRunning = false;
                    break;
                case 1: // View All Houses Information (exclude reviews and occupy status)
                    cout << "[All Houses Information]\n";
                    emptyHouse.showHouseAttributesforGuest();
                    for (auto &h : houseList)
                    {
                        h.showHouseforGuest();
                    }
                    break;
                case 2: // Register as Member
                    cout << "[Register Section] \n";
                    cout << " Please enter your full name: ";
                    cin.ignore();
                    getline(cin, fullnameR);
                    cout << "Please enter username: ";
                    cin >> usernameR;
                    cout << "Please enter password: ";
                    cin >> passwordR;
                    cout << "Please enter phone: ";
                    cin >> phoneR;

                    if (data.verifyMemberByUsername(usernameR) == true)
                    {
                        cout << "Please try again, there is already a member with the username: " << usernameR << endl;
                        break;
                    }
                    else
                    {
                        emptyMember.setFullname(fullnameR);
                        emptyMember.setUsername(usernameR);
                        emptyMember.setPassword(passwordR);
                        emptyMember.setPhone(phoneR);
                        data.addMember(emptyMember);
                        cout << "Thank you for registered!" << endl;
                        cout << "This is your information: " << endl;
                        data.getMemberByUsername(usernameR).showAll();
                    }
                    break;
                case 3: // Exit.
                    cout << "Application finished - Thank you" << endl;
                    appRunning = false;
                    guestRunning = false;
                    break;
                default:
                    cout << "Oops, something went wrong. Please try again" << endl;
                    break;
                }
            }
            break;
        case 2: // Go as Member
            memberRunning = true;
            while (memberRunning)
            {
                cout << "\n[Login Section] - Enter 'exit!please' to exit\n";
                cout << setw(4) << " "
                     << "Please enter your username: ";
                cin >> username;
                if (username.compare("exit!please") == 0)
                {
                    memberRunning = false;
                    break;
                }
                cout << setw(4) << " "
                     << "Please enter your password: ";
                cin >> password;
                if (password.compare("exit!please") == 0)
                {
                    memberRunning = false;
                    break;
                }
                if (data.verifyMemberByUsername(username))
                {
                    if (data.verifyMemberByUsernameAndPassword(username, password))
                    {
                        // Track logged in member
                        Mem = data.getMemberByUsername(username);

                        cout << "\nSuscessfully logged in\n";
                        memberRunningAfterLogin = true;
                        while (memberRunningAfterLogin)
                        {
                            // Re-Initialize data
                            Hou = Mem.getHouse();
                            memberList = data.getMemberList();
                            houseList = data.getHouseList();
                            requestList = data.getRequestList();

                            for (auto &r : requestList)
                            {
                                if (data.getMemberByHouseId(r.getHouse().getId()).getId() == Mem.getId())
                                    yourRequestList.push_back(r);
                            }

                            for (auto &h : houseList)
                            {
                                if (h.getId() == Hou.getId() && Hou.getId() != 0)
                                    hasHouse = true;
                                else
                                    hasHouse = false;
                            }

                            cout << "Press any key to continue..." << endl;
                            getch();
                            system("cls");
                            showMemberOptions();
                            cin >> memberOption;
                            switch (memberOption)
                            {
                            case 0: // Go Back
                                memberRunningAfterLogin = false;
                                break;
                            case 1: // View Account Information
                                cout << "[Account Information]\n";
                                Mem.showAllMemberAttributes();
                                Mem.showAllMemberInfo();
                                cout << "\n[House Information]\n";
                                Hou.showAllHouseAttributes();
                                Hou.showAllHouseInfo();
                                break;
                            case 2: // List House for Occupant
                                cout << "[List House for Occupant] \n";
                                if (hasHouse)
                                {
                                    cout << "You alread had a house being listed for occupant" << endl;
                                    cout << "Do you want to update your house information (yes/no): ";
                                    cin >> hasHouseResponse;
                                    if (hasHouseResponse.compare("yes") == 0)
                                    {
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
                                    }
                                    else
                                    {
                                        break;
                                    }
                                }
                                else
                                {
                                    cout << "Look like you don't have a house. Please follow instructions and register one\n";
                                    cout << "Enter house location (hanoi, saigon, hue): ";
                                    cin >> locationH;
                                    cout << "Enter start date for occupant (YYYY-MM-DD) (date after 2023-1-1 only): ";
                                    cin >> startDateH;
                                    cout << "Enter end date for occupant (YYYY-MM-DD) (date after 2023-1-1 only): ";
                                    cin >> endDateH;
                                    cout << "Enter min score for occupant (-10 to 10): ";
                                    cin >> minOccupantScoreH;
                                    cout << "Enter house consuming point per day: ";
                                    cin >> consumingPointH;
                                    cout << "Enter house description: ";
                                    cin.ignore();
                                    getline(cin, descriptionH);
                                }
                                if (locationH.compare("hanoi") != 0 && locationH.compare("saigon") != 0 && locationH.compare("hue") != 0)
                                {
                                    cout << "You entered wrong location, please follow the instructions." << endl;
                                }
                                else if (checkStringDate(startDateH) != 1 || checkStringDate(endDateH) != 1)
                                {
                                    cout << "You entered wrong date, please follow the instructions." << endl;
                                }
                                else if (minOccupantScoreH < -10 || minOccupantScoreH > 10)
                                {
                                    cout << "You entered wrong minimum occupant score, please follow the instructions." << endl;
                                }
                                else
                                {
                                    Hou.setLocation(locationH);
                                    Hou.setDescription(descriptionH);
                                    Hou.setStartDate(startDateH);
                                    Hou.setEndDate(endDateH);
                                    Hou.setMinOccupantScore(minOccupantScoreH);
                                    Hou.setConsumingPoint(consumingPointH);
                                    data.updateHouse(Hou);
                                    houseList = data.getHouseList();
                                    Mem.setHouse(houseList.back());
                                    data.updateMember(Mem);
                                    cout << "This is your house information: \n";
                                    data.getMemberByUsername(username).getHouse().showAll();
                                }

                                break;
                            case 3: // Unlist House for Occupant
                                cout << "[Unlist House for Occupant] \n";
                                if (hasHouse)
                                {
                                    cout << "You have a house listed for occupant" << endl;
                                    cout << "Do you want to unlist this house (yes/no): ";
                                    cin >> hasHouseResponse;
                                    if (hasHouseResponse.compare("yes") == 0)
                                    {
                                        data.deleteHouseById(Hou.getId());
                                        Mem.setHouse(emptyHouse);
                                        data.updateMember(Mem);
                                        data.deleteRequestByHouseId(Hou.getId());
                                    }
                                    else
                                    {
                                        break;
                                    }
                                }
                                else
                                {
                                    cout << "Sorry, you don't have a house registered in our database" << endl;
                                }
                                break;
                            case 4: // View Available Houses to Occupy
                                cout << "[View Available Houses to Occupy] \n";
                                cout << "Enter prefered start date (YYYY-MM-DD): ";
                                cin >> chosenSTime;
                                cout << "Enter prefered end date (YYYY-MM-DD): ";
                                cin >> chosenETime;
                                cout << "Enter prefered location (hanoi/hue/saigon): ";
                                cin >> chosenLocation;

                                Mem.getHouse().showAllHouseAttributes(); // print house attributes title
                                for (int i = 0; i < houseList.size(); i++)
                                {
                                    s = houseList[i].getStartDate();
                                    e = houseList[i].getEndDate();
                                    period = countDayDiff(chosenSTime, chosenETime);
                                    if (
                                        countDayDiff(chosenSTime, s) < 0 && countDayDiff(chosenETime, e) > 0 &&
                                        chosenLocation.compare(houseList[i].getLocation()) == 0 &&
                                        Mem.getCreditPoint() >= houseList[i].getConsumingPoint() * period &&
                                        Mem.getOccupierRating() >= houseList[i].getMinOccupantScore() &&
                                        Mem.getHouse().getId() != houseList[i].getId())
                                    {
                                        yourHouseList.push_back(houseList[i]);
                                        houseList[i].showAllHouseInfo();
                                    }
                                }
                                break;
                            case 5: // Request to Occupy House
                                cout << "[Request to Occupy House] \n";
                                // chosenHouse = h1;
                                cout << "Please enter house ID of the house that you chose: ";
                                cin >> chosenHouseId;
                                if (chosenHouseId != Hou.getId() && data.verifyHouseById(chosenHouseId) == true)
                                {
                                    chosenHouse = data.getHouseById(chosenHouseId);
                                    req.setHouse(chosenHouse);
                                    req.setOccupant(Mem);
                                    req.setRequestStatus(false);
                                    data.addRequest(req);
                                    req.showAll();
                                }
                                else
                                {
                                    cout << "There is something wrong with your input! Please try again." << endl;
                                }

                                break;
                            case 6: // View All Occupy Request to your House
                                cout << "[View All Occupy Request to your House] \n";
                                if (yourRequestList.empty())
                                {
                                    cout << "Sorry, you have no request to view yet" << endl;
                                }
                                else
                                {
                                    req.showAllRequestAttributes();
                                    for (auto &r : yourRequestList)
                                    {
                                        r.showAllRequestInfo();
                                    }
                                }

                                break;
                            case 7: // Response to Occupy Request
                                cout << "[Response to Occupy Request] \n";
                                if (yourRequestList.empty())
                                {
                                    cout << "Sorry, you have no request to response" << endl;
                                    break;
                                }
                                else
                                {
                                    cout << "Please enter Request ID of the request that you chose: ";
                                    cin >> chosenRequestId;
                                    cout << "Do you want to accept or deny this request (yes/no): ";
                                    cin >> chosenResponse;

                                    for (auto &r : yourRequestList)
                                    {
                                        if (r.getId() == chosenRequestId && chosenResponse.compare("yes") == 0)
                                        {

                                            // change occupy status for member houses after accept one of the requests
                                            Hou.setOccupyStatus(true);
                                            data.updateHouse(Hou);
                                            data.updateMember(Mem);
                                            // delete all requests in your request list after you accept one of them
                                            for (auto &rr : yourRequestList)
                                            {
                                                if (rr.getId() == chosenRequestId)
                                                {
                                                    yourRequestList.clear();
                                                    rr.setRequestStatus(true);
                                                    yourRequestList.push_back(rr);
                                                }
                                            }
                                            // do the some thing above for request in data
                                            data.deleteOtherRequestAfterAccept(r, yourRequestList);
                                        }
                                        else if (r.getId() == chosenRequestId && chosenResponse.compare("no") == 0)
                                        {
                                            yourRequestList = data.deleteRequestFromRequestList(r, yourRequestList);
                                            data.removeRequest(r);
                                        }
                                        else
                                        {
                                            cout << "There must be somthing wrong! Please try again." << endl;
                                            break;
                                        }
                                    }
                                    cout << "This is your request list" << endl;
                                    req.showAllRequestAttributes();
                                    for (auto &rr : yourRequestList)
                                    {
                                        rr.showAllRequestInfo();
                                    }
                                }

                                break;
                            case 8: // Rate Occupied House
                                cout << "[Rate Occupied House] \n";
                                // houseRatingM = 5;
                                // houseReviewM = "";
                                cout << "Please enter rating for the house you occupied: ";
                                cin >> houseRatingM;
                                cout << "Please enter review for the house you occupied: ";
                                cin >> houseReviewM;
                                for (auto &r : requestList)
                                {
                                    if (r.getOccupant().getId() == Mem.getId() && r.getRequestStatus() == true)
                                    {
                                        r.setHouseRating(houseRatingM);
                                        r.setHouseReview(houseReviewM);
                                        r.showAll();
                                    }
                                }
                                break;
                            case 9: // Rate Occupant of your House
                                cout << "[Rate Occupant of your House] \n";
                                // occupantRatingM = 5;
                                // occupantReviewM = "";
                                cout << "Please enter rating for the occupant of your house: ";
                                cin >> occupantRatingM;
                                cout << "Please enter review for the occupant of your house: ";
                                cin >> occupantReviewM;
                                for (auto &r : requestList)
                                {
                                    if (r.getHouse().getId() == Mem.getHouse().getId() && r.getRequestStatus() == true)
                                    {
                                        r.setOccupantRating(occupantRatingM);
                                        r.setOccupantReview(occupantReviewM);
                                        r.showAll();
                                    }
                                }
                                break;
                            case 10: // Exit
                                cout << "Application finished - Thank you" << endl;
                                appRunning = false;
                                memberRunning = false;
                                memberRunningAfterLogin = false;
                                break;
                            default:
                                cout << "Oops, something went wrong. Please try again" << endl;
                                break;
                            }
                        }
                    }
                    else
                    {
                        cout << "\nIncorrect password! Try Again\n";
                    }
                }
                else
                {
                    cout << "\nIncorrect Username or Don't Have Account! Try Again\n";
                }
            }
            break;
        case 3: // Go as Admin
            adminRunning = true;
            while (adminRunning)
            {
                cout << "\nLogin Section - Enter 'exitx!please' to exit\n";
                cout << setw(4) << ""
                     << "Please enter your username: ";
                cin >> usernameAdmin;
                if (usernameAdmin.compare("exitx!please") == 0)
                {
                    adminRunning = false;
                    break;
                }
                cout << setw(4) << ""
                     << "Please enter your password: ";
                cin >> passwordAdmin;
                if (passwordAdmin.compare("exitx!please") == 0)
                {
                    adminRunning = false;
                    break;
                }

                if (usernameAdmin.compare("admin") == 0)
                {
                    if (usernameAdmin.compare("admin") == 0 && passwordAdmin.compare("admin") == 0)
                    {
                        cout << "\nSuscessfully logged in\n";
                        adminRunningAfterLogin = true;
                        while (adminRunningAfterLogin)
                        {
                            cout << "Press any key to continue..." << endl;
                            getch();
                            system("cls");
                            showAdminOptions();
                            cin >> adminOption;
                            switch (adminOption)
                            {
                            case 0: // Go Back
                                adminRunningAfterLogin = false;
                                break;
                            case 1: // View All Member Information
                                cout << "[All Member Information]\n";
                                data.ViewAllMembers();
                                break;
                            case 2: // View All House Information
                                cout << "[All House Information]\n";
                                data.ViewAllHouses();
                                break;
                            case 3: // View All Request Information
                                cout << "[All Request Information]\n";
                                data.ViewAllRequests();
                                break;
                            case 4: // Exit.
                                cout << "Application finished - Thank you" << endl;
                                appRunning = false;
                                adminRunning = false;
                                adminRunningAfterLogin = false;
                                break;
                            default:
                                cout << "Oops, something went wrong. Please try again" << endl;
                                break;
                            }
                        }
                    }
                    else
                    {
                        cout << "\nIncorrect password\n";
                    }
                }
                else
                {
                    cout << "\nIncorrect Username or Don't Have Account\n";
                }
            }
            break;
        case 4: // Exit
            cout << "Application finished - Thank you" << endl;
            appRunning = false;
            break;
        default:
            cout << "Oops, something went wrong! Please try again" << endl;
            break;
        }

        // Store any changes to data to file
        // data.writeDataToFile("A3A3.dat");
        data.writeDataToFile("Application.dat");
    }

    return 0;
}
