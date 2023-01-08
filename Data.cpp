#include "Data.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

Data::Data() {}
Data::~Data() {}

Data::Data(vector<House> houseList, vector<Member> memberList, vector<Request> requestList)
{
    this->houseList = houseList;
    this->memberList = memberList;
    this->requestList = requestList;
}

// GETTERS
vector<House> Data::getHouseList() { return this->houseList; }
vector<Member> Data::getMemberList() { return this->memberList; }
vector<Request> Data::getRequestList() { return this->requestList; }

// SETTERS
void Data::setRequestList(vector<Request> requestList) { this->requestList = requestList; }
void Data::setHouseList(vector<House> houseList) { this->houseList = houseList; }
void Data::setMemberList(vector<Member> memberList) { this->memberList = memberList; }

// METHODS
void Data::addHouse(House house) { this->houseList.push_back(house); }
void Data::addMember(Member member) { this->memberList.push_back(member); }
void Data::addRequest(Request request) { this->requestList.push_back(request); }

House Data::getHouseById(int id)
{
    for (int i = 0; i < this->houseList.size(); i++)
    {
        if (this->houseList[i].getId() == id)
        {
            return this->houseList[i];
        }
    }
}
Member Data::getMemberById(int id)
{
    for (int i = 0; i < this->memberList.size(); i++)
    {
        if (this->memberList[i].getId() == id)
        {
            return this->memberList[i];
        }
    }
}
Request Data::getRequestById(int id)
{
    for (int i = 0; i < this->requestList.size(); i++)
    {
        if (this->requestList[i].getId() == id)
        {
            return this->requestList[i];
        }
    }
}
Member Data::getMemberByUsername(string username)
{
    for (int i = 0; i < this->memberList.size(); i++)
    {
        if (this->memberList[i].getUsername() == username)
        {
            return this->memberList[i];
        }
    }
}
Member Data::getMemberByHouseId(int id)
{
    for (int i = 0; i < this->memberList.size(); i++)
    {
        if (this->memberList[i].getHouse().getId() == id)
        {
            return this->memberList[i];
        }
    }
}

Request Data::createRequestToOccupy(Member occupant, int houseId)
{
    Request request;
    request.setId(this->requestList.size()); // this id thing is compliated!!! Put it here for now...
    request.setOccupant(occupant);
    request.setHouse(getHouseById(houseId));
    request.setRequestStatus(false);
    return request;
}

void Data::ViewAllMembers()
{
    cout << "Member ID  | Fullname" << endl;
    for (int i = 0; i < this->memberList.size(); i++)
    {
        Member member = this->memberList[i];
        cout << member.getId() << " | "
             << member.getFullname() << endl;
    }
}

void Data::ViewAllHouses()
{
    cout << "House ID  | Location" << endl;
    for (int i = 0; i < this->houseList.size(); i++)
    {
        House house = this->houseList[i];
        cout << house.getId() << " | "
             << house.getLocation() << endl;
    }
}

void Data::ViewAllHouseListings()
{
    cout << "House ID | Owner ID | Start       | End         | Min Occupier Rating" << endl;
    for (int i = 0; i < this->houseList.size(); i++)
    {
        House house = this->houseList[i];
        cout << house.getId() << " | "
             << getMemberByHouseId(house.getId()).getId() << " | "
             << house.getStartDate() << " | "
             << house.getEndDate() << " | "
             << house.getMinOccupantScore() << endl;
    }
}

void Data::ViewAllRequests()
{
    cout << "ID  | Occupant ID | Owner ID | House ID | Request Status" << endl;
    for (int i = 0; i < this->requestList.size(); i++)
    {
        Request request = this->requestList[i];
        cout << request.getId() << " | "
             << request.getOccupant().getId() << " | "
             << getMemberByHouseId(request.getHouse().getId()).getId() << " | "
             << request.getHouse().getId() << " | "
             << request.getRequestStatus() << endl;
    }
}