#include "DateAccesoryFunctions.h"

string DateAccesoryFunctions::convertTimeTToDateInStringWithCorrectFormat(time_t timeInTimeTFormat){
    tm timeStucture=*localtime(&timeInTimeTFormat);
    string dateFormat="yyyy-mm-dd";
    char bufor[sizeof(dateFormat)];
    strftime(bufor,sizeof(bufor),"%Y-%m-%d",&timeStucture);
    return bufor;
}
