#include "FinancialManager.h"

void FinancialManager::addIncome() {
    Income income;
    income.typeDateItemAmountForFinancialMovement();
    income.setIncomeId(xmlFileWithIncomes.getLastIncomeIdFromXMLFile());
    income.setUserId(LOGGED_IN_USER);

    xmlFileWithIncomes.addIncomeToXMLFile(income);

    incomes.push_back(income);
}

int FinancialManager::nextIncomeId() {
    if(incomes.size()==0) {
        return 1;
    } else {
        return incomes.back().getIncomeId()+1;
    }
}

void FinancialManager::addExpense() {
    Expense expense;
    expense.typeDateItemAmountForFinancialMovement();
    expense.setExpenseId(xmlfileWithExpenses.getLastExpenseIdFromXMLFile());
    expense.setUserId(LOGGED_IN_USER);

    xmlfileWithExpenses.addExpensesToXMLFile(expense);

    expenses.push_back(expense);

}

int FinancialManager::nextExpenseId() {
    if(expenses.size()==0) {
        return 1;
    } else {
        return expenses.back().getExpenseId()+1;
    }
}

void FinancialManager::showSummary(int incomesSummary,int expensesSummary){
    cout<<"_______________________________________"<<endl;
    cout<<endl<<">>>Summary<<<"<<endl;
    cout<<"Income: "<<incomesSummary<<endl;
    cout<<"Expense: "<<expensesSummary<<endl;
    cout<<"Difference(income-expense): "<<incomesSummary-expensesSummary<<endl<<endl;
}

void FinancialManager::showBalanceFromCurrentMonth() {
    cout<<endl<<"Incomes below: "<<endl;
    int incomesSummary=0;
    for(int i=0; i<incomes.size(); i++) {
        if(DateAccesoryFunctions::checkIfIndicatedDateIsInCurrentMouth(incomes[i].getDate())) {
            cout<<"_____"<<endl;
            showIncomeDetails(incomes[i]);
            incomesSummary+=incomes[i].getAmount();
        }
    }
    cout<<"_______________________________________"<<endl;
    cout<<endl<<"Expenses below: "<<endl;
    int expensesSummary=0;
    for(int i=0;i<expenses.size();i++){
        if(DateAccesoryFunctions::checkIfIndicatedDateIsInCurrentMouth(expenses[i].getDate())){
            cout<<"_____"<<endl;
            showExpenseDetails(expenses[i]);
            expensesSummary+=expenses[i].getAmount();
        }
    }
    showSummary(incomesSummary,expensesSummary);
    system("pause");
}

void FinancialManager::showBalanceFromPreviousMonth(){
    cout<<endl<<"Incomes below: "<<endl;
    int incomesSummary=0;
    for(int i=0; i<incomes.size(); i++) {
        if(DateAccesoryFunctions::checkIfIndicatedDateIsInPreviousMonth(incomes[i].getDate())) {
            cout<<"_____"<<endl;
            showIncomeDetails(incomes[i]);
            incomesSummary+=incomes[i].getAmount();
        }
    }
    cout<<"_______________________________________"<<endl;
    cout<<endl<<"Expenses below: "<<endl;
    int expensesSummary=0;
    for(int i=0;i<expenses.size();i++){
        if(DateAccesoryFunctions::checkIfIndicatedDateIsInPreviousMonth(expenses[i].getDate())){
            cout<<"_____"<<endl;
            showExpenseDetails(expenses[i]);
            expensesSummary+=expenses[i].getAmount();
        }
    }
    showSummary(incomesSummary,expensesSummary);
    system("pause");
}

void FinancialManager::showIncomeDetails(Income income) {
    cout<<"Date: "<<DateAccesoryFunctions::convertTimeTToDateInStringWithCorrectFormat(income.getDate())<<endl;
    cout<<"Source of income: "<<income.getItem()<<endl;
    cout<<"Amount: "<<income.getAmount()<<endl;
}

void FinancialManager::showExpenseDetails(Expense expense){
    cout<<"Date: "<<DateAccesoryFunctions::convertTimeTToDateInStringWithCorrectFormat(expense.getDate())<<endl;
    cout<<"Reason of expense: "<<expense.getItem()<<endl;
    cout<<"Amount: "<<expense.getAmount()<<endl;
}
