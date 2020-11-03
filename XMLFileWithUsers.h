#ifndef XMLFILEWITHUSERS_H
#define XMLFILEWITHUSERS_H

#include <iostream>
#include <vector>
#include "Markup.h"
#include "User.h"
using namespace std;

class XMLFileWithUsers{
    const string fileNameForFileWithUsers;
public:
    XMLFileWithUsers(string FILENAMEFORFILEWITHUSERS) : fileNameForFileWithUsers(FILENAMEFORFILEWITHUSERS){};
    void addUserToFile(User user);
    vector <User> loadUsersFromFile();
};

#endif
