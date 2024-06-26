#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <exception>
#include <fstream>
#include <vector>
#include <conio.h>

using namespace std;

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
            cout << "\nNumber of DOSE(S) you need to take at one time : ";
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

//------------------------------

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

        // setting daily intake
            cout << "\nHow many TIMES do you need to take the the medicine in a day? ";
            cin >> dailyIntake;
        
        // setting time for user
            for(int i = 0; i < dailyIntake; i++)
            {
            cout << "\nWhat's the time #" << i+1 << " you need to take the medication in a day?\n";
            cout << "24hrs system (HH:MM) : ";
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
            cout << "\nYou need to take " << dailyIntake << " per day.\n";
            cout << "Time: " ;
            for(int i = 0; i < dailyIntake; i++)
            {
                cout << time[i] << "\n" << setw(11) << endl;
            }
            Frequency :: printFreq();
        }

};

//----------------------------------------------------------

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
            cout << "\nHow many times do you need to take the medication per week? ";
            cin >> dayPerWeek;
        }

        //ACCESSOR
        int getdayPerWeek() const{ return dayPerWeek; }
        

        //PRINT WEEKLY FREQUENCY (POLYMORPHISM)
        void printFreq() override
        {
            cout << "\nThis medicine needs to be taken " << dayPerWeek << " day(s) per week, and\n";
            //Frequency :: printFreq(); // print also the general frequency
        }
};

//----------------------------------------------------

class MedType {
    string form, shape, color;

    public:
        //constructor
        MedType(){}
        MedType(string f, string s, string c): form(f), shape(s), color(c){}


        //accessor
        string getMedForm() const {return form;}
        string getMedShape() const {return shape;}
        string getMedColor() const {return color;}

        //mutators
        void setMedForm(const string &f) {form = f;}
        void setMedShape(const string &s) {shape = s;}
        void setMedColor(const string &c) {color = c;}

        //functions
        void read()
        {
        cout << "Enter form (tablet, capsule, powder, liquid): ";
        
        getline(cin, form);
        setMedForm(form);

        if (form=="tablet" || form=="capsule")
        {
            cout << "Enter shape (round, oval): ";
            getline(cin, shape);
            setMedShape(shape);
        }
        
        else if(form == "powder" || form == "liquid")
        {
            shape = "None";
        }

        else shape = "-";

        cout << "Enter color: ";
        
        getline(cin, color);
        setMedColor(color);
        }

        void printMedType()
        {
            cout << "Form" << setw(10) << ":  " << form << "\n";
            cout << "Shape" << setw(9) << ":  " << shape << "\n";
            cout << "Color" << setw(9) << ":  " << color << "\n";        
        }

        //destructor
        ~MedType(){}
};

//-----------------------------------------------

class Medication {
    string medName, dosage;
    MedType medType;//composition
    Frequency frequency; //composition
    dailyFreq dFreq;
    weeklyFreq wFreq;

    public:
    //constructor
    Medication(){}
    //Medication(string n, string d): medName(n), dosage(d) {}
    Medication(string n, string d, string s, string c, string f): medName(n), dosage(d), medType(s,c,f){}

    //accessors
    string getMedName() {return medName;}
    string getMedDosage() {return dosage;}

    //functions
    void input()
    {
        cout << "Enter medication name: ";
        cin.ignore();
        getline(cin, medName); 
        cout << "Enter dosage(500mg, 5ml): ";
        getline(cin, dosage);
        medType.read();
        frequency.setFreq();
        dFreq.setdailyIntake();
        wFreq.setdayPerWeek();
    }

    void freqOutput() 
    {
        wFreq.printFreq();
        dFreq.printFreq();
        cout << "\n\n";
    }

    void medOutput()
    {
        cout << "\t\tName: " << medName << endl;
        cout << "\t\tDosage: " << dosage << endl;
        medType.printMedType();
    }

    void output(int num)
    {
        if(num==0){
            cout << "No medication available.\n" << endl;
        }else{
            cout << left;
            cout << setw(20) << "MEDICATION"<< setw(10) << "DOSAGE" << setw(10) << "FORM" << setw(10) << "SHAPE" << setw(10) << "COLOR" << endl;
        }
    }
    void outputMed(){
        cout << setw(20) << medName << setw(10) << dosage << setw(10) << medType.getMedForm() << setw(10)<< medType.getMedShape() << setw(10) << medType.getMedColor() << "\n";
    }

    void addtoFile(string filename) {
        ofstream outfile(filename, ios::app);
        if (outfile.is_open()) {
            outfile << medName << " " << dosage << " " << medType.getMedForm() << " " << medType.getMedColor() << " " << medType.getMedShape() << endl;
            outfile.close();
        } else {
            cout << "Error opening file for writing patient data." << endl;
        }
    }

    //destructor
    ~Medication(){}
};

//----------------------------------------------------

class Patient {
    protected:
    string patientID,  fullname, password, dob, sex;
    Medication *med = nullptr; //aggregation with Medication class

    public:
    class Wrong{};
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
        if(sex=="f") return "Female";
        else if(sex=="m") return "Male";
        return "";} //M=Male, F=Female

    virtual void getData() { //for first time
        cout << "\t\t<< ENTER DETAILS >>" << endl
             << "\t\t<< TO REGISTER >>" << endl << endl;
        cout << "\t\tPatient ID: ";
        getline(cin, patientID);
        setID(patientID);
        cout << "\t\tFull Name: ";
        getline(cin, fullname);
        cout << "\t\tPassword (no space): ";
        char ch = getch();
        while (ch != 13) { // hide password
            password.push_back(ch);
            cout << '*';
            ch = getch();
        }
        setpassword(password);
        cout << "\n\t\tDate of Birth (DD/MM/YYYY): ";
        getline(cin, dob);
        cout << "\t\tGender (M/F): ";
        getline(cin, sex);
        for(int i = 0; i < sex.length(); i++){
            sex = tolower(sex[i]);
        } 
    }

    //method to calculate age (assume DD/MM/YYYY format)
    int getAge() const {
            int year;
            int age = 0;
            try{
                if(dob.length() > 7) {
                    size_t pos1 = dob.find('/');
                    size_t pos2 = dob.find('/', pos1 + 1);
                    year = stoi(dob.substr(pos2 + 1, 4)); 
                    age = 2024 - year;
                } else {
                    throw (age);
                }

            } catch(...) {
                cout << "\n\t\tSorry, cannot extract your age from DOB." << endl;
            }

            return age;
        }


  void login() {
    string pt, pw;

    cout << "\n\t\t<< LOGIN >>" << endl << endl;

    cout << "\t\tPatient ID: ";
    getline(cin, pt);
    cout << "\t\tPassword (no space): ";
    char ch = getch();
    while (ch!=13){ // hide password
        pw.push_back(ch);
        cout << '*';
        ch = getch();
    }
    //login credentials
    if (pt == getID() && password == getpassword()) {
        cout << "\n\t\tLOGIN SUCCESSFUL." << endl;
    } else {
        cout << "\n\t\t!Invalid ID or Password!" << endl;
        cout << "\t\tEnter again." << endl;
        login(); 
    }
}

     virtual void printDetails() const{
        cout << "\t\t---PATIENT DETAILS---" << endl;
        cout << "\t\tNAME          : " << getname() << endl
             << "\t\tDATE OF BIRTH : " << getdob() << endl
             << "\t\tGENDER        : " << getsex() << endl 
             << "\t\tAGE           : " << getAge() << endl << endl;
    }

    //method to prescribe med (mutator)
    void setMed(Medication *m) {
        med = m;
    }

    void addPatientFile() {
    ofstream outfile("patient_list.txt", ios::app);
        if (outfile.is_open()) {
            outfile << patientID << " " << fullname << " " << password << " " << dob << " " << sex << endl;
            outfile.close();
        } else {
            cout << "Error opening file for writing patient data." << endl;
        }

        //for each patient (Example: Arisha_med_history.txt)
        string medFilename = fullname + "_med_history.txt";
        ofstream medFile(medFilename);
        if (medFile.is_open()) {
                med->addtoFile(medFilename);
        } else {
            cout << "Error opening file for writing medications." << endl;
        }

        medFile.close();
}
    ~Patient() {} //destructor
};

//------------------------------------------------------

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
        Patient::getData();
        cout << "\t\tContact Info (+60): ";
        getline(cin, contactInfo);
        cout << "\t\tEmergency Contact (+60): ";
        getline(cin, emergencyContact);
    }

    ~RegularPatient() {} //destructor
};

//-------------------------------------------------------

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
        cout << "\t\tGuardian Name: ";
        getline(cin, guardianName);
        cout << "\t\tRelationship with Patient: ";
        getline(cin, relationship);
        cout << "\t\tGuardian Contact Info (+60): ";
        getline(cin, guardianContact);
    }

    ~SpecialPatient() {} //destructor
};

//----------------------------------------------

class Report
{
    double startDate, endDate;
    Medication *med = new Medication[50];
    Patient *patient;           
    MedType *medtype = new MedType[50];
    Frequency *freq = new Frequency[50];

   public:
    Report() : startDate(0), endDate(0){}
    Report(double s, double e) : startDate(s), endDate(e) {}

    // MUTATORS
    void setSdate()
    {
        cout << "End Date and Time (YYMMDD.HHMM): ";
        cin >> startDate;
        cin.ignore();
    }

    void setEdate()
    {cout << "End Date and Time (YYMMDD.HHMM): ";
     cin >> endDate;
     cin.ignore();}


    // ACCESSORS
    double getSdate(){return startDate;}
    double getEdate(){return endDate;}

     void displayReport(Patient *p)
    { 

        cout << "\n\n" << setw(35) << 2024 << " MEDICATION REPORT SCHEDULE\n\n";

        p->printDetails();
    }

    // Display medication (Aggregation)
    void displayMedSchedule(Medication *m, MedType *mt, int medCount, double currentDateTime) {
    for (int i = 0; i < medCount; ++i) {
        if (startDate < currentDateTime) {
            cout << "\t\tPast Medicine(s): " << endl;
            cout << "Start Date - End Date: " << startDate << " - " << endDate << endl;
            m[i].medOutput();
            m[i].freqOutput();
            cout << endl;
        } else if (startDate >= currentDateTime) {
             cout << "\t\tCurrent Medicine(s): " << endl;
            cout << "Start Date - End Date: " << startDate << " - " << endDate << endl;
            m[i].medOutput();
            m[i].freqOutput();
            cout << endl;
        }
    }
}
    ~Report(){}
    
};

//-------------------------------------------------------

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
         << "\t\t[OPTION 3] => View history" << endl
         << "\t\t[OPTION 4] => View report and exit system." << endl << endl;
    cout << "\t\tOPTION => [ ]\b\b";
    cin >> useropt;
    system("cls");
    return useropt;
}

int returnorexit() {
    int choose;
    cout << "\n\t\tPress [1] to return to menu, [2] to exit system [ ]\b\b";
    cin >> choose;
    return choose;
    system("cls");
}

void case4(int numMed, Medication med[], Report report[], Patient patient, MedType mt[], double currentDateTime) {
    cout << "\t\tYou have chosen to VIEW REPORT and EXIT SYSTEM.\n\n";
    displayLine();

    if (numMed == 0) {
        report[0].displayReport(&patient);
        cout << "\n\n *You have no medication scheduled.\n\n";
    } else {
        for (int i = 0; i < numMed; i++) {
            cout << "DATES FOR MEDICATION " << i + 1 << " : " << med[i].getMedName() << "\n";
            cout << "When would you like to start your medication " << i + 1 << " ? ";
            report[i].setSdate();

            cout << "When does this medication " << i + 1 << " end? ";
            report[i].setEdate();

            system("cls");
        }

        report[0].displayReport(&patient); // Display report, display patient's information
        for (int i = 0; i < numMed; ++i) {
            report[0].displayMedSchedule(&med[i], &mt[i], numMed, currentDateTime);
        }
    }

    system("pause");
}

int main() {

    int addMedNum=0, removeMedNum=0, numMed=0;
    string addMed[20]; //store name of meds added 
    string removeMed[20];  //store name of meds removed

    Patient* patient;
    RegularPatient rPatient;
    SpecialPatient sPatient;
    Medication *med = new Medication[50];
    MedType *mt = new MedType[50];
    Report *report = new Report[50];
    Frequency *freq = new Frequency[50];

    //TIME-FOR MEDICATION INTAKE 
    time_t t = time(0);
    struct tm* now = localtime(&t);
    double currentDateTime = (now->tm_year-100) * 10000 + (now->tm_mon + 1) * 100 + now->tm_mday + (now->tm_hour / 100.0) + (now->tm_min / 10000.0);

    displayLine();
    cout << "\t\t|       HI!! WELCOME TO        |" << endl;
    cout << "\t\t| 2024 MEDICATION SCHEDULER :) |" << endl;
    displayLine();
    // print the current time
    cout << "\t\tCURRENT TIME: " << put_time(localtime(&t), "%Y-%m-%d %H:%M:%S") << endl << endl;

    rPatient.getData(); //get patient data
    patient = &rPatient;


    system("cls");

    patient->login(); //authenticate login process

    int age = patient->getAge();

    if(age < 13 || age > 70) {
        cout << "\n\t\tYOU NEED A GUARDIAN." << endl;
        sPatient.getData(); //for special patient
        sPatient.printDetails();
        system("cls");
    }

    patient->printDetails();

    bool exit = 0;

    while(!exit)
    {
    switch(userOption()) 
    {
         case 1: 
        {
            cout << "\n\t\tYou have chosen to ADD MEDICATION" << endl;
            displayLine();
            cout << "\t\tHow many medications do you want to add? [   ]\b\b\b";
            cin >> numMed;
            system("cls");

                for (int i = 0; i < numMed; ++i) 
                {
                    cout << "\n\nMEDICATION " << i+1 << " : \n\n";
                    med[i].input();
                    patient->setMed(med); //point to med
                    string medname = med[i].getMedName();
                    patient->addPatientFile();
                    addMed[addMedNum++] = medname;
                    system("cls");
                }
            med->output(numMed);
            for(int j = 0; j < numMed; j++) {
                med[j].outputMed();}

            int c = returnorexit();
            if(c==2)
            case4(numMed, med, report, *patient, mt, currentDateTime);
            break;
        }

        case 2: 
        {
            if(numMed == 0){
                cout << "\n\t\t! ERROR !" << endl
                << "\t\tYou have no record of medication to remove" << endl 
                << "\t\tPress 1 to add medication" << endl << endl;
            }
            else
            {
                string mdname;
        
                cout << "\t\tYou have chosen REMOVE MEDICATION" << endl;
                displayLine();
                cout << "\t\tEnter the medication name that you would like to delete from the list : ";
                getline(cin, mdname);

                bool found = false;
                for(int i=0; i<numMed; i++)
                {
                    if(mdname == med[i].getMedName())
                    {
                        found = true;
                        removeMed[removeMedNum++] = med[i].getMedName();
                        for(int j=i; j<numMed-1; j++){
                            med[j] = med[j+1];
                            patient->setMed(med);
                        }
                        numMed--;
                        break;
                    }
                }
                if(!found) cout << "\n\t\tError! Medicine cannot be found.\n\n";
            }
                int c = returnorexit();
                if(c==2)
                case4(numMed, med, report, *patient, mt, currentDateTime);
                break;
        }

        case 3: 
       {system("cls");
        cout << "\t\tYou have chosen VIEW HISTORY" << endl;
        displayLine();

        cout << "\t\tLIST OF MEDICINE(S) ADDED: " << endl;
        for(int k = 0; k < addMedNum; k++) {
            cout << k+1 << ". " << addMed[k] << endl << endl;
        }
        
        cout << "\t\tLIST OF MEDICINE(S) REMOVED: " << endl;
        for(int j = 0; j < removeMedNum; j++) {
            cout << j+1 << ". " << removeMed[j] << endl << endl;
        }

        int c = returnorexit();
        system("cls");
            if(c==2)
            case4(numMed, med, report, *patient, mt, currentDateTime);
            break;}

        case 4:{case4(numMed, med, report, *patient, mt, currentDateTime);}

        default: 
        {
            cout << "\t\tInvalid option!" << endl
                 << "\t\tChoose between [1] to [4]" << endl << endl;
            int c = returnorexit();
            if(c==2)
            exit = 1;
        }
        break; 
    }
    }

    delete[] freq;
    delete[] report;
    delete[] mt;
    delete[] med;
    system("pause");
    return 0; 
}
