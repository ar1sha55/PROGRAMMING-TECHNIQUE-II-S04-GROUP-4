#ifndef WEEKLYFREQ_H
#define WEEKLYFREQ_H

#include "Frequency.h"
#include <iostream>
using namespace std;


// CHILD CLASS 2 INHERITANCE

class weeklyFreq : public Frequency  //inheritance
{
    int dayPerWeek;

    public:
        weeklyFreq(): Frequency(1), dayPerWeek(1){}
        weeklyFreq(int f, int dpw): Frequency(f), dayPerWeek(dpw){}

        //WEEKLY FRQUENCY DESTRUCTOR
        ~weeklyFreq(){}

        //AQCUIRE DAYPERWEEK FROM USER
        void setdayPerWeek()
        {
            cout << "How many times do you need to take the medication per week?\n";
            cin >> dayPerWeek;
        }

        //ACCESSOR
        int getdayPerWeek() const{ return dayPerWeek; }
        

        //PRINT WEEKLY FREQUENCY 
        void printFreq() override
        {
            cout << "This medicine needs to be taken " << dayPerWeek << " day(s) per week, and\n";
            Frequency :: printFreq();
        }
};

#endif