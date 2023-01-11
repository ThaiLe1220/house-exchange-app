#include "Admin.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

Admin::Admin() {}
Admin::~Admin() {}

Admin::Admin(int id, string username, string password) 
{
    this->id = id;
    this->username = username;
    this->password = password;
}


