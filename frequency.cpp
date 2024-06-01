





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