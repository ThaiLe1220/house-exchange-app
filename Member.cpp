#include "Member.h"

#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

// Empty Constructor
Member::Member() {}

// Destructor
Member::~Member() {}

// Constructor
Member::Member(
    int id,
    string fullname,
    string username,
    string password,
    string phone,
    double creditPoint,
    double occupierRating,
    House house)
{
    this->id = id;
    this->fullname = fullname;
    this->username = username;
    this->password = password;
    this->phone = phone;
    this->creditPoint = creditPoint;
    this->occupierRating = occupierRating;
    this->house = house;
}

// GETTERS
int Member::getId() { return this->id; }
string Member::getFullname() { return this->fullname; }
string Member::getUsername() { return this->username; }
string Member::getPassword() { return this->password; }
string Member::getPhone() { return this->phone; }
double Member::getCreditPoint() { return this->creditPoint; }
double Member::getOccupierRating() { return this->occupierRating; }
House Member::getHouse() { return this->house; }

// SETTERS
void Member::setId(int id) { this->id = id; }
void Member::setFullname(string fullname) { this->fullname = fullname; }
void Member::setUsername(string username) { this->username = username; }
void Member::setPassword(string password) { this->password = password; }
void Member::setPhone(string phone) { this->phone = phone; }
void Member::setCreditPoint(int creditPoint) { this->creditPoint = creditPoint; }
void Member::setOccupierRating(double occupierRating) { this->occupierRating = occupierRating; }
void Member::setHouse(House house) { this->house = house; }

// METHODS

void Member::showAllMemberAttributes()
{
    cout << "   " << setw(10) << "member id"
         << " | " << setw(12) << "fullname"
         << " | " << setw(12) << "username"
         << " | " << setw(12) << "password"
         << " | " << setw(10) << "phone"
         << " | " << setw(12) << "credit point"
         << " | " << setw(15) << "occupier rating"
         << " | " << setw(8) << "house id\n";
}

void Member::showAllMemberInfo()
{
    cout << "   " << setw(10) << this->id
         << " | " << setw(12) << this->fullname
         << " | " << setw(12) << this->username
         << " | " << setw(12) << this->password
         << " | " << setw(10) << this->phone
         << " | " << setw(12) << this->creditPoint
         << " | " << setw(15) << this->occupierRating
         << " | " << setw(8) << this->house.getId() << "\n";
}

void Member::showAll()
{
    showAllMemberAttributes();
    showAllMemberInfo();
}
