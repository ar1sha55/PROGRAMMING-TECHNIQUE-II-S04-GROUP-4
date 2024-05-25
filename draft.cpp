#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
#define MAX 50
using namespace std;


class MedType {
    string form, shape, color;

    public:
        MedType(){}
        MedType(string f, string s, string c): form(f),shape(s), color(c){}

        string getForm(){
            return form;
        }
        string getShape(){
            return shape;
        }
        string getColor(){
            return color;
        }

        void read(){
            cout << "\t\tEnter form (tablet, capsule, powder, liquid): ";
            getline(cin, form);
            if (form=="tablet"  form=="capsule"){
                cout << "\t\tEnter shape (round, oval): ";
                getline(cin, shape);
            }else{
                shape = "None";
            }
            cout << "\t\tEnter color: ";
            getline(cin, color);
            cout << "\t\tClick anywhere if choose more than 1";
        }

        ~MedType(){};
};

class Medication {
    string medName, dosage;
    MedType medType;//composition

    public:
        Medication(){}
        Medication(string n, string d, string s, string c, string f): medName(n), dosage(d), medType(s,c,f){}

        string getMedName(){
            return medName;
        }
         
        void input(){
            cin.ignore();
            cout << "\t\t << ADD MEDICINE(s) >>" << endl;
            cout << "\t\tEnter medication name: ";
            getline(cin, medName);
            cout << "\t\tEnter dosage(500mg, 5ml): ";
            cin.ignore();
            getline(cin, dosage);
            medType.read();
        }

        void removeMed() {
            cout << "\t\t << REMOVE MEDICINE(s) >> " << endl;
            cout << "\t\tEnter medication name you want to remove: ";
            getline(cin, medName);
            
        }

        void output(int num){
            if(num==0){
                cout << "No medication available.\n" << endl;
            }else{
                cout << left;
                cout << setw(20) << "Medication"<< setw(10) << "Dosage" << setw(10) << "Form" << setw(10) << "Shape" << setw(10) << "Color" << endl;
            }
        }
        void outputMed(){
            cout << setw(20) << medName << setw(10) << dosage << setw(10) << medType.getForm() << setw(10)<< medType.getShape() << setw(10) << medType.getColor() << endl;
        }

        ~Medication(){};
};


class Calendar
{
    string chooseMonth;

    public:
        Calendar();
        Calendar(string chooseMonth = " "){
            this->chooseMonth = chooseMonth;
        }
        //Medicine medicine[50];
        ~Calendar();

        void setchooseMonth(const string& chooseMonth){ this->chooseMonth = chooseMonth;}
        string getchooseMonth () const { return chooseMonth; }  // y must put const?
        /*void showCalendar() {
            if(chooseMonth=="January") {
                cout << ""
            }
        }*/

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
            << "\t\tGender: " << getsex() << endl << endl;
            //<< "\t\tThank you for registering." << endl << endl;
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
        cout << "\t\tEnter Contact Info (+60): ";
        getline(cin, contactInfo);
        cout << "\t\tEnter Emergency Contact (+60): ";
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

void userOption() {
     cout << "\t\tWelcome to MEDICATION SCHEDULER!" << endl
         << "\t\tChoose your task for today." << endl;
    cout << "\t\t[OPTION 1] => Add medication" << endl
         << "\t\t[OPTION 2] => Remove medication" << endl
         << "\t\t[OPTION 3] => See schedule for medicine intake" << endl;
         << "\t\t[OPTION 4] => Exit system." << endl << endl;
    cout << "\t\tOPTION => ";
}

void returnorexit() {
    int choose;
    cout << "\t\tPress [1] to return to menu, [2] to exit system.";
    cin >> choose;
    if(choose == 1)
    userOption();
}

int main() {

    int num = 0;

    Patient patient;
    RegularPatient rPatient;
    specialPatient sPatient;

    char press;
    int optionUser, numMed;
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
    if(patient.getAge() < 13  patient.getAge() > 70) 
    sPatient.getData();
    else
    rPatient.getData();

    patient.printDetails();

    optionUser = userOption();

    cout << "Your medication: " << endl << endl;
    
    med->output(num);
    for(int i=0; i<num; i++){
        med[i].outputMed();
    }
    Medication *med = new Medication[numMed];
    MedType* medtype = new MedType[numMed];
    switch(optionUser) {
        case 1: {cout << "\n\t\t You've chosen ADD MEDICATION" << endl
                      << "\t\tHow many medications do you want to add? ";
                cin >> numMed;
                system("cls");
                for(int i = 0; i < numMed; i++) {
                    med[i].input();
                }
                cout << "\t\tAll medications added successfully!";
                returnorexit();
                system("cls");
                break;}

        case 2: {cout << "\t\tPlease remove medication" << endl; 
                cout << "\t\tEnter the medication name that you would like to delete from the list : " << endl;
                string mdname;
                getline(cin, mdname);
                for(int i=0; i<num; i++){
                    if(mdname == med[i].getMedName()){
                        for(int j=i; j<num-1; j++){
                            med[j] = med[j+1];
                        }
                        num--;
                        break;
                    }
                }
                system("cls");
                break;}
        case 3: cout << "\t\tView calendar" << endl; break;
        case 4: return 0; break;
        default: cout << "\t\tInvalid option!" << endl; break; 
    }

    system("pause");
    return 0;
}