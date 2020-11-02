#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include <cstdlib>
#include "User.h"
#include "AccesoryFunctions.h"
using namespace std;

class UserManager{
    vector <User> users;
    User typeUserData();
    int idLoggedInUser;
public:
    void userRegister();
    int loginUser();
};

#endif // USERMANAGER_H
