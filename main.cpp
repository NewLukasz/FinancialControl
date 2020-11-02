#include <iostream>
#include "FinancialControl.h"
using namespace std;

int main() {
    FinancialControl financialControl;
    char choice;

    while(true){
        choice=financialControl.chooseOptionFromMainMenu();
        switch(choice){
    case '1':
        financialControl.userRegister();
        break;
    case '2':
        cout<<"Logon is chosen one"<<endl;
        system("pause");
        break;
    case '3':
        exit(0);
        break;
    default:
        cout<<endl<<"There no option like: "<<choice<<" Try again"<<endl;
        system("pause");
        break;
        }
    }
}
