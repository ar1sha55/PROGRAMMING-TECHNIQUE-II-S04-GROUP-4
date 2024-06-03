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
    cout << "\n\nTEST CLASS FREQUENCY\n";
    Frequency a;
    a.setFreq();
    a.printFreq();
    cout << "TEST CLASS FREQUENCY DONE \n\n";


    // TEST CLASS DAILY FREQUENCY
    cout << "TEST CLASS DAILY FREQUENCY\n";
    dailyFreq b;
    b.setdailyIntake();
    b.setFreq();
    b.setTime();
    b.printFreq();
    cout << "TEST CLASS DAILY FREQUENCY DONE \n\n";


    //TEST CLASS WEEKLY FREQUENCY
    cout << "TEST CLASS WEEKLY FREQUENCY\n";
    weeklyFreq c;
    c.setdayPerWeek();
    c.setFreq();
    c.printFreq();
    cout << "TEST CLASS WEEKLY FREQUENCY DONE";

    system("pause");
    return 0;
}