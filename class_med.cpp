#include <iostream>
using namespace std;

class MedType {
    string form, shape, color;

    public:
        MedType(){}
        MedType(string f, string s, string c): form(f),shape(s), color(c){}

        /*string getForm(){
            return form;
        }
        string getShape(){
            return shape;
        }
        string getColor(){
            return color;
        }*/

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

        ~MedType(){};
};

class Medication {
    string medName, dosage;
    MedType medType;//composition!!!!!!!

    public:
        Medication(){}
        Medication(string n, string d, string s, string c, string f): medName(n), dosage(d), medType(s,c,f){}

        /*string getMedName(){
            return medName;
        }
        string getDosage(){
            return dosage;
        }
        string getMedForm(){
            return medType.getForm
        }
        string getMedShape(){
            return medType.getShape
        }
        string getMedColor(){
            return medType.getColor
        }*/
        
        
        void input(){
            cout << "Enter medication name: ";
            getline(cin,medName);
            cout << "Enter dosage(500mg, 5ml): ";
            getline(cin, dosage);
            medType.read();
        }


        ~Medication(){};
};

int main (){
    int num = 0, choice;
    Medication med[num];
    //cout << "Number of medication to be added: ";
    //cin >> num;
    //cin.ignore();

    cout << "Please enter\n" 
         << "1: Add medication\n"
         << "2: Delete medication\n";
         //<< "3: No action\n";
    cin >> choice;
    cin.ignore();

    switch(choice){
        case 1:
            med[num].input();
            cout << endl;
            num++;
            break;
        
        //case 2: //delete med
        
        //default://display med list
    }    


    /*for(int i=0; i<num; i++){
        med[i].input();
        cout << endl;
    }*/

    system("pause");
    return 0;
}