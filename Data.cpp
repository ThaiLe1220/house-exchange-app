#include "Data.h"

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <iterator>
#include <fstream>
#include <chrono>

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
void Data::addHouse(House house)
{
    int maxId = 0;
    for (auto &h : this->houseList)
    {
        if (h.getId() > maxId)
        {
            maxId = h.getId();
        }
    }
    if (house.getId() == 0)
    {
        house.setId(maxId + 1);
    }

    this->houseList.push_back(house);
}
void Data::addMember(Member member)
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
    }
    this->memberList.push_back(member);
}
void Data::addRequest(Request request)
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
    bool status = false;
    for (auto &h : this->houseList)
    {
        if (h.getId() == house.getId())
        {
            status = true;
            removeHouse(h);
            addHouse(house);
        }
    }
    if (status == false || this->houseList.empty() == true)
        addHouse(house);
}
void Data::updateMember(Member member)
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
void Data::updateRequest(Request request)
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
bool Data::verifyHouseById(int id)
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

bool Data::verifyRequestById(int id)
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
void Data::deleteRequestByHouseId(int id)
{
    for (auto &r : this->requestList)
    {
        if (r.getHouse().getId() == id)
        {
            removeRequest(r);
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

void Data::writeDataToFile(string filename)
{
    ofstream myfile(filename);
    myfile << "[Member Data Start]" << endl;
    myfile << "id,,fullname,,username,,password,,phone,,creditPoint,,occupierRating,,houseId" << endl;
    for (auto &m : this->memberList)
    {

        myfile << m.getId() << ",,"
               << m.getFullname() << ",,"
               << m.getUsername() << ",,"
               << m.getPassword() << ",,"
               << m.getPhone() << ",,"
               << m.getCreditPoint() << ",,"
               << m.getOccupierRating() << ",,"
               << m.getHouse().getId() << endl;
    }
    myfile << "[Member Data End]" << endl;
    myfile << "--------------------------------------------------------------------------" << endl;

    myfile << "[House Data Start]" << endl;
    myfile << "id,,location,,description,,houseRating,,minOccupantScore,,consumingPoint,,startDate,,endDate,,occupyStatus" << endl;
    for (auto &h : this->houseList)
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
    myfile << "[House Data End]" << endl;
    myfile << "--------------------------------------------------------------------------" << endl;

    myfile << "[Request Data Start]" << endl;
    myfile << "id,,occupantId,,houseId,,houseRating,,occupantRating,,houseReview,,occupantReview,,requestStatus" << endl;
    for (auto &r : this->requestList)
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
    myfile << "[Request Data End]" << endl;
    myfile << "--------------------------------------------------------------------------" << endl;

    myfile.close();
}

void Data::readDataFromFile(string filename)
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
                            memberFromFile.setHouse(getHouseById(hId));
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
