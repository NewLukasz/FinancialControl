#include "FinancialManager.h"

void FinancialManager::addIncome(){
    Income income;
    income.typeDateItemAmountForFinancialMovement();
    income.setIncomeId(xmlFileWithIncomes.getLastIncomeIdFromXMLFile());
    income.setUserId(LOGGED_IN_USER);

    xmlFileWithIncomes.addIncomeToXMLFile(income);

    incomes.push_back(income);
}

int FinancialManager::nextIncomeId(){
    if(incomes.size()==0){
        return 1;
    }else{
        return incomes.back().getIncomeId()+1;
    }
}

void FinancialManager::addExpense(){
    Expense expense;
    expense.typeDateItemAmountForFinancialMovement();
    expense.setExpenseId(xmlfileWithExpenses.getLastExpenseIdFromXMLFile());
    expense.setUserId(LOGGED_IN_USER);

    xmlfileWithExpenses.addExpensesToXMLFile(expense);

    expenses.push_back(expense);

}

int FinancialManager::nextExpenseId(){
    if(expenses.size()==0){
        return 1;
    }else{
        return expenses.back().getExpenseId()+1;
    }
}
