


class Calendar
{
    string startDate;
    string endDate;

    public:
        Calendar();
        Calendar(string startDate = "", string endDate = ""){
            this->startDate = startDate;
            this->endDate = endDate;
        }
        Medicine medicine[50];
        ~Calendar();

        void setstartDate(const string& startDate){ this->startDate = startDate;}
        void setendDate(const string& endDate){ this->endDate = endDate;}

        string getstartDate () const { return startDate; }  // y must put const?
        string getendDate () const { return endDate; }

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


class weeklyFreq : public Frequency
{
    int dayPerWeek;

    public:
        weeklyFreq(): dayPerWeek(0){}
        weeklyFreq(int dpw): dayPerWeek(dpw){}

        ~weeklyFreq();

        void setdayPerWeek(int dayPerWeek){ this->dayPerWeek = dayPerWeek; }
        int getdayPerWeek() const{ return dayPerWeek; }

};