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
    string chooseFileNameBasedOnDecisionVariable(bool decisionVariableOneIfIncomeZeroIfExpense);
protected:
    void addFinancialMovementToFile(FinancialMovement financialMovement, int idOfFinancialMovement, bool decisionVariableOneIfIncomeZeroIfExpense);
public:
    vector <Income> loadIncomesFromXMLFile();
    vector <Expense> loadExpensesFromXMLFile();
};

#endif // XMLFINANCIALFILE_H
