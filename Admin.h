#include "Data.h"
#include <iostream>
#include <string>
#include <vector>


#ifndef ADMIN_H
#define ADMIN_H

using namespace std;

class Admin
{
private:
    int id;
    string username;
    string password;

public:
    Admin();
    ~Admin();
    Admin(int id, string username, string password);
};

#endif