#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include <cstdlib>
#include "User.h"
#include "AccesoryFunctions.h"
#include "XMLFileWithUsers.h"
using namespace std;

class UserManager{
    vector <User> users;
    User typeUserData();
    int idLoggedInUser;
    XMLFileWithUsers xmlFileWithUsers;

    bool checkLoginExists(string loginForCheck);
public:
    UserManager(string fileNameForFileWithUsers) : xmlFileWithUsers(fileNameForFileWithUsers){
        idLoggedInUser=0;
        users=xmlFileWithUsers.loadUsersFromFile();
    };
    void userRegister();
    int loginUser();
};

#endif // USERMANAGER_H
