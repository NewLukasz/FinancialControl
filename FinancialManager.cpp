#include "FinancialManager.h"

void FinancialManager::addIncome() {
    Income income;
    income.typeDateItemAmountForFinancialMovement();
    income.setIncomeId(xmlFileWithIncomes.getLastIncomeIdFromXMLFile());
    income.setUserId(LOGGED_IN_USER);

    xmlFileWithIncomes.addIncomeToXMLFile(income);

    incomes.push_back(income);
}


void FinancialManager::addExpense() {
    Expense expense;
    expense.typeDateItemAmountForFinancialMovement();
    expense.setExpenseId(xmlfileWithExpenses.getLastExpenseIdFromXMLFile());
    expense.setUserId(LOGGED_IN_USER);

    xmlfileWithExpenses.addExpensesToXMLFile(expense);

    expenses.push_back(expense);

}

void FinancialManager::showSummary(int incomesSummary,int expensesSummary) {
    cout<<"_______________________________________"<<endl;
    cout<<endl<<">>>Summary<<<"<<endl;
    cout<<"Income: "<<incomesSummary<<endl;
    cout<<"Expense: "<<expensesSummary<<endl;
    cout<<"Difference(income-expense): "<<incomesSummary-expensesSummary<<endl<<endl;
}

void FinancialManager::showBalanceFromCurrentMonth() {
    sortFinancialMovementsFromTheOldest();
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
    for(int i=0; i<expenses.size(); i++) {
        if(DateAccesoryFunctions::checkIfIndicatedDateIsInCurrentMouth(expenses[i].getDate())) {
            cout<<"_____"<<endl;
            showExpenseDetails(expenses[i]);
            expensesSummary+=expenses[i].getAmount();
        }
    }
    showSummary(incomesSummary,expensesSummary);
    system("pause");
}

void FinancialManager::showBalanceFromPreviousMonth() {
    sortFinancialMovementsFromTheOldest();
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
    for(int i=0; i<expenses.size(); i++) {
        if(DateAccesoryFunctions::checkIfIndicatedDateIsInPreviousMonth(expenses[i].getDate())) {
            cout<<"_____"<<endl;
            showExpenseDetails(expenses[i]);
            expensesSummary+=expenses[i].getAmount();
        }
    }
    showSummary(incomesSummary,expensesSummary);
    system("pause");
}

time_t FinancialManager::getLimitDate() {

    string stringLimitDate=AccesoryFunctions::getLine();
    while(DateAccesoryFunctions::checkDate(stringLimitDate)==false) {
        cout<<"Insert limit date again (format yyyy-mm-dd): ";
        stringLimitDate=AccesoryFunctions::getLine();
    }

    return DateAccesoryFunctions::convertStringDataToTimeT(stringLimitDate);
}

void FinancialManager::showBalanceFromCustomPeriodOfTime() {
    sortFinancialMovementsFromTheOldest();
    time_t firstLimit, secondLimit;

    do {
        cout<<"Insert first limit date (format: yyyy-mm-dd with dashes): ";
        firstLimit=getLimitDate();
        cout<<"Insert second limit date (format: yyyy-mm-dd with dashes): ";
        secondLimit=getLimitDate();
        if(firstLimit>secondLimit){
            cout<<"First limit date is greater than second. It is not possible to show balance. Type dates again."<<endl;
        }
    }while(firstLimit>secondLimit);

    cout<<endl<<"Incomes below: "<<endl;
    int incomesSummary=0;
    for(int i=0; i<incomes.size(); i++) {
        if(DateAccesoryFunctions::checkIfIndicatedDataIsInCustomedPeriodOfTime(firstLimit,secondLimit,incomes[i].getDate())) {
            cout<<"_____"<<endl;
            showIncomeDetails(incomes[i]);
            incomesSummary+=incomes[i].getAmount();
        }
    }
    cout<<"_______________________________________"<<endl;
    cout<<endl<<"Expenses below: "<<endl;
    int expensesSummary=0;
    for(int i=0; i<expenses.size(); i++) {
        if(DateAccesoryFunctions::checkIfIndicatedDataIsInCustomedPeriodOfTime(firstLimit,secondLimit,expenses[i].getDate())) {
            cout<<"_____"<<endl;
            showExpenseDetails(expenses[i]);
            expensesSummary+=expenses[i].getAmount();
        }
    }
    showSummary(incomesSummary,expensesSummary);
    cout<<"Summary is beetwen: "<<DateAccesoryFunctions::convertTimeTToDateInStringWithCorrectFormat(firstLimit)<<" and "<<DateAccesoryFunctions::convertTimeTToDateInStringWithCorrectFormat(secondLimit)<<"."<<endl<<endl;
    system("pause");
}

void FinancialManager::showIncomeDetails(Income income) {
    cout<<"Date: "<<DateAccesoryFunctions::convertTimeTToDateInStringWithCorrectFormat(income.getDate())<<endl;
    cout<<"Source of income: "<<income.getItem()<<endl;
    cout<<"Amount: "<<income.getAmount()<<endl;
}

void FinancialManager::showExpenseDetails(Expense expense) {
    cout<<"Date: "<<DateAccesoryFunctions::convertTimeTToDateInStringWithCorrectFormat(expense.getDate())<<endl;
    cout<<"Reason of expense: "<<expense.getItem()<<endl;
    cout<<"Amount: "<<expense.getAmount()<<endl;
}

bool FinancialManager::compareDates(FinancialMovement financialMovement1,FinancialMovement financialMovement2){
    return (financialMovement1.getDate()<financialMovement2.getDate());
}

void FinancialManager::sortFinancialMovementsFromTheOldest(){
    sort(incomes.begin(),incomes.end(),compareDates);
}
