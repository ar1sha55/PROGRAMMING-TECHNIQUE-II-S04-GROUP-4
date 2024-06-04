//Medication implementation file
#include "Medication.h"
#include "MedType.h"
//#include "Frequency.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//class medication
Medication::Medication(){}
Medication::Medication(string n, string d, string s, string c, string f): medName(n), dosage(d), medType(s,c,f){}
string Medication::getMedName(){
    return medName;
}
void Medication::input(){
    cout << "Enter medication name: ";
    getline(cin, medName); 
    cout << "Enter dosage(500mg, 5ml): ";
    //cin.ignore();
    getline(cin, dosage);
    medType.read();
    //frequency.setFreq();
}
void Medication::output(int num){
    if(num==0){
        cout << "No medication available.\n" << endl;
    }else{
        cout << left;
        cout << setw(20) << "Medication"<< setw(10) << "Dosage" << setw(10) << "Form" << setw(10) << "Shape" << setw(10) << "Color" << endl;
    }
}
void Medication::outputMed(){
    cout << setw(20) << medName << setw(10) << dosage << setw(10) << medType.getForm() << setw(10)<< medType.getShape() << setw(10) << medType.getColor() << endl;
    //cout << frequency.printFreq();
}
Medication::~Medication(){}