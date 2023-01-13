#include "Data.h"

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <iterator>
#include <fstream>
#include <chrono>
#include <bits/stdc++.h>

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
void Data::addHouse(House house) // add new house to data: houseList
{
    int maxId = 0;
    for (auto &h : this->houseList)
    {
        if (h.getId() > maxId)
        {
            maxId = h.getId();
        }
    }
    if (house.getId() == 0 && house.getLocation().compare(" ") != 0 &&
        house.getDescription().compare(" ") != 0)
    {
        house.setId(maxId + 1);
    }

    this->houseList.push_back(house);
}
void Data::addMember(Member member) // add new member to data: memberList
{
    int maxId = 0;
    for (auto &m : this->memberList)
    {
        if (m.getId() > maxId)
        {
            maxId = m.getId();
        }
    }
    if (member.getId() == 0)
    {
        member.setId(maxId + 1);
        member.setHouse(House());
    }
    this->memberList.push_back(member);
}
void Data::addRequest(Request request) // add new request to data: requestList
{
    int maxId = 0;
    for (auto &r : this->requestList)
    {
        if (r.getId() > maxId)
        {
            maxId = r.getId();
        }
    }
    if (request.getId() == 0)
    {
        request.setId(maxId + 1);
    }
    this->requestList.push_back(request);
}

void Data::removeHouse(House house) // remove house from data: houseList
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
void Data::removeMember(Member member) // remove member from data: memberList
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

void Data::removeRequest(Request request) // remove request from data: requestList
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

void Data::updateHouse(House house) // update house to data: houseList, add new one if not exist
{
    bool status = false;
    for (auto &h : this->houseList)
    {
        if (h.getId() == house.getId() && h.getId() != 0)
        {
            status = true;
            removeHouse(h);
            addHouse(house);
        }
    }
    if (status == false || this->houseList.empty() == true)
        addHouse(house);
}
void Data::updateMember(Member member) // update member to data: memberList, add new one if not exist
{
    bool status = false;
    for (auto &m : this->memberList)
    {
        if (m.getId() == member.getId())
        {
            status = true;
            removeMember(m);
            addMember(member);
        }
    }
    if (status == false || this->memberList.empty() == true)
        addMember(member);
}
void Data::updateRequest(Request request) // update request to data: requestList, add new one if not exist
{
    bool status = false;
    for (auto &r : this->requestList)
    {
        if (r.getId() == request.getId())
        {
            status = true;
            removeRequest(r);
            addRequest(request);
        }
    }
    if (status == false || this->requestList.empty() == true)
        addRequest(request);
}

House Data::getHouseById(int id) // return house of data: houseList by id
{
    for (int i = 0; i < this->houseList.size(); i++)
    {
        if (this->houseList[i].getId() == id)
        {
            return this->houseList[i];
        }
    }
}
Member Data::getMemberById(int id) // return member of data: memberList by id
{
    for (int i = 0; i < this->memberList.size(); i++)
    {
        if (this->memberList[i].getId() == id)
        {
            return this->memberList[i];
        }
    }
}
Request Data::getRequestById(int id) // return request of data: requestList by id
{
    for (int i = 0; i < this->requestList.size(); i++)
    {
        if (this->requestList[i].getId() == id)
        {
            return this->requestList[i];
        }
    }
}
Member Data::getMemberByUsername(string username) // return member of data: memberList by username
{
    for (int i = 0; i < this->memberList.size(); i++)
    {
        if (this->memberList[i].getUsername() == username)
        {
            return this->memberList[i];
        }
    }
}
Member Data::getMemberByHouseId(int id) // return member of data: memberList by Houseid
{
    for (int i = 0; i < this->memberList.size(); i++)
    {
        if (this->memberList[i].getHouse().getId() == id)
        {
            return this->memberList[i];
        }
    }
}
bool Data::verifyMemberByUsername(string username) // check if member is in data: memberList with username
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
bool Data::verifyMemberByUsernameAndPassword(string username, string password) // check if member is in data:memberList with username and password
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
bool Data::verifyHouseById(int id) // check if house is in data:houseList with id
{
    bool result = false;
    for (auto &h : this->houseList)
    {
        if (h.getId() == id && id != 0)
        {
            result = true;
        }
    }
    return result;
}

bool Data::verifyRequestById(int id) // check if request is in data:requestList with id
{
    bool result = false;
    for (auto &r : this->requestList)
    {
        if (r.getId() == id && id != 0)
        {
            result = true;
        }
    }
    return result;
}

Request Data::createRequestToOccupy(Member occupant, int houseId) // create new request with input occupant and houseId
{
    Request request;
    request.setOccupant(occupant);
    request.setHouse(getHouseById(houseId));
    request.setRequestStatus(false);
    return request;
}

void Data::deleteHouseById(int id) // delete house in data: houseList by Id
{
    for (int i = 0; i < this->houseList.size(); i++)
    {
        if (this->houseList[i].getId() == id)
        {
            this->houseList.erase(this->houseList.begin() + i);
        }
    }
}
void Data::deleteRequestByHouseId(int id) // delete request in data: requestList by Id
{
    for (auto &r : this->requestList)
    {
        if (r.getHouse().getId() == id)
        {
            removeRequest(r);
        }
    }
}

void Data::deleteOtherRequestAfterAccept(Request request, vector<Request> requests) // delete all other requests in a request list, but the input request
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

vector<Request> Data::deleteRequestFromRequestList(Request request, vector<Request> requests) // return list of requests with the input request deleted
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

void Data::ViewAllMembers() // print out all members in data: memberList
{
    Member m = Member();
    m.showAllMemberAttributes();
    for (int i = 0; i < this->memberList.size(); i++)
    {
        Member member = this->memberList[i];
        member.showAllMemberInfo();
    }
}

void Data::ViewAllHouses() // print out all houses in data: houseList
{
    House h = House();
    h.showAllHouseAttributes();
    for (int i = 0; i < this->houseList.size(); i++)
    {
        House house = this->houseList[i];
        house.showAllHouseInfo();
    }
}

void Data::ViewAllRequests() // print out all requests in data: requestList
{
    Request req = Request();
    req.showAllRequestAttributes();
    for (int i = 0; i < this->requestList.size(); i++)
    {
        Request request = this->requestList[i];
        request.showAllRequestInfo();
    }
}

void Data::writeDataToFile(string filename) // write data to file, with divided section for house, member and request, data is presented with sorted id
{
    vector<int> v; // use for sorting;

    ofstream myfile(filename);
    myfile << "[Member Data Start]" << endl;
    myfile << "id,,fullname,,username,,password,,phone,,creditPoint,,occupierRating,,houseId" << endl;
    for (auto &m : this->memberList)
    {
        v.push_back(m.getId());
    }
    sort(v.begin(), v.end());
    for (auto &n : v)
    {
        for (auto &m : this->memberList)
        {
            if (n == m.getId())
            {
                myfile
                    << m.getId() << ",,"
                    << m.getFullname() << ",,"
                    << m.getUsername() << ",,"
                    << m.getPassword() << ",,"
                    << m.getPhone() << ",,"
                    << m.getCreditPoint() << ",,"
                    << m.getOccupierRating() << ",,"
                    << m.getHouse().getId() << endl;
            }
        }
    }
    myfile << "[Member Data End]" << endl;
    myfile << "--------------------------------------------------------------------------" << endl;

    myfile << "[House Data Start]" << endl;
    myfile << "id,,location,,description,,houseRating,,minOccupantScore,,consumingPoint,,startDate,,endDate,,occupyStatus" << endl;
    v.clear();
    for (auto &h : this->houseList)
    {
        v.push_back(h.getId());
    }
    sort(v.begin(), v.end());
    for (auto &n : v)
    {
        for (auto &h : this->houseList)
        {
            if (n == h.getId())
            {
                myfile << h.getId() << ",,"
                       << h.getLocation() << ",,"
                       << h.getDescription() << ",,"
                       << h.getHouseRating() << ",,"
                       << h.getMinOccupantScore() << ",,"
                       << h.getConsumingPoint() << ",,"
                       << h.getStartDate() << ",,"
                       << h.getEndDate() << ",,"
                       << h.getOccupyStatus() << endl;
            }
        }
    }
    myfile << "[House Data End]" << endl;
    myfile << "--------------------------------------------------------------------------" << endl;

    myfile << "[Request Data Start]" << endl;
    myfile << "id,,occupantId,,houseId,,houseRating,,occupantRating,,houseReview,,occupantReview,,requestStatus" << endl;
    v.clear();
    for (auto &r : this->requestList)
    {
        v.push_back(r.getId());
    }
    sort(v.begin(), v.end());
    for (auto &n : v)
    {
        for (auto &r : this->requestList)
        {
            if (n == r.getId())
            {
                myfile << r.getId() << ",,"
                       << r.getOccupant().getId() << ",,"
                       << r.getHouse().getId() << ",,"
                       << r.getHouseRating() << ",,"
                       << r.getOccupantRating() << ",,"
                       << r.getHouseReview() << ",,"
                       << r.getOccupantReview() << ",,"
                       << r.getRequestStatus() << endl;
            }
        }
    }
    myfile << "[Request Data End]" << endl;
    myfile << "--------------------------------------------------------------------------" << endl;

    myfile.close();
}

void Data::readDataFromFile(string filename) // Read and extract data from file -> update to data
{
    int countTemp = 0;
    bool isMember = false;
    bool isHouse = false;
    bool isRequest = false;
    string myText;

    House houseFromFile;
    Member memberFromFile;
    Request requestFromFile;

    ifstream myfile(filename);
    while (getline(myfile, myText))
    {
        if (myText.find("[House Data Start]") != string::npos)
        {
            isHouse = true;
            countTemp = 0;
        }
        if (myText.find("[House Data End]") != string::npos)
        {
            isHouse = false;
        }

        if (isHouse && countTemp > 1)
        {
            int temp = 0;
            int prev = 0;
            for (int i = 0; i < myText.size() - 1; i++)
            {
                if (myText[i] == ',' && myText[i + 1] == ',')
                {
                    if (temp == 0) // id
                    {
                        houseFromFile.setId(stoi(myText.substr(0, i)));
                    }
                    else if (temp != 0 && i < myText.size() - 2)
                    {
                        if (temp == 1) // location
                        {
                            houseFromFile.setLocation(myText.substr(prev + 2, i - (prev + 2)));
                        }
                        else if (temp == 2) // description
                        {
                            houseFromFile.setDescription(myText.substr(prev + 2, i - (prev + 2)));
                        }
                        else if (temp == 3) // houseRating
                        {
                            houseFromFile.setHouseRating(stoi(myText.substr(prev + 2, i - (prev + 2))));
                        }
                        else if (temp == 4) // minOccupantScore
                        {
                            houseFromFile.setMinOccupantScore(stoi(myText.substr(prev + 2, i - (prev + 2))));
                        }
                        else if (temp == 5) // consumingPoint
                        {
                            houseFromFile.setConsumingPoint(stoi(myText.substr(prev + 2, i - (prev + 2))));
                        }
                        else if (temp == 6) // startDate
                        {
                            houseFromFile.setStartDate(myText.substr(prev + 2, i - (prev + 2)));
                        }
                        else if (temp == 7) // endDate
                        {
                            houseFromFile.setEndDate(myText.substr(prev + 2, i - (prev + 2)));
                        }
                    }
                    temp++;
                    prev = i;
                }
            }
            // occupyStatus
            if (myText.back() == '0')
            {
                houseFromFile.setOccupyStatus(false);
            }
            else
            {
                houseFromFile.setOccupyStatus(true);
            }
            // houseFromFile.showAllHouseInfo();
            updateHouse(houseFromFile);
        }
        countTemp++;
    }
    myfile.close();

    ifstream myfile2(filename);
    while (getline(myfile2, myText))
    {
        if (myText.find("[Member Data Start]") != string::npos)
        {
            isMember = true;
            countTemp = 0;
        }
        if (myText.find("[Member Data End]") != string::npos)
        {
            isMember = false;
        }

        if (myText.find("[Request Data Start]") != string::npos)
        {
            isRequest = true;
            countTemp = 0;
        }
        if (myText.find("[Request Data End]") != string::npos)
        {
            isRequest = false;
        }

        if (isMember && countTemp > 1)
        {
            int temp = 0;
            int prev = 0;
            for (int i = 0; i < myText.size() - 1; i++)
            {
                if (myText[i] == ',' && myText[i + 1] == ',')
                {
                    if (temp == 0) // id
                    {
                        memberFromFile.setId(stoi(myText.substr(0, i)));
                    }
                    else if (temp != 0 && i < myText.size() - 2)
                    {
                        if (temp == 1) // fullname
                        {
                            memberFromFile.setFullname(myText.substr(prev + 2, i - (prev + 2)));
                        }
                        else if (temp == 2) // username
                        {
                            memberFromFile.setUsername(myText.substr(prev + 2, i - (prev + 2)));
                        }
                        else if (temp == 3) // password
                        {
                            memberFromFile.setPassword(myText.substr(prev + 2, i - (prev + 2)));
                        }
                        else if (temp == 4) // phone
                        {
                            memberFromFile.setPhone(myText.substr(prev + 2, i - (prev + 2)));
                        }
                        else if (temp == 5) // creditPoint
                        {
                            memberFromFile.setCreditPoint(stoi(myText.substr(prev + 2, i - (prev + 2))));
                        }
                        else if (temp == 6) // occupierRating
                        {
                            memberFromFile.setOccupierRating(stoi(myText.substr(prev + 2, i - (prev + 2))));
                            int hId = stoi(myText.substr(i + 2, myText.size() - i - 1 - 1));
                            if (hId == 0)
                            {
                                memberFromFile.setHouse(House());
                            }
                            else
                            {
                                memberFromFile.setHouse(getHouseById(hId));
                            }
                        }
                    }
                    temp++;
                    prev = i;
                }
            }
            // memberFromFile.showAllMemberInfo();
            updateMember(memberFromFile);
        }

        if (isRequest && countTemp > 1)
        {
            int temp = 0;
            int prev = 0;
            for (int i = 0; i < myText.size() - 1; i++)
            {
                if (myText[i] == ',' && myText[i + 1] == ',')
                {
                    if (temp == 0) // id
                    {
                        requestFromFile.setId(stoi(myText.substr(0, i)));
                    }
                    else if (temp != 0 && i < myText.size() - 2)
                    {
                        if (temp == 1) // occupantId
                        {
                            requestFromFile.setOccupant(getMemberById(stoi(myText.substr(prev + 2, i - (prev + 2)))));
                        }
                        else if (temp == 2) // houseId
                        {
                            requestFromFile.setHouse(getHouseById(stoi(myText.substr(prev + 2, i - (prev + 2)))));
                        }
                        else if (temp == 3) // houseRating
                        {
                            requestFromFile.setHouseRating(stoi(myText.substr(prev + 2, i - (prev + 2))));
                        }
                        else if (temp == 4) // occupantRating
                        {
                            requestFromFile.setOccupantRating(stoi(myText.substr(prev + 2, i - (prev + 2))));
                        }
                        else if (temp == 5) // houseReview
                        {
                            requestFromFile.setHouseReview(myText.substr(prev + 2, i - (prev + 2)));
                        }
                        else if (temp == 6) // occupantReview
                        {
                            requestFromFile.setOccupantReview(myText.substr(prev + 2, i - (prev + 2)));
                        }
                    }
                    temp++;
                    prev = i;
                }
            }
            // requestStatus
            if (myText.back() == '0')
            {
                requestFromFile.setRequestStatus(false);
            }
            else
            {
                requestFromFile.setRequestStatus(true);
            }
            // requestFromFile.showAllRequestInfo();
            updateRequest(requestFromFile);
        }
        countTemp++;
    }
    myfile2.close();
}

void Data::updateHouseRating() // calculate average point of all rating towards one house, applied for all houses -> then update to data
{
    double sum = 0;
    double count = 0;
    House h;
    for (auto &r : this->requestList)
    {
        if ((r.getHouseRating() != 0 || r.getHouseReview().compare(" ") != 0) && r.getRequestStatus() == true) // has been rated
        {
            sum = 0;
            count = 0;
            for (auto &req : this->requestList)
            {
                if ((req.getHouseRating() != 0 || req.getHouseReview().compare(" ") != 0) && req.getRequestStatus() == true) // has been rated
                {
                    if (r.getHouse().getId() == req.getHouse().getId())
                    {
                        sum += req.getHouseRating();
                        count++;
                    }
                    h = r.getHouse();
                    h.setHouseRating(sum / count);
                    updateHouse(h);
                }
            }
        }
    }
}
void Data::updateOccupantRating() // calculate average point of all rating towards one occupant, applied for all occupants -> then update to data
{
    double sum = 0;
    double count = 0;
    Member m;
    for (auto &r : this->requestList)
    {
        if ((r.getOccupantRating() != 0 || r.getOccupantReview().compare(" ") != 0) && r.getRequestStatus() == true) // has been rated
        {
            sum = 0;
            count = 0;
            for (auto &req : this->requestList)
            {
                if ((req.getOccupantRating() != 0 || req.getOccupantReview().compare(" ") != 0) && req.getRequestStatus() == true) // has been rated
                {
                    if (r.getOccupant().getId() == req.getOccupant().getId())
                    {
                        sum += req.getOccupantRating();
                        count++;
                    }
                    m = r.getOccupant();
                    m.setOccupierRating(sum / count);
                    updateMember(m);
                }
            }
        }
    }
}