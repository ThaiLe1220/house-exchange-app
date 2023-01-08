#include "House.h"
#include "Member.h"
#include "Request.h"

#include <iostream>
#include <string>
#include <vector>

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

    void addHouse(House house); // dung khi ma member muon add house -> phat trien member co the xoa house, update house
    void addMember(Member member); // dung khi ma new user muon register thanh member (nho constraint la 500 credit) -> de member sua thong tin ca nhan, them credit ... // xoa tai khoan member
    void addRequest(Request request); // call chung vs createRequestToOccupy -- Thai lam roi

    House getHouseById(int id);
    Member getMemberById(int id);
    Request getRequestById(int id);
    Member getMemberByUsername(string username);
    Member getMemberByHouseId(int id);

    Request createRequestToOccupy(Member occupant, int houseId);

    void ViewAllMembers();
    void ViewAllHouses();
    void ViewAllHouseListings();
    void ViewAllRequests();

    
};

#endif 