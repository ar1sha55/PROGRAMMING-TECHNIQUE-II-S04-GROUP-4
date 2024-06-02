#include <iostream>
#include "class_med.h"
#include "class_patient.h"
using namespace std;

//second child class
class SpecialPatient: public Patient {
    private:
    string guardianName, relationship, guardianContact;

    public:
    SpecialPatient(string g = " ", string r = " ", string gc =" "): 
    guardianName(g), relationship(r), guardianContact(gc) {}
 
    //mutators
    void setguardianName(const string &g) {guardianName = g;}
    void setrelationship(const string &r) {relationship = r;}
    void setguardianContact(const string &gc) {guardianContact = gc;}

    //accessors
    string getguardianName() const{return guardianName;}
    string getrelatiosnhip() const{return relationship;}
    string getguardianContact() const{return guardianContact;}

    void printDetails() override {
        Patient::printDetails();
        cout << "Guardian Name: " << getguardianName() << endl
             << "Guardian Relationship with Patient: " << getrelatiosnhip() << endl
             << "Guardian Contact (+60): " << getguardianContact() << endl;
    }

    ~SpecialPatient() {} //destructor
};

int main() {
    SpecialPatient patient1; //create object
    Medication med1("Ibuprofen", "500ml");
    patient1.setID("001");
    patient1.setname("Ali bin Abu");
    patient1.setpassword("Abc123");
    patient1.setdob("18/12/2020");
    patient1.setsex("M");
    patient1.setguardianName("Abu bin Bakar");
    patient1.setrelationship("Father");
    patient1.setguardianContact("24681357");
    patient1.setMed(&med1);

    patient1.printDetails();

    system("pause");
    return 0;
}

