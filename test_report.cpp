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

    Medication m[]={{"Ibuprofen", "50ml", "tablet", "oval", "pink"},{"Panadol", "50gsm", "Liquid", "None", "Blue"} };

    Report r[] = {{"20-02-2019", "30-02-2019"}, {"01-08-2019", "30-08-2019"}};

    r[1].displayReport(&a);

    for(int i = 0; i < 2; i++)
    {
        cout << "MEDICATION " << i+1 << " : \n\n";
        r[i].displayMed(&m[i]);
    };

    system("pause");
    return 0;
}