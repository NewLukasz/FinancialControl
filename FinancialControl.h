#ifndef FINANCIALCONTROL_H
#define FINANCIALCONTROL_H

#include <iostream>
#include <cstdlib>
#include "AccesoryFunctions.h"
#include "UserManager.h"
#include "FinancialManager.h"
using namespace std;

class FinancialControl{
    UserManager userManager;
    FinancialManager *financialManager;
    const string FILE_NAME_FOR_FILE_WITH_USERS;
public:
    FinancialControl(string fileNameForFileWithUsers) : userManager(fileNameForFileWithUsers), FILE_NAME_FOR_FILE_WITH_USERS(fileNameForFileWithUsers){
        financialManager=NULL;
    };
    ~FinancialControl(){
        delete financialManager;
        financialManager=NULL;
    }
    char chooseOptionFromMainMenu();
    char chooseOptionFromUserMenu();
    void userRegister();
    int loginUser();
    int logout();
    void addIncome();
    void addExpense();
};

#endif // FINANCIALCONTROL_H
