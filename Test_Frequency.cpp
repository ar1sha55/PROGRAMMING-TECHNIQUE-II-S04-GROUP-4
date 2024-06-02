#include <iostream>
using namespace std;

#include <string>
#include <cmath>
#include <iomanip>

#include "Frequency.h"
#include "DailyFreq.h"
#include "WeeklyFreq.h"



int main(){

    // TEST CLASS FREQUENCY
    cout << "TESTING PARENT CLASS FREQUENCY\n"
    Frequency a;
    a.setFreq();
    a.printFreq();


    // TEST CLASS DAILY FREQUENCY
    cout << "TESTING CHILD CLASS 1 : DAILY FREQUENCY\n"
    dailyFreq b;
    b.setdailyIntake();
    b.setFreq();
    b.setTime();
    b.printFreq();


    //TEST CLASS WEEKLY FREQUENCY
    cout << "TESTING CHILD CLASS 2 : WEEKLY FREQUENCY\n"
    weeklyFreq c;
    c.setdayPerWeek();
    c.setFreq();
    c.printFreq();


    system("pause");
    return 0;
}