#include <iostream>
#include <string>

#ifndef HOUSE_H
#define HOUSE_H

using namespace std;

class House
{
private:
    int id;
    string location;
    string description;
    double houseRating;
    double minOccupantScore;
    string startDate;
    string endDate;
    bool occupyStatus;

public:
    House();
    ~House();
    House(
        int id,
        string location,
        string description,
        double houseRating,
        double minOccupantScore,
        string startDate,
        string endDate,
        bool occupyStatus);

    int getId();
    string getLocation();
    string getDescription();
    double getHouseRating();
    double getMinOccupantScore();
    string getStartDate();
    string getEndDate();
    bool getOccupyStatus();

    void setId(int id);
    void setLocation(string location);
    void setDescription(string description);
    void setHouseRating(double houseRating);
    void setMinOccupantScore(double minOccupantScore);
    void setStartDate(string startDate);
    void setEndDate(string endDate);
    void setOccupyStatus(bool Occpystatus);
};

#endif