//MedType class header file
#include <string>
#ifndef MTYPE_H
#define MTYPE_H
using namespace std;

class MedType {
    string form, shape, color;

    public:
        //constructor
        MedType();
        MedType(string , string , string );

        //accessor
        string getForm();
        string getShape();
        string getColor();

        //other function
        void read();

        //destructor
        ~MedType();
};

#endif