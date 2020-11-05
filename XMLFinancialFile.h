#ifndef XMLFINANCIALFILE_H
#define XMLFINANCIALFILE_H

#include <iostream>
#include <vector>
#include "Markup.h"
#include "FinancialMovement.h"
#include "Income.h"
#include "Expense.h"

using namespace std;

class XMLFinancialFile{
protected:
    void addFinancialMovementToFile(FinancialMovement financialMovement, int idOfFinancialMovement, bool decisionVariableOneIfIncomeZeroIfExpense, string fileName);
public:
    vector <Income> loadIncomesFromXMLFile(int loggedInUserId, string fileName);
    vector <Expense> loadExpensesFromXMLFile(int loggedInUserId, string fileName);
};

#endif // XMLFINANCIALFILE_H
