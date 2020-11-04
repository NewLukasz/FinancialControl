#include "FinancialManager.h"

void FinancialManager::addIncome(){
    Income income;
    income.typeDateItemAmountForFinancialMovement();
    income.setIncomeId(1);
    income.setUserId(LOGGED_IN_USER);
    //income.setDate(500);
    //income.setItem("Karma dla pieska");
    //income.setAmount(500);
    income.showAllDataOfFinancialMovement();
}
