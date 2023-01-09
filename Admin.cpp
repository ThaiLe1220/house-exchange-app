#include "Admin.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

Admin::Admin() {}
Admin::~Admin() {}

Admin::Admin(int id = 0, string username = "admin", string password = "admin") 
{
    this->id = id;
    this->username = username;
    this->password = password;
}


