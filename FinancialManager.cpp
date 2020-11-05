#include "FinancialManager.h"

void FinancialManager::addIncome(){
    Income income;
    income.typeDateItemAmountForFinancialMovement();

    income.setIncomeId(nextIncomeId());

    int a=nextIncomeId();

    income.setUserId(LOGGED_IN_USER);
    income.showAllDataOfFinancialMovement();

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
