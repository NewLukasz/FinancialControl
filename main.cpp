#include <iostream>
#include "FinancialControl.h"
using namespace std;

int main() {
    FinancialControl financialControl;
    int idLoggedInUser=0;
    char choice;

    while(true) {
        if(idLoggedInUser==0) {
            choice=financialControl.chooseOptionFromMainMenu();
            switch(choice) {
            case '1':
                financialControl.userRegister();
                break;
            case '2':
                idLoggedInUser=financialControl.loginUser();
                cout<<idLoggedInUser<<endl;
                break;
            case '3':
                exit(0);
                break;
            default:
                cout<<endl<<"There no option like: "<<choice<<" Try again"<<endl;
                system("pause");
                break;
            }
        } else {
            break;
        }
    }

}
