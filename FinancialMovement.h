#ifndef FINANCIALMOVEMENT_H
#define FINANCIALMOVEMENT_H

#include <iostream>
#include <time.h>
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
    void setUsetId(int newUserId);
    void setDate(time_t newDate);
    void setItem(string newItem);
    void setAmount(double newAmount);

};

#endif // FINANCIALMOVEMENT_H
