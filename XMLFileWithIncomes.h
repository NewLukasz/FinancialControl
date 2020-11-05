#ifndef XMLFILEWITHINCOMES_H
#define XMLFILEWITHINCOMES

#include <iostream>
#include "Income.h"
#include "XMLFinancialFile.h"

class XMLFileWithIncomes : public XMLFinancialFile {
public:
    void addIncomeToXMLFile(Income income);
};

#endif // XMLFILEWITHINCOMES_H
