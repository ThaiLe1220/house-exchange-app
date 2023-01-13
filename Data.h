#include "House.h"
#include "Member.h"
#include "Request.h"

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

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

    void addHouse(House house);       // add new house to data: houseList
    void addMember(Member member);    // add new member to data: memberList
    void addRequest(Request request); // add new request to data: requestList

    void removeHouse(House house);       // remove house from data: houseList
    void removeMember(Member member);    // remove member from data: memberList
    void removeRequest(Request request); // remove request from data: requestList

    void updateHouse(House house);    // update house to data: houseList, add new one if not exist
    void updateMember(Member member); // update member to data: memberList, add new one if not exist
    void updateRequest(Request request); // update request to data: requestList, add new one if not exist

    House getHouseById(int id);                  // return house of data: houseList by id
    Member getMemberById(int id);                // return member of data: memberList by id
    Request getRequestById(int id);              // return request of data: requestList by id
    Member getMemberByUsername(string username); // return member of data: memberList by username
    Member getMemberByHouseId(int id);           // return member of data: memberList by Houseid

    bool verifyMemberByUsername(string username);                             // check if member is in data: memberList with username
    bool verifyMemberByUsernameAndPassword(string username, string password); // check if member is in data:memberList with username and password
    bool verifyHouseById(int id);                                             // check if house is in data:houseList with id
    bool verifyRequestById(int id);                                           // check if request is in data:requestList with id

    Request createRequestToOccupy(Member occupant, int houseId); // create new request with input occupant and houseId

    vector<Request> deleteRequestFromRequestList(Request request, vector<Request> requests); // return list of requests with the input request deleted

    void deleteOtherRequestAfterAccept(Request request, vector<Request> requests); // delete all other requests in a request list, but the input request

    void deleteHouseById(int id);        // delete house in data: houseList by Id
    void deleteRequestByHouseId(int id); // delete request in data: requestList by Id
    void ViewAllMembers();               // print out all members in data: memberList

    void ViewAllHouses();   // print out all houses in data: houseList
    void ViewAllRequests(); // print out all requests in data: requestList

    void writeDataToFile(string filename);  // write data to file, with divided section for house, member and request, data is presented with sorted id
    void readDataFromFile(string filename); // Read and extract data from file -> update to data

    void updateHouseRating();    // calculate average point of all rating towards one house, applied for all houses -> then update to data
    void updateOccupantRating(); // calculate average point of all rating towards one occupant, applied for all occupants -> then update to data
};

#endif