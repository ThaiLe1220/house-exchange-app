#include "Request.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Empty Constructor
Request::Request() {}

// Destructor
Request::~Request() {}

// Constructor
Request::Request(
    int id,
    Member occupant,
    House house,
    bool requestStatus,
    double houseRating,
    double occupantRating,
    string houseReview,
    string occupantReview)
{
    this->id = id;
    this->occupant = occupant;
    this->house = house;
    this->requestStatus = requestStatus;
    this->houseRating = houseRating;
    this->occupantRating = occupantRating;
    this->houseReview = houseReview;
    this->occupantReview = occupantReview;
}

// GETTERS
int Request::getId() { return this->id; }
Member Request::getOccupant() { return this->occupant; }
House Request::getHouse() { return this->house; }
bool Request::getRequestStatus() { return this->requestStatus; }
double Request::getHouseRating() { return this->houseRating; }
double Request::getOccupantRating() { return this->occupantRating; }
string Request::getHouseReview() { return this->houseReview; }
string Request::getOccupantReview() { return this->occupantReview; }

// SETTERS
void Request::setId(int id) { this->id = id; }
void Request::setOccupant(Member occupant) { this->occupant = occupant; }
void Request::setHouse(House house) { this->house = house; }
void Request::setRequestStatus(bool status) { this->requestStatus = status; }
void Request::setHouseRating(double houseRating) { this->houseRating = houseRating; }
void Request::setOccupantRating(double occupantRating) { this->occupantRating = occupantRating; }
void Request::setHouseReview(string houseReview) { this->houseReview = houseReview; }
void Request::setOccupantReview(string occupantReview) { this->occupantReview = occupantReview; }

// METHODS
void Request::showAllRequestAttributes()
{
    cout << "   " << setw(10) << "request id"
         << " | " << setw(11) << "occupant id"
         << " | " << setw(10) << "house id"
         << " | " << setw(15) << "request status"
         << " | " << setw(14) << "house rating"
         << " | " << setw(16) << "occupant rating"
         << " | " << setw(20) << "house review"
         << " | " << setw(15) << "occpant review\n";
}

void Request::showAllRequestInfo()
{
    cout << setprecision(2);
    cout << boolalpha;
    if (this->requestStatus == false)
    {
        cout << "   " << setw(10) << this->id
             << " | " << setw(11) << this->occupant.getId()
             << " | " << setw(10) << this->house.getId()
             << " | " << setw(15) << this->requestStatus
             << " | " << setw(14) << ""
             << " | " << setw(16) << ""
             << " | " << setw(20) << ""
             << " | " << setw(15) << ""
             << "\n";
    }

    if (this->requestStatus == true)
    {
        cout << "   " << setw(10) << this->id
             << " | " << setw(11) << this->occupant.getId()
             << " | " << setw(10) << this->house.getId()
             << " | " << setw(15) << this->requestStatus
             << " | " << setw(14) << this->houseRating
             << " | " << setw(16) << this->occupantRating
             << " | " << setw(20) << this->houseReview
             << " | " << setw(20) << this->occupantReview << "\n";
    }
}

void Request::showAll()
{
    showAllRequestAttributes();
    showAllRequestInfo();
}
void Request::showOccupantRatingReviewAttributes()
{
    cout << "   " << setw(11) << "occupant id"
         << " | " << setw(20) << "house occupied id"
         << " | " << setw(16) << "occupant rating"
         << " | " << setw(20) << "occpant review\n";
}

void Request::showHouseRatingReviewAttributes()
{
    cout << "   " << setw(20) << "house occupied id"
         << " | " << setw(11) << "occupant id"
         << " | " << setw(14) << "house rating"
         << " | " << setw(20) << "house review\n";
}

void Request::showOccupantRatingReview()
{
    cout << "   " << setw(11) << this->occupant.getId()
         << " | " << setw(20) << this->house.getId()
         << " | " << setw(16) << this->occupantRating
         << " | " << setw(20) << this->occupantReview << "\n";
}

void Request::showHouseRatingReview()
{
    cout << "   " << setw(20) << this->house.getId()
         << " | " << setw(11) << this->occupant.getId()
         << " | " << setw(14) << this->houseRating
         << " | " << setw(20) << this->houseReview << "\n";
}
