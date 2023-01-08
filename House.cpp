

#include <iostream>
#include <iomanip>


#include "House.h"

using namespace std;

// Empty Constructor
House::House(){}

// Destructor
House::~House(){}

// Constructor
House::House(
    int id = 0,
    string location = "",
    string description = "",
    double houseRating = 0,
    double minOccupantScore = 0,
    string startDate = "",
    string endDate = "",
    bool occupyStatus = false)
{
    this->id = id;
    this->location = location;
    this->description = description;
    this->houseRating = houseRating;
    this->minOccupantScore = minOccupantScore;
    this->startDate = startDate;
    this->endDate = endDate;
    this->occupyStatus = occupyStatus;
}

// GETTERS
int House::getId() { return this->id; }
string House::getLocation() { return this->location; }
string House::getDescription() { return this->description; }
double House::getHouseRating() { return this->houseRating; }
double House::getMinOccupantScore() { return this->minOccupantScore; }
string House::getStartDate() { return this->startDate; }
string House::getEndDate() { return this->endDate; }
bool House::getOccupyStatus() { return this->occupyStatus; }

// SETTERS
void House::setId(int id) { this->id = id; }
void House::setLocation(string location) { this->location = location; }
void House::setDescription(string description) { this->description = description; }
void House::setHouseRating(double houseRating) { this->houseRating = houseRating; }
void House::setMinOccupantScore(double minOccupantScore) { this->minOccupantScore = minOccupantScore; }
void House::setStartDate(string startDate) { this->startDate = startDate; }
void House::setEndDate(string endDate) { this->endDate = endDate; }
void House::setOccupyStatus(bool occupyStatus) { this->occupyStatus = occupyStatus; }

// METHODS


