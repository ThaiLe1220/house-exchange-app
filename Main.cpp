
#include "Member.h"
#include "House.h"
#include "Request.h"
#include "Data.h"

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

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
    cout << "\nUse app as 1. Guest, 2. Member, 3.Admin or 4.Exit\n";
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
    cout << setw(4) << ""
         << "3. Exit\n";
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
         << "2. List House for Occupy\n";
    cout << setw(4) << ""
         << "3. Unlist House for Occupy\n";
    cout << setw(4) << ""
         << "4. View Available Houses Information\n";
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
    cout << setw(4) << ""
         << "11. Exit\n";
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
    cout << setw(4) << ""
         << "4. Exit\n";
    cout << "Enter admin option: ";
}

/** Main Start - Our application run here **/

/** How to compile and run **/
/*  g++ Main.cpp House.cpp Member.cpp Request.cpp Admin.cpp Data.cpp -o Main
/* ./Main
*/

int main(int argc, char *argv[])
{
    // Display welcome screen
    showWelcomeScreen();
    string loginOption;

    while (1)
    {
        showLoginOptions();
        cin >> loginOption;
        if (
            loginOption.compare("1") == 0 || loginOption.compare("2") == 0 || 
            loginOption.compare("3") == 0 || loginOption.compare("4") == 0)
        {
            break;
        }
        else
        {
            cout << "Invalid option. Try again." << endl;
        }
    }

    // cout << loginOption << endl;
    cout << endl;

    if (loginOption == "1")
    {

        while (1)
        {
            showGuestOptions();
            string guestOption;
            cin >> guestOption;
            if (
                guestOption.compare("0") == 0 || guestOption.compare("1") == 0 || guestOption.compare("2") == 0 ||
                guestOption.compare("3") == 0 || guestOption.compare("4") == 0)
            {
                break;
            }
            else
            {
                cout << "Invalid option. Try again." << endl;
            }
        }
        // TODO: Continue
    }
    else if (loginOption == "2")
    {
        while (1)
        {
            showMemberOptions();
            string memberOption;
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

        // TODO: Continue
    }
    else if (loginOption == "3")
    {
        showAdminOptions();
        string adminOption;
        cin >> adminOption;
        while (1)
        {
            if (
                adminOption.compare("0") == 0 || adminOption.compare("1") == 0 || adminOption.compare("2") == 0 ||
                adminOption.compare("3") == 0 || adminOption.compare("4") == 0)
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
       

        // TODO: Continue
    }
    else if (loginOption == "4")
    {
        return -1;
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
