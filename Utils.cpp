#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include "Utils.h"
#include <iomanip>

using namespace std;
namespace sdds {
    Utils ut;
    void Utils::testMode(bool testmode) {
        m_testMode = testmode;
    }
    void Utils::getSystemDate(int* year, int* mon, int* day) {
        if (m_testMode) {
            if (day) *day = sdds_testDay;
            if (mon) *mon = sdds_testMon;
            if (year) *year = sdds_testYear;
        }
        else {
            time_t t = std::time(NULL);
            tm lt = *localtime(&t);
            if (day) *day = lt.tm_mday;
            if (mon) *mon = lt.tm_mon + 1;
            if (year) *year = lt.tm_year + 1900;
        }
    }
    int Utils::daysOfMon(int month, int year)const {
        int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
        int mon = (month >= 1 && month <= 12 ? month : 13) - 1;
        return days[mon] + int((mon == 1) * ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
    }

    // User Defined
    unsigned int Utils::getIntegerWithRange(unsigned int maxValue, unsigned int minValue, std::istream& istr) {
        bool keepAsking = true;
        unsigned int returnValue;
        do {
            double Number;
            char a;
            if (istr.peek() == '\n')
            {
                cout << "Invalid Integer, retry: ";
                istr.get();

            }
            else if (istr.peek() == ' ') {
                cout << "Invalid Integer, retry: ";
                while (istr.get() != '\n') {

                };
            }
            else
            {
                istr >> Number;
                if (istr.fail())
                {
                    istr.clear();
                    cout << "Invalid Integer, retry: ";

                    while (istr.get() != '\n')
                    {
                    };

                }
                else
                {
                    a = istr.get();
                    if (a == '\n')
                    {
                        if (Number >= minValue && Number <= maxValue)
                        {
                            keepAsking = false;
                            returnValue = Number;

                        }
                        else
                        {
                            cout << "Value out of range [" << minValue << "<=val<=" << maxValue << "]: ";

                        };

                    }
                    else
                    {
                        cout << "Invalid Integer, retry: ";
                        while (istr.get() != '\n')
                        {

                        };
                    };
                };

            };

        } while (keepAsking);

        return returnValue;

    };
    double Utils::getDoubleWithRange(double maxValue, double minValue, std::istream& istr) {

        bool flag = true;
        double value;
        do {
            double Number;
            char a;
            if (istr.peek() == '\n')
            {
                cout << "Invalid number, retry: ";
                istr.get();

            }
            else if (istr.peek() == ' ') {
                cout << "Invalid number, retry: ";
                while (istr.get() != '\n') {

                };
            }
            else
            {
                istr >> Number;
                if (istr.fail())
                {
                    istr.clear();
                    cout << "Invalid number, retry: ";

                    while (istr.get() != '\n')
                    {
                    };

                }
                else
                {
                    a = istr.get();
                    if (a == '\n')
                    {

                        if (Number >= minValue && Number <= maxValue)
                        {
                            flag = false;
                            value = Number;

                        }
                        else
                        {
                            cout << "Value out of range [" << fixed << setprecision(2) << minValue << "<=val<=" << fixed << setprecision(2) << maxValue << "]: ";

                        };

                    }
                    else
                    {
                        cout << "Invalid number, retry: ";

                        while (istr.get() != '\n')
                        {

                        };
                    };
                };

            };

        } while (flag);

        return value;

    };


}
