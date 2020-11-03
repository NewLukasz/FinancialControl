#ifndef INCOME_H
#define INCOME_H

#include "FinancialMovement.h"
#include <iostream>

using namespace std;

class Income : public FinancialMovement{
int incomeId;
public:
    int getIncomeId();
    void setIncomeId(int newIncomeId);
};

#endif // INCOME_H

