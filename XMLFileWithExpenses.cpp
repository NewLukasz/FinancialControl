#include "XMLFileWithExpenses.h"

void XMLFileWithExpenses::addExpensesToXMLFile(Expense expense){
    addFinancialMovementToFile(expense,expense.getExpenseId(),0, fileNameForFileWithExpenses);
}

int XMLFileWithExpenses::getLastExpenseIdFromXMLFile(){
    return getLastFinancialMovementIdFromXMLFile(fileNameForFileWithExpenses,0);
}
