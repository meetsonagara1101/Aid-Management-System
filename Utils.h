#ifndef SDDS_UTILS_H
#define SDDS_UTILS_H
#include <iostream>
namespace sdds {
    const int sdds_testYear = 2023;
    const int sdds_testMon = 03;
    const int sdds_testDay = 31;
    class Utils {
        bool m_testMode = false;
    public:
        void getSystemDate(int* year = nullptr, int* mon = nullptr, int* day = nullptr);
        int daysOfMon(int mon, int year)const;
        void testMode(bool testmode = true);
        unsigned int getIntegerWithRange(unsigned int maxValue, unsigned int minValue = 0, std::istream& istr = std::cin);
        double getDoubleWithRange(double maxValue, double minValue = 0, std::istream& istr = std::cin);
    };
    extern Utils ut;
}

#endif
