#include <iostream>
#include <iomanip>
#include <string>

class Calendar {
private:
    int year;
    int month;
    struct Medicine {
        bool scheduled;

        // Default constructor
        Medicine() : scheduled(false) {}
    };
    Medicine medicine[31][7]; // Assuming a maximum of 31 days and 7 days a week
    
    // Helper function to get the number of days in a month
    int daysInMonth(int m, int y) {
        switch (m) {
            case 2:
                return (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0)) ? 29 : 28;
            case 4: case 6: case 9: case 11:
                return 30;
            default:
                return 31;
        }
    }

    // Helper function to get the starting day of the week
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
    }

public:
    Calendar(int year, int month) : year(year), month(month) {
        // Initialize medicine array
        for (int i = 0; i < 31; ++i) {
            for (int j = 0; j < 7; ++j) {
                medicine[i][j] = Medicine(); // Assuming Medicine class has a default constructor
            }
        }
    }

    void setYear(int year) {
        this->year = year;
    }

    void setMonth(int month) {
        this->month = month;
    }

    void scheduleMedicine(int day) {
        medicine[day - 1][startingDay(month, year) + (day - 1) % 7].scheduled = true;
    }

    void displayCalendar() const {
        int days = daysInMonth(month, year);
        int startDay = startingDay(month, year);
        int day = 1;

        // Print month and year header
        std::cout << " " << std::setw(20) << std::left << "Calendar: " << std::right << std::setw(10) << year << "-" << std::setw(2) << std::setfill('0') << month << std::setfill(' ') << std::endl;
        std::cout << " Sun Mon Tue Wed Thu Fri Sat" << std::endl;

        // Print leading spaces
        for (int i = 0; i < startDay - 1; ++i) {
            std::cout <<  std::setw(4) << " ";
        }

        // Print days and medicine schedule
        for (int week = 1; day <= days; ++week) {
            for (int i = 1; i <= 7 && day <= days; ++i) {
                std::cout << std::setw(4) << day;
                // Check if medicine is scheduled for the current day
                if (medicine[day - 1][i - 1].scheduled) {
                    std::cout << " (M)";
                } else {
                    std::cout << std::setw(4) << " ";
                }
                day++;
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    Calendar cal(2024, 5); // Example: May 2024
    cal.scheduleMedicine(3); // Schedule medicine for day 3
    cal.scheduleMedicine(10); // Schedule medicine for day 10
    cal.scheduleMedicine(12); // Schedule medicine for day 12
    cal.displayCalendar();
    return 0;
}
