#include "Member.h"

#include <iostream>

using namespace std;

// Empty Constructor
Member::Member() {}

// Destructor
Member::~Member() {}

// Constructor
Member::Member(
    int id = 0,
    string fullname = "",
    string username = "",
    string password = "",
    string phone = "",
    int creditPoint = 0,
    double occupierRating = 0,
    House house = House())
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
int Member::getCreditPoint() { return this->creditPoint; }
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