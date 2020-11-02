#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include <cstdlib>
#include "User.h"
using namespace std;

class UserManager{
    vector <User> users;
    User typeUserData();
public:
    void userRegister();
};

#endif // USERMANAGER_H
