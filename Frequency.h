#include <iostream>
using namespace std;
#ifndef FREQUENCY_H
#define FREQUENCY_H



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


#endif