#include <string>
#include <iostream>

#ifndef HOUSE_H
#define HOUSE_H

using namespace std;

class House
{
private:
    int id = 0;
    string location = " ";
    string description = " ";
    double houseRating = 0;
    double minOccupantScore = -10;
    double consumingPoint = 0;
    string startDate = " ";
    string endDate = " ";
    bool occupyStatus = false;

public:
    House();
    ~House();
    House(
        int id,
        string location,
        string description,
        double houseRating,
        double minOccupantScore,
        double consumingPoint,
        string startDate,
        string endDate,
        bool occupyStatus);

    int getId();
    string getLocation();
    string getDescription();
    double getHouseRating();
    double getMinOccupantScore();
    double getConsumingPoint();
    string getStartDate();
    string getEndDate();
    bool getOccupyStatus();

    void setId(int id);
    void setLocation(string location);
    void setDescription(string description);
    void setHouseRating(double houseRating);
    void setMinOccupantScore(double minOccupantScore);
    void setConsumingPoint(double consumingPoint);
    void setStartDate(string startDate);
    void setEndDate(string endDate);
    void setOccupyStatus(bool Occpystatus);

    void showAllHouseAttributes();
    void showAllHouseInfo();
    void showHouseAttributesforGuest();
    void showHouseforGuest();
    void showAll();
};

#endif