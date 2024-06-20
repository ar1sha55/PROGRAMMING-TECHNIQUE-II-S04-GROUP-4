#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>

using namespace std;

class MyException: public exception { //create our own exception class that extended from the built in exception class
    public:
    const char* what() const throw() {
        return "MyException error";
    }
};
class Frequency
{
    // so that child class have access
    protected:
        int freqVal;

    public:
        Frequency() : freqVal(1){}
        Frequency(int freqVal):freqVal(freqVal){}

        // MUTATOR
        void setFreq()
        {
            cout << "\nNumber of doses you need to take at one time : ";
            cin >> freqVal;
        }

        // ACCESSOR
        int getFreq() const { return freqVal; }

        //POLYMORPHISM
        // default print from parent class
        virtual void printFreq()
        {
            cout << "Frequency : " << freqVal << " each time\n";
        }

        // Destructor
        ~Frequency(){}

};

class dailyFreq : public Frequency
{
    
    int dailyIntake;
    double time[10];

    public:
        dailyFreq(): Frequency(1), dailyIntake(1), time() {}
        dailyFreq(int f, int d, double t): Frequency(f), dailyIntake(d) 
        {
            if(d > 1)
            {
                for(int i = 0; i < d; i++)
                {
                    time[i] = t;   
                }
            }
        }


        //DAILY FREQUENCY DESTRUCTOR
        ~dailyFreq(){}


        //AQCUIRE DAILY INTAKE FROM USER
        void setdailyIntake()
        {
            cout << "\nHow many times do you need to take the the medicine in a day?\n";
            cin >> dailyIntake;
        }

        //AQCUIRE TIME FROM USER
        void setTime()
        {
            for(int i = 0; i < dailyIntake; i++)
            {
            cout << "\nWhat's the time no." << i+1 << " you need to take the medication in a day? \n";
            cout << "24hrs system, (hh.mm) : ";
            cin >> time[i];
            }
        }

        //ACCESSORS
        int getdailyIntake() const { return dailyIntake; }
        double getTime(int i) const{ return time[i]; }
        

        //PRINT DAILY FREQUENCY (POLYMORPHISM)
        void printFreq() override
        {
            cout << fixed << setprecision(2);
            Frequency :: printFreq();
            cout << "\nYou need to take " << dailyIntake << "per day.\n";
            cout << "Time: " ;
            for(int i = 0; i < dailyIntake; i++)
            {
            cout <<  time[i] << "\n" << setw(10);
            }
        }

};

class weeklyFreq : public Frequency  //inheritance
{
    int dayPerWeek;

    public:
        weeklyFreq(): Frequency(1), dayPerWeek(1){}
        weeklyFreq(int f, int dpw): Frequency(f), dayPerWeek(dpw){}

        //WEEKLY FRQUENCY DESTRUCTOR
        ~weeklyFreq(){}

        //AQCUIRE DAYPERWEEK FROM USER
        void setdayPerWeek()
        {
            cout << "How many times do you need to take the medication per week?\n";
            cin >> dayPerWeek;
        }

        //ACCESSOR
        int getdayPerWeek() const{ return dayPerWeek; }
        

        //PRINT WEEKLY FREQUENCY (POLYMORPHISM)
        void printFreq() override
        {
            cout << "\nThis medicine needs to be taken " << dayPerWeek << " day(s) per week, and\n";
            Frequency :: printFreq(); // print also the general frequency
        }
};

class MedType {
    string form, shape, color;

    public:
        //constructor
        MedType(){}
        MedType(string f, string s, string c): form(f),shape(s), color(c){}


        //accessor
        string getMedForm() {return form;}
        string getMedShape() {return shape;}
        string getMedColor() {return color;}

        //functions
        void read(){
        cout << "Enter form (tablet, capsule, powder, liquid): ";
        getline(cin, form);
        if (form=="tablet" || form=="capsule"){
            cout << "Enter shape (round, oval): ";
            getline(cin, shape);
        }else{
            shape = "None";
        }
        cout << "Enter color: ";
        getline(cin, color);
        }

        //destructor
        ~MedType(){}
};

class Medication {
    string medName, dosage;
    MedType medType;//composition
    Frequency frequency; //composition
    dailyFreq dFreq;
    weeklyFreq wFreq;

    public:
    //constructor
    Medication(){}
    Medication(string n, string d): medName(n), dosage(d) {}
    Medication(string n, string d, string s, string c, string f): medName(n), dosage(d), medType(s,c,f){}

    //accessors
    string getMedName() {return medName;}
    string getMedDosage() {return dosage;}

    //functions
    void input(){
        cout << "Enter medication name: ";
        cin.ignore();
        getline(cin, medName); 
        cout << "Enter dosage(500mg, 5ml): ";
        getline(cin, dosage);
        medType.read();
        dFreq.setdailyIntake();
        wFreq.setdayPerWeek();
        frequency.printFreq(); //print frequency of medicine intake 
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
        cout << setw(20) << medName << setw(10) << dosage << setw(10) << medType.getMedForm() << setw(10)<< medType.getMedShape() << setw(10) << medType.getMedColor() << endl;
    }

    //destructor
    ~Medication(){}
};

class Patient {
    protected:
    string patientID,  fullname, password, dob, sex;
    Medication *med = nullptr; //aggregation with Medication class

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
    string getsex() const{
        if(sex=="F") return "Female";
        else if(sex=="M") return "Male";
        return "";} //M=Male, F=Female

      virtual void getData() { //for first time
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

    //method to calculate age
    int getAge() {
            int year = stoi(dob.substr(6, 4));
            int age = 2024 - year;
            return age;
}

    void login() {//untuk confirm
        system("cls");
        string pt, pw;
        cout << "\n\t\t<<PLEASE ENTER AGAIN>>" << endl;
        cout << "\t\t<<FOR LOGIN>>" << endl << endl;
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

     virtual void printDetails() {
         cout << "Details of Patient" << endl
         << "ID: " << getID() << endl
         << "Name: " << getname() << endl
         << "DOB: " << getdob() << endl
         //<< "Age: " << getAge() << endl
         << "Sex: " << getsex() << endl;
         /*<< "Medicine name: " << med->getMedName() << endl
         << "Medicine dosage: " << med->getMedDosage() << endl; */
    }

    //method to prescribe med (mutator)
    void setMed(Medication *m) {
        med = m;
    }

    ~Patient() {} //destructor
};

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

    //using polymorphism
    void getData() {
        cout << "\t\tContact info (+60): ";
        getline(cin, contactInfo);
        cout << "\t\tEmergency Contact (+60): ";
        getline(cin, emergencyContact);
    }

    void printDetails() override {
        Patient::printDetails();
        cout << "Contact Info (+60): " << getcontactInfo() << endl
             << "Emergency Contact (+60): " << getemergencyContact() << endl;
    }

    ~RegularPatient() {} //destructor
};

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
    string getrelationship() const{return relationship;}
    string getguardianContact() const{return guardianContact;}

    void getData() {
        cout << "\tGuardian name: ";
        getline(cin, guardianName);
        cout << "\tRelationship with patient: ";
        getline(cin, relationship);
        cout << "\tGuardian contact info (+60): ";
        getline(cin, guardianContact);
    }

    void printDetails() override {
        Patient::printDetails();
        cout << "Guardian Name: " << getguardianName() << endl
             << "Guardian Relationship with Patient: " << getrelationship() << endl
             << "Guardian Contact (+60): " << getguardianContact() << endl;
    }

    ~SpecialPatient() {} //destructor
};


class Report
{
    
    string startDate;
    string endDate;
    Medication *medication[20];  //Aggregation
    Patient *patient;            //Aggregation
    MedType *medtype[20];


    public:
    Report() : startDate(""), endDate(""){}
    Report(string s, string e) : startDate(s), endDate(e) {}

    // MUTATORS
    int setSdate()
    {
        int m,d;
        string sD;
        cout << "When would you like to start your medication? \n";
        
        // Extract month from user
        do{
        cout << "(dd-mm-year) : ";
        getline (cin, sD);
        startDate = sD;
        string a = startDate.substr(3,2);
        m = stoi(a);

        string b = startDate.substr(0,2);
        d = stoi(b);
        
        if(m > 13 || d > 31 ) // notification pop up if month/day entered is invalid
        cout << "Oops! It seems like there's a typo on your date.\n Enter again.";
        } while(m > 13 || d > 31);
        return m;

    }

    // Extract year from user
    string setYear()
    {
        string a;
        a = startDate.substr(6,4);
        return a;
    }

    void setEdate()
    {
        int n, e;
        string eD;
        cout << "When does this medication end? \n";
        
        do{
        cout << "(dd-mm-yyyy) : ";
        getline (cin, eD);
        endDate = eD;
        string c = endDate.substr(3,2);
        n = stoi(c);

        string f = endDate.substr(0,2);
        e = stoi(f);
        
        if(n > 13 || e > 31 ) // notification pop up if month entered is invalid
        cout << "Oops! It seems like there's a typo on your date.\n Enter again.";
        } while(n > 13 || e > 31);
        endDate = eD;
    }

    // ACQUIRE MONTH FROM USER
    string getMonth()
    {
        int m = setSdate();
        
        switch(m)
        {
            case 1 : return "January";
            case 2 : return  "February";
            case 3 : return "March";
            case 4 : return  "April";
            case 5 : return "May";
            case 6 : return "June";
            case 7 : return "July";
            case 8 : return  "August";
            case 9 : return "September";
            case 10 : return  "October";
            case 11 : return "November";
            case 12 : return  "December";
            default : return  "ERROR";
        }


    }


    // ACCESSORS
    string getSdate(){return startDate;}
    string getEdate(){return endDate;}


    void displayReport(Patient *p)
    { 
        string a = setYear();
        
        cout << "\n\n" << setw(55) << a << " MEDICATION REPORT SCHEDULE\n\n";

        cout << "NAME : " << p->getname() << endl;
        cout << "DATE OF BIRTH : " << p->getdob() << endl;
        cout << "SEX : " << p->getsex() << endl << endl << endl;

    }

    // Display medication (Aggregation)
    void displayMed(Medication *m, MedType *mt)
    {
        
        cout << "Date Start - Date End : " << startDate << " - " <<  endDate << "\n";
        cout << "Name" << setw(10) << ":  " << m->getMedName() << "\n";
        cout << "Dosage" << setw(8) << ":  " << m->getMedDosage() << "\n";
        cout << "Form" << setw(10) << ":  " << mt->getMedForm() << "\n";
        cout << "Shape" << setw(9) << ":  " << mt->getMedShape()<< "\n";
        cout << "Color" << setw(9) << ":  " << mt->getMedColor() << "\n\n\n";
    }

    ~Report()
    {
        cout << "YOUR REPORT HAS BEEN DELETED\n\n\n";
    }
    
};

void displayLine() {
    cout << "\t\t";
    for(int i = 0; i < 30; i++) {
        cout << "-";
    }
    cout << endl;
}

int userOption() {
    int useropt;
     cout << "\n\t\tWelcome to MEDICATION SCHEDULER!" << endl
         << "\t\tChoose your task for today." << endl;
    cout << "\t\t[OPTION 1] => Add medication" << endl
         << "\t\t[OPTION 2] => Remove medication" << endl
         << "\t\t[OPTION 3] => See schedule for medicine intake" << endl
         << "\t\t[OPTION 4] => Exit system." << endl << endl;
    cout << "\t\tOPTION => ";
    cin >> useropt;
    return useropt;
}

void returnorexit() {
    int choose;
    cout << "\n\t\tPress [1] to return to menu, [2] to exit system.";
    cin >> choose;
    if(choose == 1)
    userOption();
}

int main() {
     int numMed;

    Patient patient;
    RegularPatient rPatient;
    SpecialPatient sPatient;
    Medication *med = new Medication[50];
    MedType *mt;
    Report report;

    //TIME-FOR MEDICATION INTAKE 
    time_t now = time(nullptr);

    displayLine();
    cout << "\t\t|      HI!! WELCOME TO        |" << endl;
    cout << "\t\t|   MEDICATION SCHEDULER :)   |" << endl;
    displayLine();
    // Print the current time
    cout << "\t\tLOGIN TIME: " << put_time(localtime(&now), "%Y-%m-%d %H:%M:%S") << endl << endl;

   
    patient.getData(); //get patient data
    //patient.login(); //authenticate login process

    if(patient.getAge() < 13 || patient.getAge() > 70) {
        cout << "\tYOU NEED A GUARDIAN." << endl;
        sPatient.getData(); //for special patient
        system("cls");
        sPatient.printDetails();
    }
    else{
        rPatient.getData();
        system("cls");
        rPatient.printDetails();
        } //for regular patient

    while(!false){
    int optionUser = userOption(); //for user option
    switch(optionUser) {
        case 1: {cout << "\n\t\t You've chosen ADD MEDICATION" << endl
                      << "\t\tHow many medications do you want to add? ";
                cin >> numMed;
                system("cls");

                for(int i = 0; i < numMed; i++) {
                    med[i].input();
                }
                cout << "\n\t\tAll medications added successfully!";
                med->outputMed();
                returnorexit();
                system("cls");
                break;}

        case 2: {if(numMed == 0)
                cout << "\n\t\tYou have no record of medication to remove";
                else{
                cout << "\t\tPlease remove medication" << endl; 
                cout << "\t\tEnter the medication name that you would like to delete from the list : " << endl;
                string mdname;
                getline(cin, mdname);
                for(int i=0; i<numMed; i++){
                    if(mdname == med[i].getMedName()){
                        for(int j=i; j<numMed-1; j++){
                            med[j] = med[j+1];
                        }
                        numMed--;
                        break;
                    }
                }
                }
                returnorexit();
                system("cls");
                break;}

        case 3: {cout << "\t\tView report" << endl; 
        report.setSdate();
        report.setEdate();
        report.displayReport(&patient);
        report.displayMed(med, mt);
        break;}
        default: {cout << "\t\tInvalid option!" << endl; 
        userOption();}
        break; 
    }
    }

    system("pause");
    return 0;
}

