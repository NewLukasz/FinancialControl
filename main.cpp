#include <iostream>
#include "FinancialControl.h"
using namespace std;

int main() {
    FinancialControl financialControl("users.xml","incomes.xml","expenses.xml");
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
            choice = financialControl.chooseOptionFromUserMenu();
            switch(choice) {
            case '1':
                system("cls");
                cout<<">>>Adding an income<<<"<<endl;
                financialControl.addIncome();
                break;
            case '2':
                system("cls");
                cout<<">>>Adding an expense<<<"<<endl;
                financialControl.addExpense();
                break;
            case '3':
                system("cls");
                cout<<">>>Balance from current month<<<"<<endl;
                financialControl.showBalanceFromCurrentMonth();
                break;
            case '4':
                system("cls");
                cout<<">>>Balance from previous month<<<"<<endl;
                financialControl.showBalanceFromPreviousMonth();
                break;
            case '5':
                system("cls");
                cout<<">>>Balance from custom period of time<<<"<<endl;
                financialControl.showBalanceFromCustomPeriodOfTime();
                break;
            case '6':
                system("cls");
                cout<<">>>Change password<<<"<<endl;
                financialControl.changeUserPassword();
                break;
            case '9':
                idLoggedInUser=financialControl.logout();
                break;
            }
        }
    }
}
