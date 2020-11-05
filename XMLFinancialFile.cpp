#include "XMLFinancialFile.h"

string XMLFinancialFile::chooseFileNameBasedOnDecisionVariable(bool decisionVariableOneIfIncomeZeroIfExpense) {
    if(decisionVariableOneIfIncomeZeroIfExpense==1) {
        return "incomes.xml";
    } else {
        return "expenses.xml";
    }
}

void XMLFinancialFile::addFinancialMovementToFile(FinancialMovement financialMovement,int idOfFinancialMovement,bool decisionVariableOneIfIncomeZeroIfExpense) {
    CMarkup xml;
    bool fileExists= xml.Load(chooseFileNameBasedOnDecisionVariable(decisionVariableOneIfIncomeZeroIfExpense));
    if(!fileExists) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("FinancialMovements");
    }
    xml.FindElem();
    xml.IntoElem();
    if(decisionVariableOneIfIncomeZeroIfExpense==1) {
        xml.AddElem("Income");
    } else {
        xml.AddElem("Expense");
    }
    xml.IntoElem();
    if(decisionVariableOneIfIncomeZeroIfExpense==1) {
        xml.AddElem("IncomeId",idOfFinancialMovement);
    } else {
        xml.AddElem("ExpenseId", idOfFinancialMovement);
    }
    xml.AddElem("UserId",financialMovement.getUserId());
    xml.AddElem("Date",financialMovement.getDate());
    xml.AddElem("Item",financialMovement.getItem());
    xml.AddElem("Amount",financialMovement.getAmount());
    xml.Save(chooseFileNameBasedOnDecisionVariable(decisionVariableOneIfIncomeZeroIfExpense));
}


vector <Income> XMLFinancialFile::loadIncomesFromXMLFile() {

    CMarkup xml;
    bool fileExists=xml.Load("incomes.xml");

    vector <Income> incomes;
    Income income;

    if(!fileExists) {
        return incomes;
    } else {
        xml.FindElem();
        xml.IntoElem();
        while(xml.FindElem("Income")){
            xml.IntoElem();
            xml.FindElem("IncomeId");
            income.setIncomeId(atoi(xml.GetData().c_str()));
            xml.FindElem("UserId");
            income.setUserId(atoi(xml.GetData().c_str()));
            xml.FindElem("Date");
            income.setDate(atoi(xml.GetData().c_str()));
            xml.FindElem("Item");
            income.setItem(xml.GetData().c_str());
            xml.FindElem("Amount");
            income.setAmount(atof(xml.GetData().c_str()));
            xml.OutOfElem();
            incomes.push_back(income);
        }
        return incomes;
    }
}

//vector <Expense> XMLFinancialFile::loadExpensesFromXMLFile();
