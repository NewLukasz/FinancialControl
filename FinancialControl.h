#ifndef FINANCIALCONTROL_H
#define FINANCIALCONTROL_H

#include <iostream>
#include <cstdlib>
#include "AccesoryFunctions.h"
#include "UserManager.h"
using namespace std;

class FinancialControl{
    UserManager userManager;
public:
    char chooseOptionFromMainMenu();
    void userRegister();
    int loginUser();
};

#endif // FINANCIALCONTROL_H
