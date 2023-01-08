#include "Request.h"
#include <iostream>
#include <iomanip>

using namespace std;

// Empty Constructor
Request::Request() {}

// Destructor
Request::~Request() {}

// Constructor
Request::Request(
    int id = 0,
    Member occupant = Member(),
    House house = House(),
    bool requestStatus = false)
{
    this->id = id;
    this->occupant = occupant;
    this->house = house;
    this->requestStatus = requestStatus;
}

// GETTERS
int Request::getId() { return this->id; }
Member Request::getOccupant() { return this->occupant; }
House Request::getHouse() { return this->house; }
bool Request::getRequestStatus() { return this->requestStatus; }

// SETTERS
void Request::setId(int id) { this->id = id; }
void Request::setOccupant(Member occupant) { this->occupant = occupant; }
void Request::setHouse(House house) { this->house = house; }
void Request::setRequestStatus(bool status) { this->requestStatus = status; }

// METHODS
