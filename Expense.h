#ifndef EXPENSE_H
#define EXPENSE_H

#include "FinancialMovement.h"
#include <iostream>

using namespace std;

class Expense : public FinancialMovement{
int expenseId;
public:
    int getExpenseId();
    void setExpenseId(int newExpenseId);
};

#endif // EXPENSE_H
