#include "FinancialManager.h"

void FinancialManager::addIncome(){
    Income income;
    income.typeDateItemAmountForFinancialMovement();
    income.setIncomeId(1);
    income.setUserId(LOGGED_IN_USER);
    income.showAllDataOfFinancialMovement();

    XMLFileWithIncomes xmlWithIncomes;
    xmlWithIncomes.addIncomeToXMLFile(income);

    incomes.push_back(income);
}
