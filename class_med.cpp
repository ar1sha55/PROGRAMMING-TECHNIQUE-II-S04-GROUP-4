#include <iostream>
#include <iomanip>
#include <string>
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
    MedType medType;//composition

    public:
        Medication(){}
        Medication(string n, string d, string s, string c, string f): medName(n), dosage(d), medType(s,c,f){}

        string getMedName(){
            return medName;
        }
        /*string getDosage(){
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

int main (){
    int num = 0, choice;
    //Medication med[100];
    Medication *med = new Medication[100];

    do{
    cout << "Your medication: " << endl << endl;
    
    med->output(num);
    for(int i=0; i<num; i++){
        med[i].outputMed();
    }

    cout << "\nPlease enter\n" 
         << "1: Add medication\n"
         << "2: Delete medication\n";
         << "3: No action / Exit program\n";
    cin >> choice;
    cin.ignore();

    switch(choice){
        case 1:
            med[num].input();
            cout << endl;
            num++;
            break;
        
        case 2: 
            string mdname;
            cout << "Enter the medication name that you would like to delete from the list : " << endl;
            getline(cin, mdname);
            for(int i=0; i<num; i++){
                if(mdname == med[i].getMedName()){
                    for(int j=i; j<num-1; j++){
                        med[j] = med[j+1];
                    }
                    num--;
                    break;
                }//else{cout<< "Medication not found";}
            }
            break;
        
        default:
            return 0;
    }    
    }while(choice!=3);
    

    system("pause");
    return 0;
}