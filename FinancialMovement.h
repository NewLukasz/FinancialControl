#ifndef FINANCIALMOVEMENT_H
#define FINANCIALMOVEMENT_H

#include <iostream>
#include <cstdlib>
#include <time.h>
#include "AccesoryFunctions.h"
using namespace std;

class FinancialMovement{
    int userId;
    time_t date;
    string item;
    double amount;
public:
    int getUserId();
    time_t getDate();
    string getItem();
    double getAmount();
    void setUserId(int newUserId);
    void setDate(time_t newDate);
    void setItem(string newItem);
    void setAmount(double newAmount);
    void showAllDataOfFinancialMovement();
    void typeDateItemAmountForFinancialMovement();
};

#endif // FINANCIALMOVEMENT_H
