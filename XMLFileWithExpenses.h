#ifndef XMLFILEWITHEXPENSES_H
#define XMLFILEWITHEXPENSES_H

#include <iostream>
#include "Expense.h"
#include "XMLFinancialFile.h"

class XMLFileWithExpenses : public XMLFinancialFile{
public:
    void addExpensesToXMLFile(Expense expense);
};

#endif // XMLFILEWITHEXPENSES_H
