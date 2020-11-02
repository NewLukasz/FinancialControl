#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include <cstdlib>
#include "User.h"
#include "AccesoryFunctions.h"
#include "XMLfile.h"
using namespace std;

class UserManager{
    vector <User> users;
    User typeUserData();
    int idLoggedInUser;
    XMLFileWithUsers xmlFileWithUsers;
public:
    void userRegister();
    int loginUser();
};

#endif // USERMANAGER_H
