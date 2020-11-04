#include "FinancialMovement.h"

int FinancialMovement::getUserId() {
    return userId;
}

time_t FinancialMovement::getDate() {
    return date;
}

string FinancialMovement::getItem() {
    return item;
}

double FinancialMovement::getAmount() {
    return amount;
}

void FinancialMovement::setUserId(int newUserId) {
    userId=newUserId;
}

void FinancialMovement::setDate(time_t newDate) {
    date=newDate;
}

void FinancialMovement::setItem(string newItem) {
    item=newItem;
}

void FinancialMovement::setAmount(double newAmount) {
    amount=newAmount;
}

void FinancialMovement::showAllDataOfFinancialMovement() {
    cout<<"UserId: "<<userId<<endl;
    cout<<"Date: "<<DateAccesoryFunctions::convertTimeTToDateInStringWithCorrectFormat(date)<<endl;
    cout<<"Item: "<<item<<endl;
    cout<<"Amount: "<<amount<<endl;
    system("pause");
}

void FinancialMovement::typeDateItemAmountForFinancialMovement() {
    cout<<"Is financial movement should be added with today date? (y/n)";
    char choice=AccesoryFunctions::getChar();
    while(choice!='n'&&choice!='y') {
        cout<<"Option: "<<choice<<" doesn't exist. Choose beetween y/n: ";
        choice=AccesoryFunctions::getChar();
    }
    if(choice=='n') {
        cout<<"Insert date of financial movement (format: yyyy-mm-dd with dashes): ";
        string stringDate=AccesoryFunctions::getLine();
        while(DateAccesoryFunctions::checkDate(stringDate)==false) {
            cout<<"Insert date again (format yyyy-mm-dd): ";
            stringDate=AccesoryFunctions::getLine();
        }
        date=DateAccesoryFunctions::convertStringDataToTimeT(stringDate);
    } else if(choice=='y') {
        cout<<"Here insert function with get today date"<<endl;
        date=1000;
        system("pause");
    }
    cout<<"Type source/destination of financial movement: ";
    item=AccesoryFunctions::getLine();
    cout<<"Type amount: ";
    cin>>amount;
}
