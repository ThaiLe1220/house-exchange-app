
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
{
    // Display welcome screen
    bool appRunning = true;
    bool guestRunning = true;
    bool memberRunning = true;
    bool memberRunningAfterLogin = true;
    bool adminRunning = true;
    int loginOption;
    int guestOption;
    int memberOption;
    int adminOption;

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

    Member m1 = Member(1, "thai", "thai", "thai", "0349087318", 999, 9, h1);
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

    Request r1 = Request(1, m8, h1, false, 0, 0, "", "");
    Request r2 = Request(2, m7, h1, false, 0, 0, "", "");
    Request r3 = Request(3, m6, h1, false, 0, 0, "", "");
    Request r4 = Request(4, m4, h7, true, 5, 5, "best house", "worst occupant");
    data.addRequest(r1);
    data.addRequest(r2);
    data.addRequest(r3);
    data.addRequest(r4);

    // login check then use this to track member while using the app
    string username; // prompt user to get username
    string password; // prompt user to get password

    // Member option 1, 2, 3 // View account + List and UnList House for Occupant
    Member Mem;
    House Hou;
    string locationH, descriptionH, startDateH, endDateH;
    double minOccupantScoreH, consumingPointH;
    int houseId;

    // Member option 4 - View available house
    vector<House> houseList;
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
    vector<Request> requestList;
    vector<Request> yourRequestList;
    int chosenRequestId;
    string chosenResponse;

    // Member option 8, 9 - Rate Occupied House and Rate Occupant of your House
    double occupantRatingM;
    double houseRatingM;
    string houseReviewM;
    string occupantReviewM;

    system("cls");
    showWelcomeScreen();
    cout << "Press any key to continue..." << endl;
    getch();
    while (appRunning)
    {
        system("cls");
        showLoginOptions();
        cin >> loginOption;
        cout << "\nPress any key to continue..." << endl;
        getch();
        switch (loginOption)
        {
        case 1: // Go as Guest
            guestRunning = true;
            while (guestRunning)
            {
                system("cls");
                showGuestOptions();
                cin >> guestOption;

                switch (guestOption)
                {
                case 0: // Go Back
                    guestRunning = false;
                    break;
                case 1: // View All Houses Information (exclude reviews and occupy status)
                        // TODO:
                    cout << "[All Houses Information]\n";

                    break;
                case 2: // Register as Member
                        // TODO:
                    cout << "[Register Section] \n";

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
                cout << "\n[Login Section] - Enter 'exit!please' if you want to exit anytime\n";
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
                        cout << "\nSuscessfully logged in\n";
                        memberRunningAfterLogin = true;
                        while (memberRunningAfterLogin)
                        {
                            // Track logged in member
                            Mem = data.getMemberByUsername(username);
                            Hou = Mem.getHouse();
                            houseList = data.getHouseList();
                            requestList = data.getRequestList();
                            for (auto &r : requestList)
                            {
                                if (data.getMemberByHouseId(r.getHouse().getId()).getId() == Mem.getId())
                                {
                                    r.showAllRequestInfo();
                                    yourRequestList.push_back(r);
                                }
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
                                Hou = data.createHouseforOccupant(locationH, descriptionH, startDateH, endDateH, minOccupantScoreH, consumingPointH);
                                Hou.setId(68);
                                Mem.setHouse(Hou);
                                data.updateHouse(Hou);
                                cout << "This is your house information: \n";
                                Mem.getHouse().showAllHouseInfo();
                                break;
                            case 3: // Unlist House for Occupant
                                cout << "[Unlist House for Occupant] \n";
                                cout << "Enter house id to unlist: ";
                                cin >> houseId;
                                data.deleteHouseById(houseId);
                                break;
                            case 4: // View Available Houses to Occupy
                                cout << "[View Available Houses to Occupy] \n";
                                // chosenSTime = "2023-2-11";
                                // chosenETime = "2023-2-16";
                                // chosenLocation = "hanoi";
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
                                chosenHouse = data.getHouseById(chosenHouseId);

                                req.setId(68);
                                req.setHouse(chosenHouse);
                                req.setOccupant(Mem);
                                req.setRequestStatus(false);
                                data.addRequest(req);
                                req.showAll();
                                break;
                            case 6: // View All Occupy Request to your House
                                cout << "[View All Occupy Request to your House] \n";
                                req.showAllRequestAttributes();
                                for (auto &r : yourRequestList)
                                {
                                    r.showAllRequestInfo();
                                }
                                break;
                            case 7: // Response to Occupy Request
                                cout << "[Response to Occupy Request] \n";
                                // chosenResponse = "yes";
                                // chosenRequestId = 1;
                                cout << "Please enter Request ID of the request that you chose: ";
                                cin >> chosenRequestId;
                                cout << "Do you want to accept or deny this request (yes/no): ";
                                cin >> chosenResponse;
                                for (auto &r : yourRequestList)
                                {
                                    if (r.getId() == chosenRequestId && chosenResponse.compare("yes") == 0)
                                    {
                                        // change occupy status for member houses after accept one of the requests
                                        Mem.getHouse().setOccupyStatus(true);
                                        data.updateHouse(Mem.getHouse());
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
                                    if (r.getId() == chosenRequestId && chosenResponse.compare("no") == 0)
                                    {
                                        yourRequestList = data.deleteRequestFromRequestList(r, yourRequestList);
                                        data.removeRequest(r);
                                    }
                                }

                                // try to print out requests for testing -- will be delete later
                                req.showAllRequestAttributes();
                                for (auto &rr : yourRequestList)
                                {
                                    rr.showAllRequestInfo();
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
                cout << "Press any key to continue..." << endl;
                getch();
                system("cls");
                showAdminOptions();
                cin >> adminOption;
                switch (adminOption)
                {
                case 0: // Go Back
                    adminRunning = false;
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
                    break;
                default:
                    cout << "Oops, something went wrong. Please try again" << endl;
                    break;
                }
            }
            break;
        case 4: // Exit
            cout << "Application finished - Thank you" << endl;
            appRunning = false;
            break;
        default:
            cout << "Oops, something went wrong. Please try again" << endl;
            break;
        }
    }

    return 0;
}

/** Function to Read and Write from/to File -- Act as a database **/
/**
int readHouseFromFile(string filename)
{
    House house;
    fstream file;
    file.open(filename, ios::in | ios::binary);
    if (!file)
    {
        cout << "Error opening file" << endl;
        return -1;
    }
    if (file.read((char *)&house, sizeof(house)))
    {
        cout << endl
             << left << setw(10) << "HOUSE NAME"
             << left << setw(10) << "CITY"
             << left << setw(10) << "OCCUPATION STATUS"
             << left << setw(10) << "HOUSE RATING"
             << left << setw(10) << "MINIMUM SCORE REQUIRED" << endl;
        while (!file.eof())
        {
            house.displayHouse();
            file.read((char *)&house, sizeof(house));
        }
    }
    else
    {
        cout << "Error reading from file" << endl;
        return -1;
    }
    file.close();
    return 0;
};

int writeHouseToFile(House house, string filename){
    house.readHouse();
    fstream file;
    /// write to file
    file.open(filename, ios::out | ios::binary | ios::app);
    if (!file) {
        cout << "Error writing file" << endl;
        return -1;
    }
    file.write((char *) &house, sizeof(house));
    file.close();
    cout << "SAVED YOUR HOUSE DETAILS" << endl;
    return 0;
};

int deleteHouseFromFile(string filename){
    House house;
    string houseName;
    cout << "Please input house name you want to delete: ";
    cin >> houseName;
    fstream file;
    file.open(filename, ios::in | ios::binary);
    if (!file) {
        cout << "Error opening file" << endl;
        return -1;
    }
    vector<string> HName;
    while (getline(file, houseName))
        HName.push_back(houseName);
    file.close();
    return 0;
};

**/
