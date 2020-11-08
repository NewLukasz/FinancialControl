#ifndef FINANCIALMANAGER_H
#define FINANCIALMANAGER

#include <iostream>
#include <vector>
#include <algorithm>
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
    XMLFileWithIncomes xmlFileWithIncomes;
    XMLFileWithExpenses xmlfileWithExpenses;
    void showSummary(int incomesSummary, int expensesSummary);
    time_t getLimitDate();
    void sortFinancialMovementsFromTheOldest();
    static bool compareDates(FinancialMovement financialMovement1, FinancialMovement financialMovement2);
public:
    FinancialManager(int loggedInUser, string fileNameForFileWithIncomes, string fileNameForFileWithExpenses)
    : xmlFileWithIncomes(fileNameForFileWithIncomes), xmlfileWithExpenses(fileNameForFileWithExpenses), LOGGED_IN_USER(loggedInUser) {
    incomes=xmlFileWithIncomes.loadIncomesFromXMLFile(LOGGED_IN_USER, fileNameForFileWithIncomes);
    expenses=xmlfileWithExpenses.loadExpensesFromXMLFile(LOGGED_IN_USER, fileNameForFileWithExpenses);
    };
    void addIncome();
    void addExpense();
    void showBalanceFromCurrentMonth();
    void showBalanceFromPreviousMonth();
    void showBalanceFromCustomPeriodOfTime();
    void showIncomeDetails(Income income);
    void showExpenseDetails(Expense expense);

};

#endif // FINANCIALMANAGER_H
