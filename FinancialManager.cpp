#include "FinancialManager.h"

void FinancialManager::addIncome(){
    Income income;
    income.typeDateItemAmountForFinancialMovement();
    income.setIncomeId(nextIncomeId());
    income.setUserId(LOGGED_IN_USER);

    XMLFileWithIncomes xmlWithIncomes;
    xmlWithIncomes.addIncomeToXMLFile(income);

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
    expense.setExpenseId(nextExpenseId());
    expense.setUserId(LOGGED_IN_USER);

    expense.showAllDataOfFinancialMovement();

    expenses.push_back(expense);

}

int FinancialManager::nextExpenseId(){
    if(expenses.size()==0){
        return 1;
    }else{
        return expenses.back().getExpenseId()+1;
    }
}
