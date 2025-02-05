#define _CRT_SECURE_NO_WARNINGS
#include "Date.h"
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
namespace sdds {

    int maxYearValue = 2030;
    bool Date::validate() {
        bool valid = false;
        int currentYear;
        ut.testMode(false);
        ut.getSystemDate(&currentYear);

        if (year >= currentYear && year <= maxYearValue) {
            if (month >= 1 && month <= 12) {
                int daysInMonth = ut.daysOfMon(month, year);
                if (day >= 1 && day <= daysInMonth) {
                    status.clear();
                    valid = true;
                }
                else {
                    status.set("Invalid day in date", 3);

                };
            }
            else {
                status.set("Invalid month in date", 2);

            };

        }
        else {
            status.set("Invalid year in date", 1);

        };

        return valid;
    };
    int Date::uniqueDateValue() const {
        int uniqueValue = year * 372 + month * 31 + day;
        return uniqueValue;

    };
    Date::Date() {

        ut.getSystemDate(&year, &month, &day);
        status.set(nullptr);
        format = true;



    };
    Date::Date(int Year, int Month, int Day) {
        year = Year;
        month = Month;
        day = Day;
        status.set(nullptr);
        format = true;
        validate();

    };
    Date::~Date() {




    };


    bool Date::operator==(const Date& date) const {
        bool isEqual;
        if (uniqueDateValue() == date.uniqueDateValue()) {
            isEqual = true;

        }
        else {

            isEqual = false;
        };

        return isEqual;


    };

    bool Date::operator!=(const Date& date) const {
        bool isNotEqual;
        if (uniqueDateValue() != date.uniqueDateValue()) {
            isNotEqual = true;
        }
        else {
            isNotEqual = false;

        };


        return isNotEqual;
    };

    bool Date::operator>(const Date& date) const {
        bool isGreater;
        if (uniqueDateValue() > date.uniqueDateValue()) {
            isGreater = true;

        }
        else {
            isGreater = false;

        };

        return isGreater;
    };

    bool Date::operator<(const Date& date) const {
        bool isLess;
        if (uniqueDateValue() < date.uniqueDateValue()) {
            isLess = true;

        }
        else {
            isLess = false;
        };
        return isLess;
    };

    bool Date::operator>=(const Date& date) const {
        bool isGreaterEqual;
        if (uniqueDateValue() >= date.uniqueDateValue()) {
            isGreaterEqual = true;

        }
        else {
            isGreaterEqual = false;

        };
        return isGreaterEqual;
    };

    bool Date::operator<=(const Date& date) const {
        bool isLessEqual;
        if (uniqueDateValue() <= date.uniqueDateValue()) {
            isLessEqual = true;

        }
        else {

            isLessEqual = false;
        };
        return isLessEqual;

    };
    const Status& Date::state() {


        return status;
    };

    void Date::formatted(bool toFormat) {
        format = toFormat;

    };
    Date::operator bool() const {
        return (bool)status;

    };
    std::ostream& Date::write(std::ostream& os) const {
        if (format == true) {
            os << year << "/";
            os.fill('0');
            os.width(2);
            os << month;
            os << "/";
            os.width(2);
            os << day;
        }
        else {
            int yearPrint = year - 2000;

            os << yearPrint;
            os.fill('0');
            os.width(2);
            os << month;
            os.width(2);
            os << day;

        };



        return os;

    };
    std::istream& Date::read(std::istream& istr) {
        int dateEntered;
        istr >> dateEntered;
        if (istr.fail()) {
            status.set("Invalid date value");
        }
        else {
            double x1 = (double)dateEntered / 1000000;

            if (x1 >= 0.1) {
                int tempYear = dateEntered / 10000;

                year = tempYear + 2000;
                int remain = dateEntered - (tempYear * 10000);

                int tempMonth = remain / 100;
                month = tempMonth;
                int remain2 = remain - (tempMonth * 100);
                day = remain2;

            }
            else if (x1 >= 0.001) {
                ut.testMode(true);
                ut.getSystemDate(&year);
                int tempMonth = (double)dateEntered / 100;
                month = tempMonth;
                int remain2 = dateEntered - (tempMonth * 100);
                day = remain2;
            }
            else {
                ut.testMode(true);
                ut.getSystemDate(&year);
                month = 0;
                day = dateEntered;

            };

            if (validate()) {

            }
            else {
                istr.setstate(ios::failbit);
            };

        };
        return istr;
    };
    std::ostream& operator<<(std::ostream& os, const Date& date) {
        return date.write(os);

    };

    std::istream& operator>>(std::istream& istr, Date& date) {
        return date.read(istr);

    };
    void Date::setEmpty() {
        year = 0;
        day = 0;
        month = 0;
        status.set(nullptr);
        format = true;


    };

    Date& Date::operator=(const Date& src) {
        year = src.year;
        month = src.month;
        day = src.day;
        format = src.format;
        status = src.status;
        return *this;
    };
    void Date::save(std::ofstream& ofstr)const {
        int yearPrint = year - 2000;

        ofstr << yearPrint;
        ofstr.fill('0');
        ofstr.width(2);
        ofstr << month;
        ofstr.width(2);
        ofstr << day;



    };

    void Date::setDate(int dateSet) {
        int tempYear = dateSet / 10000;

        year = tempYear + 2000;
        int remain = dateSet - (tempYear * 10000);

        int tempMonth = remain / 100;
        month = tempMonth;
        int remain2 = remain - (tempMonth * 100);
        day = remain2;



    };




}
