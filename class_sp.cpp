#include <iostream>
using namespace std;

class SpecialPatient{
    private:
    string patientID, fullname, password, dob, sex, guardianName, relationship, guardianContact;

    public:
    SpecialPatient(string id=" ", string _name=" ", string pw=" ", string _dob=" ", string _sex=" ", string g = " ", string r = " ", string gc =" "): 
    patientID(id), fullname(_name), password(pw), dob(_dob), sex(_sex), guardianName(g), relationship(r), guardianContact(gc) {}
 
    //mutators
    void setID(const string &id) {patientID = id;}
    void setname(const string &n) {fullname = n;}
    void setpassword(const string &pw) {password = pw;}
    void setdob(const string &d) {dob = d;}
    void setsex(const string &s) {sex = s;}
    void setguardianName(const string &g) {guardianName = g;}
    void setrelationship(const string &r) {relationship = r;}
    void setguardianContact(const string &gc) {guardianContact = gc;}

    //accessors
    string getID() const{return patientID;}
    string getname() const{return fullname;}
    string getpassword() const{return password;}
    string getdob() const{return dob;}
    string getsex() const{if(sex=="F")
        return "Female";
        else
        return "Male";} //M=Male, F=Female
    string getguardianName() const{return guardianName;}
    string getrelatiosnhip() const{return relationship;}
    string getguardianContact() const{return guardianContact;}

    //method to calculate age
    int getAge() {
        int year, age;
        year = stoi(dob.substr(6, 4));
        age = 2024 - year;
        return age;
    }

    ~SpecialPatient() {} //destructor
};

int main() {
    SpecialPatient patient1; //create object
    patient1.setID("001");
    patient1.setname("Ali bin Abu");
    patient1.setpassword("Abc123");
    patient1.setdob("18/12/2020");
    patient1.setsex("M");
    patient1.setguardianName("Abu bin Bakar");
    patient1.setrelationship("Father");
    patient1.setguardianContact("24681357");

    cout << "Details of Patient 1" << endl
         << "ID: " << patient1.getID() << endl
         << "Name: " << patient1.getname() << endl
         << "DOB: " << patient1.getdob() << endl
         << "Age: " << patient1.getAge() << endl
         << "Sex: " << patient1.getsex() << endl
         << "Guardian Name: " << patient1.getguardianName() << endl
         << "Guardian Relationship with Patient: " << patient1.getrelatiosnhip() << endl
         << "Guardian Contact (+60): " << patient1.getguardianContact() << endl;

    system("pause");
    return 0;
}
