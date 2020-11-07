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
    const string FILE_NAME_FOR_FILE_WITH_INCOMES;
    const string FILE_NAME_FOR_FILE_WITH_EXPENSES;
public:
    FinancialControl(string fileNameForFileWithUsers, string fileNameForFileWithIncomes, string fileNameForFileWithExpenses) :
        userManager(fileNameForFileWithUsers), FILE_NAME_FOR_FILE_WITH_USERS(fileNameForFileWithUsers), FILE_NAME_FOR_FILE_WITH_INCOMES(fileNameForFileWithIncomes),FILE_NAME_FOR_FILE_WITH_EXPENSES(fileNameForFileWithExpenses){
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
    void showBalanceFromCurrentMonth();
    void showBalanceFromPreviousMonth();
    void showBalanceFromCustomPeriodOfTime();
};

#endif // FINANCIALCONTROL_H
