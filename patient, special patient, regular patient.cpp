#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
#define MAX 50
using namespace std;

//parent class 1 (for everything about meds)
/*class Medication {
    private:
    string name, form, dosage;

    public:
    Medication(string _name= " ", string _form= " ", string _dosage=" "): name(_name), form(_form), dosage(_dosage) {} //default constructor

    void setmedname(string medname) {
        name = medname;
    }

    string getmedname() {return name;}
    void setform(string medform) {form = medform;}
    string getform() {return medform;}
    void setdosage(string meddos) {dosage = meddos;}
    string getdosage() {return dosage;}
};

//child 1.2 (untuk generate report)
class Calendar {
    private:
    int frequency;
    string starttDate, endDate;

    public:
    Calendar(int freq=0, string _startDate=" ", string _endDate=" "): frequency(freq), startDate(_startDate), endDate(_endDate) {}
    void setfreq(int freq) {frequency = freq;}
    int getfreq() {return frequency;}
    void setstartDate(string start) {startDate = start;}
    string getstartDate() {return startDate;}
    void setendDate(string end) {endDate = end;}
    string getendDate() {return endDate;}

    ~Calendar() {} //destructor
};

class Reminder {
    string message;

    public:
    Reminder(string m=" "): message(m) {}
    void setReminder(string m) {
        message = m;
    }
    string getReminder() {
        return message;
    }

    ~Reminder() {} //destructor
};

class Time {
    private:

}*/

//parent 2
class Patient {
    protected:
    string patientID,  fullname, password, dob, sex;

    public:
    Patient(string id=" ", string _name=" ", string pw=" ", string _dob=" ", string _sex=" "): patientID(id), fullname(_name), password(pw), dob(_dob), sex(_sex) {} //default constructor

    //mutators and accessors for dob and sex
    void setID(string id) {
        id = patientID;
    }
    string getID() {
        return patientID;
    }
    void setpassword(string pw) {
        pw = password;
    }
    string getpassword() {
        return password;
    }

    string getname() {return fullname;}
    string getdob() {return dob;}
    string getsex() {return sex;}

    void getData() { //for first time
        cout << "\t\t<< ENTER DETAILS >>" << endl
             << "\t\t<< TO REGISTER >>" << endl;
        cout << "\t\tPatient ID: ";
        getline(cin, patientID);
        cout << "\t\tFull Name: ";
        getline(cin, fullname);
        cout << "\t\tPassword: ";
        getline(cin, password);
        cout << "\t\tDate of Birth (DD/MM/YYYY): ";
        getline(cin, dob);
        cout << "\t\tGender (M/F): ";
        getline(cin, sex);
    }

    void authenticate() {//untuk confirm
        system("cls");
        cout << "\n\t\t<<PLEASE ENTER AGAIN>>" << endl;
        cout << "\t\t<<FOR CONFIRMATION>>" << endl << endl;
        cout << "\t\tPatient ID: ";
        getline(cin, patientID);
        cout << "\t\tPassword: ";
        getline(cin, password);
        system("cls");
        if(patientID!=getID())
        cout << "\t\t!User ID entered is wrong." << endl
             << "\t\tEnter again!" << endl;
        else
        cout << "\t\t!Password entered is wrong." << endl
             << "\t\tEnter again!" << endl;
        while(patientID != getID() || password != getpassword()){
            cout << "\t\tUser ID: ";
            getline(cin, patientID);
            cout << "\t\tPassword: ";
            getline(cin, password);
        }
    }

    int getAge() {
        int year, age;
        year = stoi(dob.substr(6, 4));
        age = 2024 - year;
        return age;
    }

    void printDetails() {
        cout << "\t\t---------------------------" << endl
            << "\n\t\tHERE ARE YOUR DETAILS" << endl
            << "\t\t---------------------------" << endl
            << "\t\tUser ID: " << patientID << endl
            << "\t\tFull Name: " << getname() << endl
            << "\t\tDate of Birth: " << getdob() << endl
            << "\t\tGender: " << getsex() << endl
            << "\t\tLOGIN SUCCESS." << endl;
    }

};

//inherited 1.1
class RegularPatient : public Patient {
    private:
    string contactInfo, emergencyContact;

    public:
    RegularPatient(string contact=" ", string emergency=" "): contactInfo(contact), emergencyContact(emergency) {}

    void getData() {
        system("cls");
        cout << "\t\tHELLO " << getname() << "!" << endl
             << "\t\tYou are a REGULAR patient" << endl;
        cout << "\t\t<<PLEASE ENTER YOUR CONTACT INFO>>" << endl;
        cout << "\t\tEnter Contact Info (Phone Num): ";
        getline(cin, contactInfo);
        cout << "\t\tEnter Emergency Contact (Phone Num): ";
        getline(cin, emergencyContact);
    }
};

//inherited 1.2
class specialPatient : public Patient {
    private:
    string guardianName, relationship, guardianContact;

    public:
    specialPatient(string g = " ", string r = " ", string gc =" "): guardianName(g), relationship(r), guardianContact(gc) {}

    void getData() {
        system("cls");
        cout << "\t\tHELLO GUARDIAN OF " << getname() << "!" << endl;
        cout << "\t\t<<PLEASE ENTER YOUR CONTACT INFO>>" << endl;
        cout << "\t\tName: ";
        getline(cin, guardianName);
        cout << "\t\tRelationship with Patient: ";
        getline(cin, relationship);
        cout << "\t\tGuardian Contact Info: ";
        getline(cin, guardianContact);
    }

};

void displayLine() {
    cout << "\t\t";
    for(int i = 0; i < 30; i++) {
        cout << "-";
    }
    cout << endl;
}

int main() {
    Patient patient;
    RegularPatient rPatient;
    specialPatient sPatient;

    int optionUser;
    char press;
    //TIME-FOR MEDICATION INTAKE 
    time_t now = time(nullptr);

    displayLine();
    cout << "\t\t|      HI!! WELCOME TO        |" << endl;
    cout << "\t\t|   MEDICATION SCHEDULER :)   |" << endl;
    displayLine();
    // Print the current time
    cout << "\t\tCurrent time: " << put_time(localtime(&now), "%Y-%m-%d %H:%M:%S") << endl << endl;

    patient.getData();
    patient.authenticate();
    if(patient.getAge() < 13 || patient.getAge() > 70) 
    sPatient.getData();
    else
    rPatient.getData();

    patient.printDetails();

    option:
    cout << "\t\tWelcome to MEDICATION SCHEDULER!" << endl
         << "\t\tChoose your task for today." << endl;
    cout << "\t\t[OPTION 1] => Add medication" << endl
         << "\t\t[OPTION 2] => Remove medication" << endl
         << "\t\t[OPTION 3] => See schedule for medicine intake" << endl;
    cout << "OPTION => ";
    cin >> optionUser;

    /*switch(optionUser) {
        case 1: cout << "\t\tPlease add medication" << endl; goto option; break;
        case 2: cout << "\t\tPlease remove medication" << endl; goto option; break;
        case 3: cout << "\t\tView calendar" << endl; goto option; break;
        default: cout << "salah" << endl; goto option; break;
    }*/

    system("pause");
    return 0;
}
