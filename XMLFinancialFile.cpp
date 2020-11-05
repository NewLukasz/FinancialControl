#include "XMLFinancialFile.h"

void XMLFinancialFile::addFinancialMovementToFile(FinancialMovement financialMovement,int idOfFinancialMovement,bool decisionVariableOneIfIncomeZeroIfExpense, string fileName) {
    CMarkup xml;
    bool fileExists= xml.Load(fileName);
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
    xml.Save(fileName);
}


vector <Income> XMLFinancialFile::loadIncomesFromXMLFile(int loggedInUserId, string fileName) {
    CMarkup xml;
    bool fileExists=xml.Load(fileName);

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
            if(income.getUserId()==loggedInUserId){
                incomes.push_back(income);
            }else{
                continue;
            }
        }
        return incomes;
    }
}

vector <Expense> XMLFinancialFile::loadExpensesFromXMLFile(int loggedInUserId, string fileName){
    CMarkup xml;
    bool fileExists=xml.Load(fileName);

    vector <Expense> expenses;
    Expense expense;

    if(!fileExists){
        return expenses;
    }else{
        xml.FindElem();
        xml.IntoElem();
        while(xml.FindElem("Expense")){
            xml.IntoElem();
            xml.FindElem("ExpenseId");
            expense.setExpenseId(atoi(xml.GetData().c_str()));
            xml.FindElem("UserId");
            expense.setUserId(atoi(xml.GetData().c_str()));
            xml.FindElem("Date");
            expense.setDate(atoi(xml.GetData().c_str()));
            xml.FindElem("Item");
            expense.setItem(xml.GetData().c_str());
            xml.FindElem("Amount");
            expense.setAmount(atof(xml.GetData().c_str()));
            xml.OutOfElem();
            expenses.push_back(expense);
        }
        return expenses;
    }
}
