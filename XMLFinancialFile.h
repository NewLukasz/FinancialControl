#ifndef XMLFINANCIALFILE_H
#define XMLFINANCIALFILE_H

#include <iostream>
#include "Markup.h"
#include "FinancialMovement.h"

using namespace std;

class XMLFinancialFile{
protected:
    void addFinancialMovementToFile(FinancialMovement financialMovement, int idOfFinancialMovement, bool decisionVariableOneIfIncomeZeroIfExpense);
};

#endif // XMLFINANCIALFILE_H
