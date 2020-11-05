#include "XMLFileWithExpenses.h"

void XMLFileWithExpenses::addExpensesToXMLFile(Expense expense){
    addFinancialMovementToFile(expense,expense.getExpenseId(),0);
}
