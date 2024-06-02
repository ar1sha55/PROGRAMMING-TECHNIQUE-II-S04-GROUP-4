#include <iostream>
#include <string>
#include <iomanip>

#include "Medication.h"
#include "MedType.h"
#include "Frequency.h"
#include "DailyFreq.h"
#include "WeeklyFreq.h"
#include "Patient.h"
#include "RegularPatient.h"
#include "SpecialPatient.h"

#ifndef REPORT_H
#define REPORT_H
using namespace std;



class Report
{
    
    string startDate;
    string endDate;
    Medication *medication;
    Patient *patient;
    RegularPatient *regularp;
    SpecialPatient *specialp;
    

    public:
    Report() : startDate(""), endDate(""), medication(nullptr), patient(nullptr){}
    Report(string s, string e, Medication *m, Patient *p) 
    : startDate(s), endDate(e), medication(m), patient(p) {}

    // MUTATORS
    int setSdate()
    {
        int m,d;
        string sD;
        cout << "When would you like to start your medication? \n";
        
        do{
        cout << "(dd-mm-year) : ";
        getline (cin, sD);
        startDate = sD;
        string a = startDate.substr(3,2);
        m = stoi(a);

        string b = startDate.substr(0,2);
        d = stoi(b);
        
        if(m > 13 || d > 31 ) // notification pop up if month entered is invalid
        cout << "Oops! It seems like there's a typo on your date.\n Enter again.";
        } while(m > 13 || d > 31);
        return m;

    }

    void setEdate()
    {
        int n, e;
        string eD;
        cout << "When does this medication end? \n";
        

        do{
        cout << "(dd-mm-yyyy) : ";
        getline (cin, eD);
        endDate = eD;
        string c = endDate.substr(3,2);
        n = stoi(c);

        string f = endDate.substr(0,2);
        e = stoi(f);
        
        if(n > 13 || e > 31 ) // notification pop up if month entered is invalid
        cout << "Oops! It seems like there's a typo on your date.\n Enter again.";
        } while(n > 13 || e > 31);
        endDate = eD;
    }

    // ACQUIRE MONTH FROM USER
    string getMonth()
    {
        int m = setSdate();

        
        
        switch(m)
        {
            case 1 : return "January";
            case 2 : return  "February";
            case 3 : return "March";
            case 4 : return  "April";
            case 5 : return "May";
            case 6 : return "June";
            case 7 : return "July";
            case 8 : return  "August";
            case 9 : return "September";
            case 10 : return  "October";
            case 11 : return "November";
            case 12 : return  "December";
            default : return  "ERROR";
        }

        //string b = toupper(bulan);   
        //return bulan;

    }


    // ACCESSORS
    string getSdate(){return startDate;}
    string getEdate(){return endDate;}


    ~Report()
    {
        cout << "YOUR REPORT HAS BEEN DELETED\n\n\n";
    }

    void displayReport(Patient *p, Medication *m)
    {
        string bulan = getMonth();
        int i;
        cout << setw(55) << bulan <<" MEDICATION REPORT SCHEDULE\n\n";

        cout << "NAME : " << p->getname() << endl;
        cout << "DATE OF BIRTH : " << p->getdob() << endl;
        cout << "SEX : " << p->getsex() << endl;

       
        cout << "MEDICATION " << 1 << ": \n\n";
        cout << "Date Start - Date End : " << startDate << " - " <<  endDate << "\n";
        cout << "Name" << setw(10) << ":  " << m->getMedName() << "\n";
        cout << "Dosage" << setw(8) << ":  " << m->getDosage() << "\n";
        cout << "Form" << setw(10) << ":  " << m->getMedForm() << "\n";
        cout << "Shape" << setw(9) << ":  " << m->getMedShape()<< "\n";
        cout << "Color" << setw(9) << ":  " << m->getMedColor() << "\n";
    }
    
};

#endif
