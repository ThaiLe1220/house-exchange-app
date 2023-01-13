#include "House.h"

#include <string>
#include <iostream>

#ifndef MEMBER_H
#define MEMBER_H

using namespace std;

class Member
{
private:
    int id = 0;
    string fullname = " ";
    string username = " ";
    string password = " ";
    string phone = " ";
    double creditPoint = 500;
    double occupierRating = 0;
    House house = House();

public:
    Member();
    ~Member();
    Member(
        int id,
        string fullname,
        string username,
        string password,
        string phone,
        double creditPoint,
        double occupierRating,
        House house);

    int getId();
    string getFullname();
    string getUsername();
    string getPassword();
    string getPhone();
    double getCreditPoint();
    double getOccupierRating();
    House getHouse();

    void setId(int id);
    void setFullname(string fullname);
    void setUsername(string username);
    void setPassword(string password);
    void setPhone(string phone);
    void setCreditPoint(int creditPoint);
    void setOccupierRating(double occupierRating);
    void setHouse(House house);

    void showAllMemberAttributes();
    void showAllMemberInfo();
    void showAll();
};

#endif