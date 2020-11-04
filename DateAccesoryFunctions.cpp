#include "DateAccesoryFunctions.h"

string DateAccesoryFunctions::convertTimeTToDateInStringWithCorrectFormat(time_t timeInTimeTFormat){
    tm timeStucture=*localtime(&timeInTimeTFormat);
    string dateFormat="yyyy-mm-dd";
    char bufor[sizeof(dateFormat)];
    strftime(bufor,sizeof(bufor),"%Y-%m-%d",&timeStucture);
    return bufor;
}

time_t DateAccesoryFunctions::getTodayDate(){
    time_t today;
    time(&today);

    tm dataStructure=*localtime(&today);
    dataStructure.tm_sec=0;
    dataStructure.tm_min=0;
    dataStructure.tm_hour=0;

    today=mktime(&dataStructure);

    return today;
}

time_t DateAccesoryFunctions::convertStringDataToTimeT(string stringDate){
    const int YEAR_WHEN_COUTING_STARTED=1900;
    const int FACTOR_WHICH_ENABLE_START_COUNTING_MONTHS_FROM_0=1;

    char stringDateTable[stringDate.length()];
    strcpy(stringDateTable, stringDate.c_str());

    time_t convertedDate;
    int year=0,month=0,day=0;

    if(sscanf(stringDateTable,"%4d-%2d-%2d",&year,&month,&day)==3){
        struct tm timeDetails={0};
        timeDetails.tm_year=year-YEAR_WHEN_COUTING_STARTED;
        timeDetails.tm_mon=month-FACTOR_WHICH_ENABLE_START_COUNTING_MONTHS_FROM_0;
        timeDetails.tm_mday=day;
        convertedDate = mktime(&timeDetails);
        return convertedDate;
    }else{
        return 0;
    }
}
