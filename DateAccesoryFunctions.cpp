#include "DateAccesoryFunctions.h"

string DateAccesoryFunctions::convertTimeTToDateInStringWithCorrectFormat(time_t timeInTimeTFormat) {
    tm timeStucture=*localtime(&timeInTimeTFormat);
    string dateFormat="yyyy-mm-dd";
    char bufor[sizeof(dateFormat)];
    strftime(bufor,sizeof(bufor),"%Y-%m-%d",&timeStucture);
    return bufor;
}

time_t DateAccesoryFunctions::getTodayDate() {
    time_t today;
    time(&today);

    tm dataStructure=*localtime(&today);
    dataStructure.tm_sec=0;
    dataStructure.tm_min=0;
    dataStructure.tm_hour=0;

    today=mktime(&dataStructure);

    return today;
}

time_t DateAccesoryFunctions::convertStringDataToTimeT(string stringDate) {
    const int YEAR_WHEN_COUTING_STARTED=1900;
    const int FACTOR_WHICH_ENABLE_START_COUNTING_MONTHS_FROM_0=1;

    char stringDateTable[stringDate.length()];
    strcpy(stringDateTable, stringDate.c_str());

    time_t convertedDate;
    int year=0,month=0,day=0;

    if(sscanf(stringDateTable,"%4d-%2d-%2d",&year,&month,&day)==3) {
        struct tm timeDetails= {0};
        timeDetails.tm_year=year-YEAR_WHEN_COUTING_STARTED;
        timeDetails.tm_mon=month-FACTOR_WHICH_ENABLE_START_COUNTING_MONTHS_FROM_0;
        timeDetails.tm_mday=day;
        convertedDate = mktime(&timeDetails);
        return convertedDate;
    } else {
        return 0;
    }
}

int DateAccesoryFunctions::getYearFromStringDate(string stringDate) {
    string yearString=stringDate.substr(0,4);
    return atoi(yearString.c_str());
}

int DateAccesoryFunctions::getMonthFromStringDate(string stringDate) {
    string monthsString=stringDate.substr(5,2);
    return atoi(monthsString.c_str())-1;
}

int DateAccesoryFunctions::getDayFromStringDate(string stringDate) {
    string daysString=stringDate.substr(8,2);
    return atoi(daysString.c_str());
}

bool DateAccesoryFunctions::checkIfYearIsLeap(int year) {
    return (year % 400 == 0 ||(year % 4 == 0 && year % 100 != 0)) ? true: false;
}

int DateAccesoryFunctions::checkHowManyDaysHasIndicatedMonth(int month, int year) {
    if(month==0) {
        return 31;
    } else if(month==1) {
        if(checkIfYearIsLeap(year)) {
            return 29;
        } else {
            return 28;
        }

    } else if(month==3) {
        return 30;
    } else if(month==4) {
        return 31;
    } else if(month==5) {
        return 30;
    } else if(month==6) {
        return 31;
    } else if(month==7) {
        return 31;
    } else if(month==8) {
        return 30;
    } else if(month==9) {
        return 31;
    } else if(month==10) {
        return 30;
    } else if(month==11) {
        return 31;
    }
}

bool DateAccesoryFunctions::checkIfDayInIndicatedMonthExists(string stringDate) {
    int day=getDayFromStringDate(stringDate);
    int month=getMonthFromStringDate(stringDate);
    int year=getYearFromStringDate(stringDate);
    int maximumDayInTypedMonth=checkHowManyDaysHasIndicatedMonth(month,year);
    if(day<=maximumDayInTypedMonth) {
        return true;
    } else {
        cout<<"This month doesn't have "<<day<<" days. Maximum is "<<maximumDayInTypedMonth<<". "<<endl;
        return false;
    }
}

bool DateAccesoryFunctions::checkPositionOfDashesInInputDate(string stringDate) {
    const int INDEX_OF_FIRST_DASH=4;
    const int INDEX_OF_SECOND_DASH=7;
    if(stringDate[INDEX_OF_FIRST_DASH]!='-'||stringDate[INDEX_OF_SECOND_DASH]!='-') {
        cout<<"Incorrect data format. Missing dashes or wrong signs."<<endl;
        return false;
    } else {
        return true;
    }
}

bool DateAccesoryFunctions::checkLengthOfInputDate(string stringDate) {
    const int LENGTH_OF_CORRECT_STRING_DATA_INSERTED=10;
    if(stringDate.length()!=LENGTH_OF_CORRECT_STRING_DATA_INSERTED) {
        cout<<"Wrong length of date, which you typed."<<endl;
        return false;
    } else {
        return true;
    }
}

bool DateAccesoryFunctions::checkIfInsertedDayIsAfter20200101(string stringDate) {
    const int DATE_WHICH_FROM_YOU_CAN_ADD_FINANCIAL_MOVEMENT_IN_TIME_T=946681200;
    if(convertStringDataToTimeT(stringDate)<DATE_WHICH_FROM_YOU_CAN_ADD_FINANCIAL_MOVEMENT_IN_TIME_T) {
        cout<<"You can't add financial movements before 2000-01-01"<<endl;
        return false;
    } else {
        return true;
    }
}

bool DateAccesoryFunctions::checkIfTypedMonthMoreThanTwelve(string stringDate) {
    const int QUANTITY_OF_MONTHS_COUNTING_FROM_ZERO=11;
    int numberOfMonth=getMonthFromStringDate(stringDate);
    if (numberOfMonth>QUANTITY_OF_MONTHS_COUNTING_FROM_ZERO) {
        cout<<"Year has only 12 months."<<endl;
        return false;
    }
    return true;
}

bool DateAccesoryFunctions::checkIfDateExceedCurrentMonthDay(string stringDate) {
    int typedYear=getYearFromStringDate(stringDate);
    int typedMonth=getMonthFromStringDate(stringDate);
    if(typedYear>getCurrentYear()) {
        cout<<"You can add financial movents only up to last day of current month."<<endl;
        return false;
    }
    if(typedMonth>getCurrentMonth()) {
        cout<<"You can add financial movents only up to last day of current month."<<endl;
        return false;
    }

    return true;
}

bool DateAccesoryFunctions::checkDate(string dateForCheckInString) {
    DateAccesoryFunctions accesoryObject;

    if(!accesoryObject.checkLengthOfInputDate(dateForCheckInString)) {
        return false;
    }

    if(!accesoryObject.checkPositionOfDashesInInputDate(dateForCheckInString)) {
        return false;
    }

    if(!accesoryObject.checkIfDayInIndicatedMonthExists(dateForCheckInString)) {
        return false;
    }

    if(!accesoryObject.checkIfTypedMonthMoreThanTwelve(dateForCheckInString)) {
        return false;
    }

    if(!accesoryObject.checkIfInsertedDayIsAfter20200101(dateForCheckInString)) {
        return false;
    }

    if(!accesoryObject.checkIfDateExceedCurrentMonthDay(dateForCheckInString)) {
        return false;
    }
    return true;
}

int DateAccesoryFunctions::getCurrentMonth() {
    time_t today;
    time(&today);
    tm dataStructure=*localtime(&today);
    return dataStructure.tm_mon;
}

int DateAccesoryFunctions::getCurrentYear() {
    time_t today;
    time(&today);
    tm dataStructure=*localtime(&today);
    const int FACTOR_TO_RETURN_ACTUCAL_YEAR=1900;
    return dataStructure.tm_year+FACTOR_TO_RETURN_ACTUCAL_YEAR;
}

int DateAccesoryFunctions::getPreviousMonth() {
    time_t today;
    time(&today);
    tm dataStructure=*localtime(&today);
    return dataStructure.tm_mon-1;
}

int DateAccesoryFunctions::getMonthFromTimeT(time_t dateForGetMonth) {
    tm dataStructure=*localtime(&dateForGetMonth);
    return dataStructure.tm_mon;
}

bool DateAccesoryFunctions::checkIfIndicatedDateIsInCurrentMouth(time_t dateForCheck) {
    DateAccesoryFunctions dateAccesoryObject;
    return (dateAccesoryObject.getMonthFromTimeT(dateForCheck)==dateAccesoryObject.getCurrentMonth()) ? true : false;
}

bool DateAccesoryFunctions::checkIfIndicatedDateIsInPreviousMonth(time_t dateForCheck) {
    DateAccesoryFunctions dateAccesoryObject;
    return(dateAccesoryObject.getMonthFromTimeT(dateForCheck)==dateAccesoryObject.getPreviousMonth()) ? true : false;
}

bool DateAccesoryFunctions::checkIfIndicatedDataIsInCustomedPeriodOfTime(time_t firstLimit, time_t secondLimit, time_t dateForCheck) {
    return (dateForCheck>firstLimit&&dateForCheck<secondLimit) ? true : false;
}

