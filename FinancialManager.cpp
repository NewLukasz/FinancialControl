#include "FinancialManager.h"

void FinancialManager::addIncome(){
    Income income;
    cout<<DateAccesoryFunctions::convertTimeTToDateInStringWithCorrectFormat(100000)<<endl;
    income.typeDateItemAmountForFinancialMovement();
    income.setIncomeId(1);
    income.setUserId(LOGGED_IN_USER);
    income.showAllDataOfFinancialMovement();
    incomes.push_back(income);
}
