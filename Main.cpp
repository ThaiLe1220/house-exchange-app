#include <iostream>
#include <string>
#include "Member.h"
#include "House.h"
#include "Request.h"
#include "Data.h"


#include <vector>
#include <iomanip>

// TODO: figure out how to handle the id system of House, Member, and Request

using namespace std;

/** Main Start - Our application run here **/

/** How to compile and run **/
/*  g++ Main.cpp House.cpp Member.cpp Request.cpp Admin.cpp Data.cpp -o t1
/* ./t1
*/

int main(int argc, char *argv[])
{
     // House h1 = House("house1", "hue", "description1", 1);
     // House *h2 = new House("house2", "saigon", "description2", 2);

     // vector<House *> houseList;
     // houseList.push_back(&h1);
     // houseList.push_back(h2);
     // // for (auto h : houseList){
     // //     cout << "House: " << h->name << endl;
     // // }
     // vector<Request> requestList;
     // Member m1 = Member("member1", "user1", "password1", "phone1", 1, 501, 11, h1, false, requestList);
     // // m1.showMemberinfo();

     /** Kha Work comment out for now to prioritize testing method from each class and readFromFile and writeToFile Function  **/

     // // Display welcome screen
     // cout << "EEET2482/COSC2082 ASSIGNMENT"
     //      << "\n";
     // cout << "VACATION HOUSE EXCHANGE APPLICATION"
     //      << "\n";
     // cout << "Instructors: Mr. Linh Tran & Phong Ngo"
     //      << "\n";
     // cout << "Group: Group 28"
     //      << "\n";
     // cout << "s3824892, Chau Minh Kha"
     //      << "\n";
     // cout << "s3902460, Nguyen Minh Phu"
     //      << "\n";
     // cout << "s3752577, Thai Le"
     //      << "\n";
     // cout << "s3927195, The Anh"
     //      << "\n";
     // cout << "s3915202, Trinh Viet Quy"
     //      << "\n";
     // cout << "Welcome to our House Exchange App!";
     // cout << "Use the app as 1. Guest   2. Member   3. Admin"
     //      << "\n";
     // cout << "Enter your choice: ";
     // int user_type;
     // cin >> user_type;

     // if (user_type == 1)
     // {
     //      // Guest user
     //      while (true)
     //      {
     //           cout << "This is your menu:"
     //                << "\n";
     //           cout << "0. Exit"
     //                << "\n";
     //           cout << "1. View available houses"
     //                << "\n";
     //           cout << "Enter your choice: ";
     //           int choice;
     //           cin >> choice;

     //           if (choice == 0)
     //           {
     //                break;
     //           }
     //           else if (choice == 1)
     //           {
     //                cout << "Enter start date (YYYY-MM-DD): ";
     //                string start_date;
     //                cin >> start_date;
     //                cout << "Enter end date (YYYY-MM-DD): ";
     //                string end_date;
     //                cin >> end_date;
     //                cout << "Enter city: ";
     //                string city;
     //                cin >> city;
     //                system.ViewAvailableHouses(-1, start_date, end_date, city);
     //           }
     //           else
     //           {
     //                cout << "Error: Invalid menu choice."
     //                     << "\n";
     //           }
     //      }
     // }
     // else if (user_type == 2)
     // {
     //      // Member user
     //      cout << "Enter username: ";
     //      string username;
     //      cin >> username;

     //      int member_id = -1;
     //      for (int i = 0; i < system.members().size(); i++)
     //      {
     //           if (system.members()[i].personal_info().username() == username)
     //           {
     //                member_id = i;
     //                break;
     //           }
     //      }

     //      if (member_id == -1)
     //      {
     //           cout << "Error: Invalid username."
     //                << "\n";
     //           return 0;
     //      }

     //      while (true)
     //      {
     //           cout << "This is your menu:"
     //                << "\n";
     //           cout << "0. Exit"
     //                << "\n";
     //           cout << "1. View Information"
     //                << "\n";
     //           cout << "2. List House"
     //                << "\n";
     //           cout << "3. View Available Houses"
     //                << "\n";
     //           cout << "4. Request to Occupy House"
     //                << "\n";
     //           cout << "5. View Occupy Requests"
     //                << "\n";
     //           cout << "6. Rate Occupied Houses"
     //                << "\n";
     //           cout << "Enter your choice: ";
     //           int choice;
     //           cin >> choice;

     //           if (choice == 0)
     //           {
     //                break;
     //           }
     //           else if (choice == 1)
     //           {
     //                system.ViewMemberInfo(member_id);
     //           }
     //           else if (choice == 2)
     //           {
     //                cout << "Enter start date (YYYY-MM-DD): ";
     //                string start_date;
     //                cin >> start_date;
     //                cout << "Enter end date (YYYY-MM-DD): ";
     //                string end_date;
     //                cin >> end_date;
     //                cout << "Enter points per day: ";
     //                int points_per_day;
     //                cin >> points_per_day;
     //                cout << "Enter minimum required occupier rating (optional, leave blank for no requirement): ";
     //                string min_rating_str;
     //                cin >> min_rating_str;
     //                int min_rating = -1;
     //                if (min_rating_str != "")
     //                {
     //                     min_rating = std::stoi(min_rating_str);
     //                }
     //                system.ListHouse(member_id, start_date, end_date, points_per_day, min_rating);
     //           }
     //           else if (choice == 3)
     //           {
     //                cout << "Enter start date (YYYY-MM-DD): ";
     //                string start_date;
     //                cin >> start_date;
     //                cout << "Enter end date (YYYY-MM-DD): ";
     //                string end_date;
     //                cin >> end_date;
     //                cout << "Enter city: ";
     //                string city;
     //                cin >> city;
     //                system.ViewAvailableHouses(member_id, start_date, end_date, city);
     //           }
     //           else if (choice == 4)
     //           {
     //                cout << "Enter house ID: ";
     //                int house_id;
     //                cin >> house_id;
     //                cout << "Enter start date (YYYY-MM-DD): ";
     //                string start_date;
     //                cin >> start_date;
     //                cout << "Enter end date (YYYY-MM-DD): ";
     //                string end_date;
     //                cin >> end_date;
     //                system.RequestToOccupyHouse(member_id, house_id, start_date, end_date);
     //           }
     //           else if (choice == 5)
     //           {
     //                system.ViewOccupyRequests(member_id);
     //           }
     //           else if (choice == 6)
     //           {
     //                cout << "Enter house ID: ";
     //                int house_id;
     //                cin >> house_id;
     //                cout << "Enter score (1-10): ";
     //                int score;
     //                cin >> score;
     //                cout << "Enter comment: ";
     //                string comment;
     //                cin >> comment;
     //                system.LeaveReview(member_id, house_id, score, comment);
     //           }
     //           else
     //           {
     //                cout << "Error: Invalid menu choice."
     //                     << "\n";
     //           }
     //      }
     // }
     // else if (user_type == 3)
     // {
     //      // Admin user
     //      while (true)
     //      {
     //           cout << "This is your menu:"
     //                << "\n";
     //           cout << "0. Exit"
     //                << "\n";
     //           cout << "1. View All Members"
     //                << "\n";
     //           cout << "2. View All Houses"
     //                << "\n";
     //           cout << "Enter your choice: ";
     //           int choice;
     //           cin >> choice;

     //           if (choice == 0)
     //           {
     //                break;
     //           }
     //           else if (choice == 1)
     //           {
     //                system.ViewAllMembers();
     //           }
     //           else if (choice == 2)
     //           {
     //                system.ViewAllHouses();
     //           }
     //           else
     //           {
     //                cout << "Error: Invalid menu choice."
     //                     << "\n";
     //           }
     //      }
     // }
     // else
     // {
     //      cout << "Error: Invalid user type."
     //           << "\n";
     // }

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
