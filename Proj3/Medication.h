//Medication class header file
#include "MedType.h"
//#include "Frequency.h"
#include <string>
#ifndef MED_H
#define MED_H
using namespace std;

class Medication {
    string medName, dosage;
    MedType medType;//composition
    //Frequency frequency; //composition

    public:
        //constructor
        Medication();
        Medication(string , string , string , string , string );

        //accessor
        string getMedName();
        
        //other function
        void input();
        void output(int);
        void outputMed();

        //destructor
        ~Medication();
};


#endif