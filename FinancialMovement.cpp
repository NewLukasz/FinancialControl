#include "FinancialMovement.h"

int FinancialMovement::getUserId() {
    return userId;
}

time_t FinancialMovement::getDate() {
    return date;
}

string FinancialMovement::getItem() {
    return item;
}

double FinancialMovement::getAmount() {
    return amount;
}

void FinancialMovement::setUserId(int newUserId) {
    userId=newUserId;
}

void FinancialMovement::setDate(time_t newDate) {
    date=newDate;
}

void FinancialMovement::setItem(string newItem) {
    item=newItem;
}

void FinancialMovement::setAmount(double newAmount) {
    amount=newAmount;
}

void FinancialMovement::showAllDataOfFinancialMovement() {
    cout<<"UserId: "<<userId<<endl;
    cout<<"Date: "<<DateAccesoryFunctions::convertTimeTToDateInStringWithCorrectFormat(date)<<endl;
    cout<<"Item: "<<item<<endl;
    cout<<"Amount: "<<amount<<endl;
    system("pause");
}

void FinancialMovement::typeDateItemAmountForFinancialMovement() {
    cout<<"Is financial movement should be added with today date? (y/n) ";
    char choice=AccesoryFunctions::getChar();
    while(choice!='n'&&choice!='y') {
        cout<<"Option: "<<choice<<" doesn't exist. Choose beetween y/n: ";
        choice=AccesoryFunctions::getChar();
    }
    if(choice=='n') {
        cout<<"Insert date of financial movement (format: yyyy-mm-dd with dashes): ";
        string stringDate=AccesoryFunctions::getLine();
        while(DateAccesoryFunctions::checkDate(stringDate)==false) {
            cout<<"Insert date again (format yyyy-mm-dd): ";
            stringDate=AccesoryFunctions::getLine();
        }
        setDate(date=DateAccesoryFunctions::convertStringDataToTimeT(stringDate));
    } else if(choice=='y') {
        setDate(date=DateAccesoryFunctions::getTodayDate());
    }
    cout<<"Type source/destination of financial movement: ";
    setItem(item=AccesoryFunctions::getLine());
    cout<<"Type amount: ";
    setAmount(insertAmount());
    cout<<endl<<"Financial movement has been added"<<endl;
    system("pause");
}

bool FinancialMovement::checkIfAmountInStringContainLetter(string amountInString) {
    for(int i=0; i<amountInString.length(); i++) {
        if(isdigit(amountInString[i])==0) {
            if(amountInString[i]==','||amountInString[i]=='.') {
                continue;
            } else {
                return true;
            }
        }
    }
    return false;
}

bool FinancialMovement::checkIfAmountContainsMoreThanTwoDigitAfterComa(string amountInString) {
    int positionOfComaInString=0;
    for(int i=0; i<amountInString.length(); i++) {
        if(amountInString[i]=='.'||amountInString[i]==',') {
            positionOfComaInString=i;
            break;
        }
    }
    int const VALUE_OF_DISPLACEMENT_TO_DELETE_CORRECT_PART_OF_STRING_TO_MAKE_DETECTION=1;
    string signsAfterComa=amountInString.erase(0,positionOfComaInString+VALUE_OF_DISPLACEMENT_TO_DELETE_CORRECT_PART_OF_STRING_TO_MAKE_DETECTION);
    if(signsAfterComa.length()==2||signsAfterComa.length()==1||signsAfterComa.length()==0) {
        return false;
    } else {
        return true;
    }
}

string FinancialMovement::changeCommaToDotInAmountString(string amountInString){
    for(int i=0; i<amountInString.length(); i++) {
        if(amountInString[i]==',') {
            amountInString[i]='.';
        }
    }
    return amountInString;
}

double FinancialMovement::insertAmount() {
    string amountInString=AccesoryFunctions::getLine();
    string amountInStringWithDot=changeCommaToDotInAmountString(amountInString);
    while(checkIfAmountInStringContainLetter(amountInStringWithDot)||checkIfAmountContainsMoreThanTwoDigitAfterComa(amountInStringWithDot)){
        cout<<"You typed wrong sings. Try again: ";
        amountInString=AccesoryFunctions::getLine();
        amountInStringWithDot=changeCommaToDotInAmountString(amountInString);
    }
    return atof(amountInStringWithDot.c_str());
}
