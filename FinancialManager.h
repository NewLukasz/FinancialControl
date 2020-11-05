#ifndef FINANCIALMANAGER_H
#define FINANCIALMANAGER

#include <iostream>
#include <vector>
#include "Income.h"
#include "Expense.h"
#include "DateAccesoryFunctions.h"
#include "XMLFileWithExpenses.h"
#include "XMLFileWithIncomes.h"
using namespace std;

class FinancialManager {
    const int LOGGED_IN_USER;
    vector <Income> incomes;
    vector <Expense> expenses;
    int nextIncomeId();
    int nextExpenseId();
    XMLFileWithIncomes xmlFileWithIncomes;
    XMLFileWithExpenses xmlfileWithExpenses;
public:
    FinancialManager(int loggedInUser, string fileNameForFileWithIncomes, string fileNameForFileWithExpenses)
    : xmlFileWithIncomes(fileNameForFileWithIncomes), xmlfileWithExpenses(fileNameForFileWithExpenses), LOGGED_IN_USER(loggedInUser) {
    incomes=xmlFileWithIncomes.loadIncomesFromXMLFile(LOGGED_IN_USER, fileNameForFileWithIncomes);
    expenses=xmlfileWithExpenses.loadExpensesFromXMLFile(LOGGED_IN_USER, fileNameForFileWithExpenses);
    };
    void addIncome();
    void addExpense();
};

#endif // FINANCIALMANAGER_H
