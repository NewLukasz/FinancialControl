#ifndef XMLFILEWITHINCOMES_H
#define XMLFILEWITHINCOMES

#include <iostream>
#include "Income.h"
#include "XMLFinancialFile.h"

class XMLFileWithIncomes : public XMLFinancialFile {
    string fileNameForFileWithIncomes;
public:
    XMLFileWithIncomes(string sendedFileNameForFileWithIncomes){
    fileNameForFileWithIncomes=sendedFileNameForFileWithIncomes;
    };
    void addIncomeToXMLFile(Income income);
    int getLastIncomeIdFromXMLFile();
};

#endif // XMLFILEWITHINCOMES_H
