//Main file
#include "Medication.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main (){
    int num = 0, choice;
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
        //<< "3: Logout and view calender\n";
    cin >> choice;
    cin.ignore();
   

    switch(choice){
        case 1:
            med[num].input();
            cout << endl;
            num++;
            system("cls");
            break;
        
        case 2: 
            string mdname;
            bool tf=true;
            do{
                cout << "Enter the medication name that you would like to delete from the list : " << endl;
                getline(cin, mdname);
                for(int i=0; i<num; i++){
                    if(mdname == med[i].getMedName()){
                        tf=true;
                        for(int j=i; j<num-1; j++){
                            med[j] = med[j+1];
                        }
                        num--;
                        break;
                    }else{tf=false; cout<< "Medication not found" << endl;}
                }
            }while(tf==false);
            system("cls");
            break;
        
        //case 3: logout and view calender
    }    
    }while(choice!=3);
    

    system("pause");
    return 0;
}