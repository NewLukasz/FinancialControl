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

void FinancialMovement::setUsetId(int newUserId){
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
