#include "House.h"

#include <iostream>
#include <string>
#include <vector>

#ifndef MEMBER_H
#define MEMBER_H

using namespace std;

class Member
{
private:
    int id;
    string fullname;
    string username;
    string password;
    string phone;
    int creditPoint;
    double occupierRating;
    House house;

public:
    Member();
    ~Member();
    Member(
        int id,
        string fullname,
        string username,
        string password,
        string phone,
        int creditPoint,
        double occupierRating,
        House house);

    int getId();
    string getFullname();
    string getUsername();
    string getPassword();
    string getPhone();
    int getCreditPoint();
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
};

#endif