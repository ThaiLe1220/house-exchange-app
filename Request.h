#include "Member.h"
#include "House.h"
#include <iostream>


#ifndef REQUEST_H
#define REQUEST_H


class Request
{
private:
    int id;
    Member occupant;
    House house;
    bool requestStatus;

public:
    Request();
    ~Request();
    Request(int id, Member occupant, House house, bool requestStatus);

    int getId();
    Member getOccupant();
    House getHouse();    
    bool getRequestStatus();

    void setId(int id);
    void setOccupant(Member occupant);
    void setHouse(House house);
    void setRequestStatus(bool status);
};

#endif