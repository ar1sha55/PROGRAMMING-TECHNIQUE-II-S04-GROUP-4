#include <iostream>
#include <string>
#include "class_med.h"
#include "class_patient.h"
using namespace std; 

int main() {
    Patient patient1; //create object
    Medication med1("Ibuprofen", "500ml"); //initialize constructor
    patient1.setID("001");
    patient1.setname("Ali bin Abu");
    patient1.setpassword("Abc123");
    patient1.setdob("18/12/2004");
    patient1.setsex("M");
    patient1.setMed(&med1);

    patient1.printDetails();

    if(patient1.getAge() > 70 || patient1.getAge() < 13) 
    cout << "You need a GUARDIAN." << endl;

    system("pause");
    return 0;

}
