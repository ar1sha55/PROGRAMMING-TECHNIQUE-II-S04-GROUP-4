


class Calendar
{
    int year, month;
    string startDate;
    string endDate;
    Medicine medicine[31][7];

    int days(int m, int y){
        switch(m){
            case 2: 28;
            case 4: case 6: case 9: case: 11 return 30;
            default: return 31;
        }
    }


    // KIV
       /*// Helper function to get the starting day of the week
    int startingDay(int m, int y) {
        // Zeller's Congruence algorithm
        if (m < 3) {
            m += 12;
            y--;
        }
        int k = y % 100;
        int j = y / 100;
        int h = (1 + ((13 * (m + 1)) / 5) + k + (k / 4) + (j / 4) + (5 * j)) % 7;
        return ((h + 5) % 7) + 1;
    }*/

    public:
        Calendar(int y, int m): year(y), month(m)
        {
            for(int i = 0; i < 31; i++){
                for(int j = 0; j < 7; j++){
                    medicine[i][j] = Medicine();
                }
            }
        }


        Calendar(string startDate = "", string endDate = ""){
            this->startDate = startDate;
            this->endDate = endDate;
        }
        
        ~Calendar();

        void setYear(int year){ this->year = year;}
        void setMonth(int month){ this->month = month;}

        void setstartDate(const string& startDate){ this->startDate = startDate;}
        void setendDate(const string& endDate){ this->endDate = endDate;}

        string getstartDate () const { return startDate; }  // y must put const?
        string getendDate () const { return endDate; }

        void displayCal () const
        {
            int d = days(month, year);
            int s = startingDay(month, year);
            int day = 1;

            cout << "\tSun\tMon\tTue\tWed\tThu\tFri\tSat\n";
            
        }

};


class Frequency
{
    protected:
        int freqVal;

    public:
        Frequency() : freqVal(0){}
        Frequency(int freqVal):freqVal(freqVal){}

        ~Frequency();

};


class dailyFreq : public Frequency
{
    int time;
    int dailyIntake;

    public:
        dailyFreq(): time(0), dailyIntake(0){}
        dailyFreq(int t, int d): time(t), dailyIntake(d){}

        ~dailyFreq();

        void setTime(int time){ this->time = time; }
        void setdailyIntake(int dailyIntake){ this->dailyIntake = dailyIntake; }
        int getTime() const{ return time; }
        int getdailyIntake() const { return dailyIntake; }


};


class weeklyFreq : public Frequency  //inheritance
{
    int dayPerWeek;

    public:
        weeklyFreq(): dayPerWeek(0){}
        weeklyFreq(int dpw): dayPerWeek(dpw){}

        ~weeklyFreq();

        void setdayPerWeek(int dayPerWeek){ this->dayPerWeek = dayPerWeek; }
        int getdayPerWeek() const{ return dayPerWeek; }

};