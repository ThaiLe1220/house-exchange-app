#include "Data.h"

#ifndef ADMIN_H
#define ADMIN_H

using namespace std;

class Admin
{
private:
    int id = 0;
    string username = "admin";
    string password = "admin";

public:
    Admin();
    ~Admin();
    Admin(int id, string username, string password);
};

#endif