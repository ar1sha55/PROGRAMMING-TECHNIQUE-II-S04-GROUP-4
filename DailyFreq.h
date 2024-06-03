#ifndef DAILYFREQ_H
#define DAILYFREQ_H

#include "Frequency.h"

#include <iostream>
#include <iomanip>
using namespace std;


// CHILD CLASS 1 INHERITANCE

class dailyFreq : public Frequency
{
    
    int dailyIntake;
    double time[10];

    public:
        dailyFreq(): Frequency(1), dailyIntake(1), time() {}
        dailyFreq(int f, int d, double t): Frequency(f), dailyIntake(d) 
        {
            if(d > 1)
            {
                for(int i = 0; i < d; i++)
                {
                    time[i] = t;   
                }
            }
        }


        //DAILY FREQUENCY DESTRUCTOR
        ~dailyFreq(){}


        //AQCUIRE DAILY INTAKE FROM USER
        void setdailyIntake()
        {
            cout << "How many times do you need to take the the medicine in a day?\n";
            cin >> dailyIntake;
        }

        //AQCUIRE TIME FROM USER
        void setTime()
        {
            for(int i = 0; i < dailyIntake; i++)
            {
            cout << "What's the time no." << i+1 << " you need to take the medication in a day? \n";
            cout << "24hrs system, (hh.mm) : ";
            cin >> time[i];
            }
        }

        //ACCESSORS
        int getdailyIntake() const { return dailyIntake; }
        double getTime(int i) const{ return time[i]; }
        

        //PRINT DAILY FREQUENCY (POLYMORPHISM)
        void printFreq() override
        {
            cout << fixed << setprecision(2);
            Frequency :: printFreq();
            cout << "You need to take " << dailyIntake << "per day.\n";
            cout << "Time: " ;
            for(int i = 0; i < dailyIntake; i++)
            {
            cout <<  time[i] << "\n" << setw(10);
            }
        }

};


#endif