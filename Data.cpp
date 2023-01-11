#include "Data.h"

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <iterator>

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

void Data::removeHouse(House house)
{
    House h = House();
    vector<House> houses = this->houseList;
    vector<House>::iterator hou = houses.begin();
    for (auto i = houses.begin(); i != houses.end(); i++)
    {
        h = *i;
        if (h.getId() == house.getId())
        {
            houses.erase(i);
            i--;
        }
    }
    this->houseList = houses;
}
void Data::removeMember(Member member)
{
    Member m = Member();
    vector<Member> members = this->memberList;
    vector<Member>::iterator mem = members.begin();
    for (auto i = members.begin(); i != members.end(); i++)
    {
        m = *i;
        if (m.getId() == member.getId())
        {
            members.erase(i);
            i--;
        }
    }
    this->memberList = members;
}

void Data::removeRequest(Request request)
{
    Request r = Request();
    vector<Request> requests = this->requestList;
    vector<Request>::iterator req = requests.begin();
    for (auto i = requests.begin(); i != requests.end(); i++)
    {
        r = *i;
        if (r.getId() == request.getId())
        {
            requests.erase(i);
            i--;
        }
    }
    this->requestList = requests;
}

void Data::updateHouse(House house)
{
    for (auto &h : this->houseList)
    {
        if (h.getId() == house.getId())
        {
            removeHouse(h);
            addHouse(house);
        }
    }
}
void Data::updateMember(Member member)
{
    for (auto &m : this->memberList)
    {
        if (m.getId() == member.getId())
        {
            removeMember(m);
            addMember(member);
        }
    }
}
void Data::updateRequest(Request request)
{
    for (auto &r : this->requestList)
    {
        if (r.getId() == request.getId())
        {
            removeRequest(r);
            addRequest(request);
        }
    }
}

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
bool Data::verifyMemberByUsername(string username)
{
    bool result = false;
    for (int i = 0; i < this->memberList.size(); i++)
    {
        if (this->memberList[i].getUsername() == username)
        {
            result = true;
        }
    }
    return result;
}
bool Data::verifyMemberByUsernameAndPassword(string username, string password)
{
    bool result = false;
    for (int i = 0; i < this->memberList.size(); i++)
    {
        if (this->memberList[i].getUsername() == username && this->memberList[i].getPassword() == password)
        {
            result = true;
        }
    }
    return result;
}

House Data::createHouseforOccupant(string location, string description, string startDate, string endDate, double minOccupantScore, double consumingPoint)
{
    // TODO: how to get unique id, create a method
    int id = 0;
    House h = House();
    h.setId(id);
    h.setLocation(location);
    h.setDescription(description);
    h.setStartDate(startDate);
    h.setEndDate(endDate);
    h.setMinOccupantScore(minOccupantScore);
    h.setConsumingPoint(consumingPoint);
    // TODO:check if house exits in list or nor, create a method
    addHouse(h);
    return h;
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

void Data::deleteHouseById(int id)
{
    for (int i = 0; i < this->houseList.size(); i++)
    {
        if (this->houseList[i].getId() == id)
        {
            this->houseList.erase(this->houseList.begin() + i);
        }
    }
}

void Data::deleteOtherRequestAfterAccept(Request request, vector<Request> requests)
{
    for (auto &r : this->requestList)
    {
        for (int i = 0; i < requests.size(); i++)
        {
            if (r.getId() == requests[i].getId())
            {
                removeRequest(r);
            }
        }
    }
    addRequest(request);
}

vector<Request> Data::deleteRequestFromRequestList(Request request, vector<Request> requests)
{

    Request r = Request();
    vector<Request>::iterator req = requests.begin();
    for (auto i = requests.begin(); i != requests.end(); i++)
    {
        r = *i;
        if (r.getId() == request.getId())
        {
            requests.erase(i);
            i--;
        }
    }
    return requests;
}

void Data::ViewAllMembers()
{
    Member m = Member();
    m.showAllMemberAttributes();
    for (int i = 0; i < this->memberList.size(); i++)
    {
        Member member = this->memberList[i];
        member.showAllMemberInfo();
    }
}

void Data::ViewAllHouses()
{
    House h = House();
    h.showAllHouseAttributes();
    for (int i = 0; i < this->houseList.size(); i++)
    {
        House house = this->houseList[i];
        house.showAllHouseInfo();
    }
}

void Data::ViewAllRequests()
{
    Request req = Request();
    req.showAllRequestAttributes();
    for (int i = 0; i < this->requestList.size(); i++)
    {
        Request request = this->requestList[i];
        request.showAllRequestInfo();
    }
}