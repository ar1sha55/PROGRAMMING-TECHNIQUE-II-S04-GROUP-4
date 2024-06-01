#include <iostream>
using namespace std;

class RegularPatient{
    private:
    string patientID,  fullname, password, dob, sex, contactInfo, emergencyContact;

    public:
    RegularPatient(string id=" ", string _name=" ", string pw=" ", string _dob=" ", string _sex=" ", string contact=" ", string emergency=" "): 
    patientID(id), fullname(_name), password(pw), dob(_dob), sex(_sex), contactInfo(contact), emergencyContact(emergency) {}
 
    //mutators
    void setID(const string &id) {patientID = id;}
    void setname(const string &n) {fullname = n;}
    void setpassword(const string &pw) {password = pw;}
    void setdob(const string &d) {dob = d;}
    void setsex(const string &s) {sex = s;}
    void setcontactInfo(const string &cont) {contactInfo = cont;}
    void setemergencyContact(const string &emercon) {emergencyContact = emercon;}

    //accessors
    string getID() const{return patientID;}
    string getname() const{return fullname;}
    string getpassword() const{return password;}
    string getdob() const{return dob;}
    string getsex() const{if(sex=="F")
        return "Female";
        else
        return "Male";} //M=Male, F=Female
    string getcontactInfo() const{return contactInfo;}
    string getemergencyContact() const{return emergencyContact;}

    //method to calculate age
    int getAge() {
        int year, age;
        year = stoi(dob.substr(6, 4));
        age = 2024 - year;
        return age;
    }

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
