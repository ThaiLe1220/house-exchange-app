

#include <iostream>
#include <iomanip>
#include <string>

#include "House.h"

using namespace std;

// Empty Constructor
House::House() {}

// Destructor
House::~House() {}

// Constructor
House::House(
    int id,
    string location,
    string description,
    double houseRating,
    double minOccupantScore,
    double consumingPoint,
    string startDate,
    string endDate,
    bool occupyStatus)
{
    this->id = id;
    this->location = location;
    this->description = description;
    this->houseRating = houseRating;
    this->minOccupantScore = minOccupantScore;
    this->consumingPoint = consumingPoint;
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
double House::getConsumingPoint() { return this->consumingPoint; }
string House::getStartDate() { return this->startDate; }
string House::getEndDate() { return this->endDate; }
bool House::getOccupyStatus() { return this->occupyStatus; }

// SETTERS
void House::setId(int id) { this->id = id; }
void House::setLocation(string location) { this->location = location; }
void House::setDescription(string description) { this->description = description; }
void House::setHouseRating(double houseRating) { this->houseRating = houseRating; }
void House::setMinOccupantScore(double minOccupantScore) { this->minOccupantScore = minOccupantScore; }
void House::setConsumingPoint(double consumingPoint) { this->consumingPoint = consumingPoint; }
void House::setStartDate(string startDate) { this->startDate = startDate; }
void House::setEndDate(string endDate) { this->endDate = endDate; }
void House::setOccupyStatus(bool occupyStatus) { this->occupyStatus = occupyStatus; }

// METHODS

void House::showAllHouseAttributes()
{
    cout << "   " << setw(8) << "house id"
         << " | " << setw(8) << "location"
         << " | " << setw(12) << "house rating"
         << " | " << setw(19) << "min occupant score"
         << " | " << setw(15) << "consuming point"
         << " | " << setw(12) << "period start"
         << " | " << setw(12) << "period end"
         << " | " << setw(13) << "occupy status"
         << " | " << setw(12) << "house description\n";
}
void House::showAllHouseInfo()
{
    cout << boolalpha;
    cout << "   " << setw(8) << this->id
         << " | " << setw(8) << this->location
         << " | " << setw(12) << this->houseRating
         << " | " << setw(19) << this->minOccupantScore
         << " | " << setw(15) << this->consumingPoint
         << " | " << setw(12) << this->startDate
         << " | " << setw(12) << this->endDate
         << " | " << setw(13) << this->occupyStatus
         << " | " << setw(12) << this->description << "\n";
}
void House::showHouseAttributesforGuest()
{
    cout << "   " << setw(8) << "house id"
         << " | " << setw(8) << "location"
         << " | " << setw(12) << "house rating"
         << " | " << setw(19) << "min occupant score"
         << " | " << setw(15) << "consuming point"
         << " | " << setw(12) << "period start"
         << " | " << setw(12) << "period end"
         << " | " << setw(12) << "house description\n";
}
void House::showHouseforGuest()
{
    cout << boolalpha;
    cout << "   " << setw(8) << this->id
         << " | " << setw(8) << this->location
         << " | " << setw(12) << this->houseRating
         << " | " << setw(19) << this->minOccupantScore
         << " | " << setw(15) << this->consumingPoint
         << " | " << setw(12) << this->startDate
         << " | " << setw(12) << this->endDate
         << " | " << setw(12) << this->description << "\n";
}

void House::showAll()
{
    showAllHouseAttributes();
    showAllHouseInfo();
}
