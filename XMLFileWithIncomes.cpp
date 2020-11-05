#include "XMLFileWithIncomes.h"

void XMLFileWithIncomes::addIncomeToXMLFile(Income income){
    addFinancialMovementToFile(income,income.getIncomeId(),1,fileNameForFileWithIncomes);
}
