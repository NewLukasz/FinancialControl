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
    bool checkIfDateExceedCurrentMonthDay(string stringDate);
    int getCurrentYear();
    int getCurrentMonth();
    int getPreviousMonth();
    int getMonthFromTimeT(time_t dateForGerMonth);
public:
    static bool checkIfIndicatedDateIsInCurrentMouth(time_t dateForCheck);
    static bool checkIfIndicatedDateIsInPreviousMonth(time_t dateForCheck);
    static bool checkIfIndicatedDataIsInCustomedPeriodOfTime(time_t firstLimit, time_t secondLimit, time_t dateForCheck);
    static bool checkDate(string dateForCheck);
    static string convertTimeTToDateInStringWithCorrectFormat(time_t timeInTimeTFormat);
    static time_t getTodayDate();
    static time_t convertStringDataToTimeT(string stringDate);
    static int getYearFromStringDate(string stringDate);
    static int getMonthFromStringDate(string stringDate);
    static int getDayFromStringDate(string stringDate);
};

#endif // DATEACCESORYFUNCTIONS_H
