#ifndef FINANCIALMANAGER_H
#define FINANCIALMANAGER

#include <iostream>
#include <vector>
#include "Income.h"
#include "Expense.h"
#include "DateAccesoryFunctions.h"
#include "XMLFileWithIncomes.h"
using namespace std;

class FinancialManager {
    const int LOGGED_IN_USER;
    vector <Income> incomes;
    vector <Expense> expenses;
    int nextIncomeId();
    int nextExpenseId();
public:
    FinancialManager(int loggedInUser) : LOGGED_IN_USER(loggedInUser) {
    XMLFileWithIncomes xmlFileWithIncomes;
    incomes=xmlFileWithIncomes.loadIncomesFromXMLFile();
    };
    void addIncome();
    void addExpense();
};

#endif // FINANCIALMANAGER_H
