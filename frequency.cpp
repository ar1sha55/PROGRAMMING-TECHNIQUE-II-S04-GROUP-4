





#include <iostream>
using namespace std;

#include <string>
#include <cmath>
#include <iomanip>




//PARENT CLASS INHERITANCE

class Frequency
{
    protected:
        int freqVal;

    public:
        Frequency() : freqVal(0){}
        Frequency(int freqVal):freqVal(freqVal){}

        void setFreq()
        {
            cout << "How many times do you need to take the the medicine in a day?\n";
            cin >> freqVal;
        }

        int getFreq() const { return freqVal; }


        virtual void printFreq()
        {
            cout << "Frequency : " << freqVal << " times per day\n";
        }

        ~Frequency(){}

};


// CHILD CLASS 1 INHERITANCE

class dailyFreq : public Frequency
{
    
    int dailyIntake;
    double time[10];

    public:
        dailyFreq(): Frequency(0), dailyIntake(0), time() {}
        dailyFreq(int f, int d, double t): Frequency(f), dailyIntake(d) 
        {
            if(f > 1)
            {
                for(int i = 0; i < f; i++)
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
            cout << "Number of doses you need to take at one time : ";
            cin >> dailyIntake;
        }

        //AQCUIRE TIME FROM USER
        void setTime()
        {
            for(int i = 0; i < dailyIntake; i ++)
            {
            cout << "What's the time no." << i+1 << " you need to take the medication in a day? \n";
            cout << "24hrs system, (hh.mm) : ";
            cin >> time[i];
            }
        }

        //ACCESSORS
        int getdailyIntake() const { return dailyIntake; }
        double getTime(int i) const{ return time[i]; }
        

        //PRINT DAILY FREQUENCY 
        void printFreq() override
        {
            Frequency :: printFreq();
            cout << "You need to take " << dailyIntake << " each time.\n";
            cout << "Time: " ;
            for(int i = 0; i < dailyIntake; i++)
            {
            cout <<  time[i] << "\n" << setw(10);
            }
        }

};



// CHILD CLASS 2 INHERITANCE

class weeklyFreq : public Frequency  //inheritance
{
    int dayPerWeek;

    public:
        weeklyFreq(): Frequency(0), dayPerWeek(0){}
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

int main(){

    // TEST CLASS FREQUENCY
    Frequency a;
    a.setFreq();
    a.printFreq();
    cout << "test class frequency done.\n\n"


    // TEST CLASS DAILY FREQUENCY
    dailyFreq b;
    b.setFreq();
    b.setdailyIntake();
    b.setTime();
    b.printFreq();
    cout << "\ntest daily frequency done\n\n";


    //TEST CLASS WEEKLY FREQUENCY
    weeklyFreq c;
    c.setdayPerWeek();
    c.setFreq();
    c.printFreq();


    system("pause");
    return 0;
}