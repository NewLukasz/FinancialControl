#ifndef FINANCIALCONTROL_H
#define FINANCIALCONTROL_H

#include <iostream>
#include <cstdlib>
#include "AccesoryFunctions.h"
#include "UserManager.h"
using namespace std;

class FinancialControl{
    UserManager userManager;
    const string FILE_NAME_FOR_FILE_WITH_USERS;
public:
    FinancialControl(string fileNameForFileWithUsers) : userManager(fileNameForFileWithUsers), FILE_NAME_FOR_FILE_WITH_USERS(fileNameForFileWithUsers){};
    char chooseOptionFromMainMenu();
    char chooseOptionFromUserMenu();
    void userRegister();
    int loginUser();
    int logout();
};

#endif // FINANCIALCONTROL_H
