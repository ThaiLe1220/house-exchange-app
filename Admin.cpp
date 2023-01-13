#include "Admin.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

Admin::Admin() {}
Admin::~Admin() {}

string Admin::getUsernamme() { return this->username; }
string Admin::getPassword() { return this->password; }
