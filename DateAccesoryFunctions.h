#ifndef DATEACCESORYFUNCTIONS_H
#define DATEACCESORYFUNCTIONS_H

#include "AccesoryFunctions.h"
#include <iostream>
#include <time.h>
#include <bits/stdc++.h>
#include <string>
using namespace std;

class DateAccesoryFunctions {
    bool checkIfYearIsLeap(int year);
    int checkHowManyDaysHasIndicatedMonth(int month, int year);
    bool checkIfDayInIndicatedMonthExists(string stringDate);
    bool checkPositionOfDashesInInputDate(string stringDate);
    bool checkLengthOfInputDate(string stringDate);
    bool checkIfInsertedDayIsAfter20200101(string stringDate);
    bool checkIfTypedMonthMoreThanTwelve(string stringDate);
public:
    static bool checkDate(string dateForCheck);
    static string convertTimeTToDateInStringWithCorrectFormat(time_t timeInTimeTFormat);
    static time_t getTodayDate();
    static time_t convertStringDataToTimeT(string stringDate);
    static int getYearFromStringDate(string stringDate);
    static int getMonthFromStringDate(string stringDate);
    static int getDayFromStringDate(string stringDate);
};

#endif // DATEACCESORYFUNCTIONS_H
