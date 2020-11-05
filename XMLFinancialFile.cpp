#include "XMLFinancialFile.h"

void XMLFinancialFile::addFinancialMovementToFile(FinancialMovement financialMovement,int idOfFinancialMovement,bool decisionVariableOneIfIncomeZeroIfExpense) {
    CMarkup xml;
    bool fileExists= xml.Load("FinancialMovement.xml");
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
    xml.Save("FinancialMovement.xml");
}
