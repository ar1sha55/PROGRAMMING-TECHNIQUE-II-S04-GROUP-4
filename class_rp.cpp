#include <iostream>
#include "class_med.h"
#include "class_patient.h"
using namespace std;

//first child class
class RegularPatient : public Patient{
    private:
    string contactInfo, emergencyContact;

    public:
    RegularPatient(string contact=" ", string emergency=" "): 
    contactInfo(contact), emergencyContact(emergency) {}
 
    //mutators
    void setcontactInfo(const string &cont) {contactInfo = cont;}
    void setemergencyContact(const string &emercon) {emergencyContact = emercon;}

    //accessors
    string getcontactInfo() const{return contactInfo;}
    string getemergencyContact() const{return emergencyContact;}

    ~RegularPatient() {} //destructor
};

int main() {
    RegularPatient patient1; //create object
    patient1.setID("001");
    patient1.setname("Ali bin Abu");
    patient1.setpassword("Abc123");
    patient1.setdob("18/12/2004");
    patient1.setsex("M");
    patient1.setcontactInfo("123456789");
    patient1.setemergencyContact("12121212");

    cout << "Details of Patient 1" << endl
         << "ID: " << patient1.getID() << endl
         << "Name: " << patient1.getname() << endl
         << "DOB: " << patient1.getdob() << endl
         << "Age: " << patient1.getAge() << endl
         << "Sex: " << patient1.getsex() << endl
         << "Contact Info (+60): " << patient1.getcontactInfo() << endl
         << "Emergency Contact (+60): " << patient1.getemergencyContact() << endl;

    system("pause");
    return 0;
}
