#include "XMLFileWithIncomes.h"

void XMLFileWithIncomes::addIncomeToXMLFile(Income income){
    addFinancialMovementToFile(income,income.getIncomeId(),1,fileNameForFileWithIncomes);
}

int XMLFileWithIncomes::getLastIncomeIdFromXMLFile(){
    return getLastFinancialMovementIdFromXMLFile(fileNameForFileWithIncomes,1);
}
