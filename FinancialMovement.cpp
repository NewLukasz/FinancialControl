#include "FinancialMovement.h"

int FinancialMovement::getUserId(){
    return userId;
}

time_t FinancialMovement::getDate(){
    return date;
}

string FinancialMovement::getItem(){
    return item;
}

double FinancialMovement::getAmount(){
    return amount;
}

void FinancialMovement::setUserId(int newUserId){
    userId=newUserId;
}

void FinancialMovement::setDate(time_t newDate){
    date=newDate;
}

void FinancialMovement::setItem(string newItem){
    item=newItem;
}

void FinancialMovement::setAmount(double newAmount){
    amount=newAmount;
}

void FinancialMovement::showAllDataOfFinancialMovement(){
    cout<<"UserId: "<<userId<<endl;
    cout<<"Date: "<<date<<endl;
    cout<<"Item: "<<item<<endl;
    cout<<"Amount: "<<amount<<endl;
    system("pause");
}
