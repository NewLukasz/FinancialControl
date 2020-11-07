#include "FinancialControl.h"

char FinancialControl::chooseOptionFromMainMenu(){
    char choice;
    system("cls");
    cout<<">>>MAIN MENU<<<"<<endl;
    cout<<"1. Register"<<endl;
    cout<<"2. Login"<<endl;
    cout<<"3. Exit"<<endl;
    cout<<"Your choise: ";
    choice=AccesoryFunctions::getChar();

    return choice;
}

char FinancialControl::chooseOptionFromUserMenu(){
    char choice;
    system("cls");
    cout<<">>>USER MENU<<<"<<endl;
    cout<<"1. Add income"<<endl;
    cout<<"2. Add expense"<<endl;
    cout<<"3. Balance from current month"<<endl;
    cout<<"4. Balance from previous month"<<endl;
    cout<<"5. Balance from custom period of time"<<endl;
    cout<<"6. Change password"<<endl;
    cout<<"9. Logout"<<endl;
    cout<<"Your choice: ";

    choice=AccesoryFunctions::getChar();

    return choice;
}

void FinancialControl::userRegister(){
    userManager.userRegister();
}

int FinancialControl::loginUser(){
    int idLoggedInUser=userManager.loginUser();
    if(userManager.checkIfUserIsLogin()){
        financialManager = new FinancialManager(idLoggedInUser, FILE_NAME_FOR_FILE_WITH_INCOMES, FILE_NAME_FOR_FILE_WITH_EXPENSES);
    }
    return idLoggedInUser;
}

int FinancialControl::logout(){
    return userManager.logout();
}

void FinancialControl::addIncome(){
    financialManager->addIncome();
}

void FinancialControl::addExpense(){
    financialManager->addExpense();
}

void FinancialControl::showBalanceFromCurrentMonth(){
    financialManager->showBalanceFromCurrentMonth();
}
