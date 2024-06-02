#include <iostream>
#include <string>
#include <iomanip>

#include "Medication.h"
#include "MedType.h"
#include "Frequency.h"
#include "DailyFreq.h"
#include "WeeklyFreq.h"
#include "classpatient.h"
#include "RegularPatient.h"
#include "SpecialPatient.h"
#include "Report.h"

using namespace std;


int main(){

    Patient a("alyaqiistina", "ALYA QISTINA BINTI AWALUDDIN", "Abcd1234", "01-07-2004", "F" );

    Medication m("Ibuprofen", "50ml", "tablet", "oval", "pink" );

    Report r("20-09-2015", "20-10-2015", &m, &a);

    r.displayReport(&a, &m);

    //a.setSdate();
    //a.setEdate();

    //string m = a.getMonth();

    //cout << m;

    system("pause");
    return 0;
}