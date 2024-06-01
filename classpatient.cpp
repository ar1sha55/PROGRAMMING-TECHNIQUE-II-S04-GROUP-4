#include <iostream>
#include <string>
#include "class_med.h"
using namespace std; 

//parent class
class Patient {
    protected:
    string patientID,  fullname, password, dob, sex;
    Medication *med; //aggregation with Medication class

    public:
    Patient(string id=" ", string _name=" ", string pw=" ", string _dob=" ", string _sex=" "): 
    patientID(id), fullname(_name), password(pw), dob(_dob), sex(_sex) {} //argument constructor

    //mutators
    void setID(const string &id) {patientID = id;}
    void setname(const string &n) {fullname = n;}
    void setpassword(const string &pw) {password = pw;}
    void setdob(const string &d) {dob = d;}
    void setsex(const string &s) {sex = s;}

    //accessors
    string getID() const{return patientID;}
    string getname() const{return fullname;}
    string getpassword() const{return password;}
    string getdob() const{return dob;}
    string getsex() const{if(sex=="F")
        return "Female";
        else
        return "Male";} //M=Male, F=Female

    //method to calculate age
    int getAge() {
        int year, age;
        year = stoi(dob.substr(6, 4));
        age = 2024 - year;
        return age;
    }

    ~Patient() {} //destructor
};


int main() {
    Patient patient1; //create object
    patient1.setID("001");
    patient1.setname("Ali bin Abu");
    patient1.setpassword("Abc123");
    patient1.setdob("18/12/2004");
    patient1.setsex("M");

    cout << "Details of Patient 1" << endl
         << "ID: " << patient1.getID() << endl
         << "Name: " << patient1.getname() << endl
         << "DOB: " << patient1.getdob() << endl
         << "Age: " << patient1.getAge() << endl
         << "Sex: " << patient1.getsex() << endl;

    system("pause");
    return 0;

}
