#ifndef DATEACCESORYFUNCTIONS_H
#define DATEACCESORYFUNCTIONS_H

#include <iostream>
#include <time.h>
#include <bits/stdc++.h>
using namespace std;

class DateAccesoryFunctions {
public:
    static string convertTimeTToDateInStringWithCorrectFormat(time_t timeInTimeTFormat);
    static time_t getTodayDate();
    static time_t convertStringDataToTimeT(string stringDate);
};

#endif // DATEACCESORYFUNCTIONS_H
