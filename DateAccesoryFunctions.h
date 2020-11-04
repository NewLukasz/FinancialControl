#ifndef DATEACCESORYFUNCTIONS_H
#define DATEACCESORYFUNCTIONS_H

#include <iostream>
#include <time.h>

using namespace std;

class DateAccesoryFunctions {
public:
    static string convertTimeTToDateInStringWithCorrectFormat(time_t timeInTimeTFormat);
};

#endif // DATEACCESORYFUNCTIONS_H
