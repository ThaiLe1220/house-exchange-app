#include "Data.h"

#ifndef ADMIN_H
#define ADMIN_H

using namespace std;

class Admin
{
private:
    string username = "admin";
    string password = "admin";

public:
    Admin();
    ~Admin();
    string getUsernamme();
    string getPassword();
};

#endif