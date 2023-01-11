#include "House.h"
#include "Member.h"
#include "Request.h"

#include <iostream>
#include <vector>
#include <string>

#ifndef DATA_H
#define DATA_H

using namespace std;

class Data
{
private:
    vector<House> houseList;
    vector<Member> memberList;
    vector<Request> requestList;

public:
    Data();
    ~Data();
    Data(vector<House> houseList, vector<Member> memberList, vector<Request> requestList);

    vector<House> getHouseList();
    vector<Member> getMemberList();
    vector<Request> getRequestList();

    void setRequestList(vector<Request> requestList);
    void setHouseList(vector<House> houseList);
    void setMemberList(vector<Member> memberList);

    void addHouse(House house);
    void addMember(Member member);
    void addRequest(Request request);

    void removeHouse(House house);
    void removeMember(Member member);
    void removeRequest(Request request);

    void updateHouse(House house);
    void updateMember(Member member);
    void updateRequest(Request request);

    House getHouseById(int id);
    Member getMemberById(int id);
    Request getRequestById(int id);
    Member getMemberByUsername(string username);
    Member getMemberByHouseId(int id);
    bool verifyMemberByUsername(string username);                             // New function to verify member by username
    bool verifyMemberByUsernameAndPassword(string username, string password); // New function to verify member by username and password

    House createHouseforOccupant(string location, string description, string startDate, string endDate, double minOccupantScore, double consumingPorint);

    Request createRequestToOccupy(Member occupant, int houseId);
    vector<Request> deleteRequestFromRequestList(Request request, vector<Request> requests);


    void deleteHouseById(int id);
    void deleteOtherRequestAfterAccept(Request request, vector<Request> requests);
    void ViewAllMembers();
    void ViewAllHouses();
    void ViewAllRequests();
};

#endif