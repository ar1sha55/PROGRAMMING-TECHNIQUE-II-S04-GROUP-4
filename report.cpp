#include <iostream>
using namespace std;

#include <string>
#include <cmath>
#include <iomanip>


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
            cout << "Enter form (tablet, capsule, powder, liquid): ";
            getline(cin, form);
            if (form=="tablet" || form=="capsule"){
                cout << "Enter shape (round, oval): ";
                getline(cin, shape);
            }else{
                shape = "Not Applicable";
            }
            cout << "Enter color: ";
            getline(cin, color);

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
        string getDosage(){
            return dosage;
        }
        string getMedForm(){
            return medType.getForm();
        }
        string getMedShape(){
            return medType.getShape();
        }
        string getMedColor(){
            return medType.getColor();
        }
        
        
        void input(){
            cout << "Enter medication name: ";
            getline(cin, medName); 
            cout << "Enter dosage(500mg, 5ml): ";
            cin.ignore();
            getline(cin, dosage);
            medType.read();
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



// CLASS REPORT

class Report
{
    
    string startDate;
    string endDate;
    Medication *medication;

    public:
    Report() : startDate(""), endDate(""), medication(nullptr){}
    Report(string s, string e, Medication *m) : startDate(s), endDate(e), medication(m) {}

    // MUTATORS
    int setSdate()
    {
        int m,d;
        string sD;
        cout << "When would you like to start your medication? \n";
        
        do{
        cout << "(dd-mm-year) : ";
        getline (cin, sD);
        startDate = sD;
        string a = startDate.substr(3,2);
        m = stoi(a);

        string b = startDate.substr(0,2);
        d = stoi(b);
        
        if(m > 13 || d > 31 ) // notification pop up if month entered is invalid
        cout << "Oops! It seems like there's a typo on your date.\n Enter again.";
        } while(m > 13 || d > 31);
        return m;

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
            case 2 : return "February";
            case 3 : return "March";
            case 4 : return "April";
            case 5 : return "May";
            case 6 : return "June";
            case 7 : return "July";
            case 8 : return "August";
            case 9 : return "September";
            case 10 : return "October";
            case 11 : return "November";
            case 12 : return "December";
            default: return "ERROR";
        }

    }


    // ACCESSORS
    string getSdate(){return startDate;}
    string getEdate(){return endDate;}


    ~Report()
    {
        cout << "YOUR REPORT HAS BEEN DELETED\n\n\n";
    }

    void displayReport(Medication *m)
    {
        string bulan = getMonth();
        int i;
        cout << setw(55) << bulan <<" Medication Report Schedule\n\n";

       // for(int i = 1; i < totalMed; i++)
       cout << "MEDICATION " << i << ": \n\n";
       cout << "Date Start - Date End : " << startDate << endDate << "\n";
       cout << "Name" << setw(10) << ":  " << m->getMedName() << "\n";
       cout << "Dosage" << setw(8) << ":  " << m->getDosage() << "\n";
       cout << "Form" << setw(10) << ":  " << m->getMedForm() << "\n";
       cout << "Shape" << setw(9) << ":  " << m->getMedShape()<< "\n";
    }
    
};


int main(){

    Report a;

    a.setSdate();
    a.setEdate();

    string m = a.getMonth();

    cout << m;

    system("pause");
    return 0;
}