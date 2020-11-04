#ifndef FINANCIALMANAGER_H
#define FINANCIALMANAGER

#include <iostream>
#include <vector>
#include "Income.h"
#include "Expense.h"
using namespace std;

class FinancialManager {
    const int LOGGED_IN_USER;
    vector <Income> incomes;
    vector <Expense> expenses;
public:
    FinancialManager(string nameForFileWithIncomes, string nameForFileWithExpenses, int loggedInUser) : LOGGED_IN_USER(loggedInUser) {
        cout<<loggedInUser<<endl;
        system("pause");
    };
    void addIncome();
    void addExpense();
};

#endif // FINANCIALMANAGER_H
