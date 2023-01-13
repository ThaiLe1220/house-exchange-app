#include "Member.h"
#include "House.h"
#include <iostream>

#ifndef REQUEST_H
#define REQUEST_H

class Request
{
private:
    int id = 0;
    Member occupant = Member();
    House house = House();
    bool requestStatus = false;
    double houseRating = 0;
    double occupantRating = 0;
    string houseReview = " ";
    string occupantReview = " ";

public:
    Request();
    ~Request();
    Request(int id, Member occupant, House house, bool requestStatus, double houseRating, double occupantRating, string houseReview, string occupantReview);

    int getId();
    Member getOccupant();
    House getHouse();
    bool getRequestStatus();
    double getHouseRating();
    double getOccupantRating();
    string getHouseReview();
    string getOccupantReview();

    void setId(int id);
    void setOccupant(Member occupant);
    void setHouse(House house);
    void setRequestStatus(bool status);
    void setHouseRating(double houseRating);
    void setOccupantRating(double occupantRating);
    void setHouseReview(string houseReview);
    void setOccupantReview(string occupantReview);

    void showAllRequestAttributes();
    void showAllRequestInfo();
    void showAll();
};

#endif