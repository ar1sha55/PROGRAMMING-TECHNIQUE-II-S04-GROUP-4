//MedType implementation file
#include "MedType.h"
#include <iostream>
#include <string>
using namespace std;

//class MedType
MedType::MedType(){}
MedType::MedType(string f, string s, string c): form(f),shape(s), color(c){}
string MedType::getForm(){
    return form;
}
string MedType::getShape(){
    return shape;
}
string MedType::getColor(){
    return color;
}
void MedType::read(){
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
MedType::~MedType(){}