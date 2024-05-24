#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
#define MAX 50
using namespace std;

class Calendar
{
    string startDate;
    string endDate;

    public:
        Calendar();
        Calendar(string startDate = "", string endDate = ""){
            this->startDate = startDate;
            this->endDate = endDate;
        }
        //Medicine medicine[50];
        ~Calendar();

        void setstartDate(const string& startDate){ this->startDate = startDate;}
        void setendDate(const string& endDate){ this->endDate = endDate;}

        string getstartDate () const { return startDate; }  // y must put const?
        string getendDate () const { return endDate; }

};


class Frequency
{
    protected:
        int freqVal;

    public:
        Frequency() : freqVal(0){}
        Frequency(int freqVal):freqVal(freqVal){}

        ~Frequency();

};


class dailyFreq : public Frequency
{
    int time;
    int dailyIntake;

    public:
        dailyFreq(): time(0), dailyIntake(0){}
        dailyFreq(int t, int d): time(t), dailyIntake(d){}

        ~dailyFreq();

        void setTime(int time){ this->time = time; }
        void setdailyIntake(int dailyIntake){ this->dailyIntake = dailyIntake; }
        int getTime() const{ return time; }
        int getdailyIntake() const { return dailyIntake; }


};


class weeklyFreq : public Frequency
{
    int dayPerWeek;

    public:
        weeklyFreq(): dayPerWeek(0){}
        weeklyFreq(int dpw): dayPerWeek(dpw){}

        ~weeklyFreq();

        void setdayPerWeek(int dayPerWeek){ this->dayPerWeek = dayPerWeek; }
        int getdayPerWeek() const{ return dayPerWeek; }

};

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
    string getsex() {
        if(sex=="F")
        sex = "Female";
        else
        sex = "Male";
        return sex;}

    void getData() { //for first time
        cout << "\t\t<< ENTER DETAILS >>" << endl
             << "\t\t<< TO REGISTER >>" << endl << endl;
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
        string pt, pw;
        cout << "\n\t\t<<PLEASE ENTER AGAIN>>" << endl;
        cout << "\t\t<<FOR CONFIRMATION>>" << endl << endl;
        cout << "\t\tPatient ID: ";
        getline(cin, pt);
        setID(pt);
        cout << "\t\tPassword: ";
        getline(cin, pw);
        setpassword(pw);
        system("cls");
        if(pt != patientID && pw != password)
        do{
            cout << "\t\t!Both ID and password entered is wrong." << endl
            << "\t\tEnter again!" << endl;
            cout << "\t\tUser ID: ";
            getline(cin, patientID);
            cout << "\t\tPassword: ";
            getline(cin, password);
        }while(pt == patientID && pw == password);
        else if(pw!=password) {
             do{
            cout << "\t\t!Password entered is wrong." << endl
            << "\t\tEnter again!" << endl;
            cout << "\t\tPassword: ";
            getline(cin, password);
            }while(pw==password);
        }
        else if(pt!=patientID) {
            do{
            cout << "\t\t!User ID entered is wrong." << endl
             << "\t\tEnter again!" << endl;
            cout << "\t\tUser ID: ";
            getline(cin, pt);
            }while(pt==patientID);
        }
    }

    int getAge() {
        int year, age;
        year = stoi(dob.substr(6, 4));
        age = 2024 - year;
        return age;
    }

    void printDetails() {
        cout << "\t\t---------------------------" 
            << "\n\t\tHERE ARE YOUR DETAILS" << endl
            << "\t\t---------------------------" << endl
            << "\t\tUser ID: " << patientID << endl
            << "\t\tFull Name: " << getname() << endl
            << "\t\tDate of Birth: " << getdob() << endl
            << "\t\tGender: " << getsex() << endl
            << "\t\tThank you for registering." << endl;
            system("cls");
    }

};

//inherited 1.1
class RegularPatient : public Patient {
    private:
    string contactInfo, emergencyContact;

    public:
    RegularPatient(string contact=" ", string emergency=" "): contactInfo(contact), emergencyContact(emergency) {}

    void getData() {
        cout << "\t\tLOGIN SUCCESS." << endl
             << "\t\tYou are a REGULAR patient" << endl << endl;
        cout << "\t\t<< PLEASE ENTER YOUR CONTACT INFO >>" << endl;
        cout << "\t\tEnter Contact Info (Phone Num): ";
        getline(cin, contactInfo);
        cout << "\t\tEnter Emergency Contact (Phone Num): ";
        getline(cin, emergencyContact);
        system("cls");
    }
};

//inherited 1.2
class specialPatient : public Patient {
    private:
    string guardianName, relationship, guardianContact;

    public:
    specialPatient(string g = " ", string r = " ", string gc =" "): guardianName(g), relationship(r), guardianContact(gc) {}

    void getData() {
        cout << "\t\tLOGIN SUCCESS." << endl
             << "\t\t<< PLEASE ENTER GUARDIAN INFO >>" << endl << endl;
        cout << "\t\tName: ";
        getline(cin, guardianName);
        cout << "\t\tRelationship with Patient: ";
        getline(cin, relationship);
        cout << "\t\tGuardian Contact Info: ";
        getline(cin, guardianContact);
        system("cls");
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
    cout << "\t\tLOGIN TIME: " << put_time(localtime(&now), "%Y-%m-%d %H:%M:%S") << endl << endl;

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
    cout << "\t\tOPTION => ";
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
