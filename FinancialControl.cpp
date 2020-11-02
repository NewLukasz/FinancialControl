#include "FinancialControl.h"

char FinancialControl::chooseOptionFromMainMenu(){
    char choice;
    system("cls");
    cout<<"   MAIN MENU   "<<endl;
    cout<<"1. Register"<<endl;
    cout<<"2. Login"<<endl;
    cout<<"3. Exit"<<endl;
    cout<<"Your choise: ";
    choice=AccesoryFunctions::getChar();

    return choice;
}

void FinancialControl::userRegister(){
    userManager.userRegister();
}

int FinancialControl::loginUser(){
    return userManager.loginUser();
}
