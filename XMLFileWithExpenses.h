#ifndef XMLFILEWITHEXPENSES_H
#define XMLFILEWITHEXPENSES_H

#include <iostream>
#include "Expense.h"
#include "XMLFinancialFile.h"

class XMLFileWithExpenses : public XMLFinancialFile{
    string fileNameForFileWithExpenses;
public:
    XMLFileWithExpenses(string sendedFileNameForFileWithExpenses){
        fileNameForFileWithExpenses=sendedFileNameForFileWithExpenses;
    };
    void addExpensesToXMLFile(Expense expense);
    int getLastExpenseIdFromXMLFile();
};

#endif // XMLFILEWITHEXPENSES_H
