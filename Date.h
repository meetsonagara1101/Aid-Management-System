#ifndef SDDS_DATE_H
#define SDDS_DATE_H
#include <iostream>
#include "Status.h"
#include "Utils.h"
namespace sdds {



    class Date {
        int year;
        int month;
        int day;
        Status status;
        bool format;
        bool validate();
        int uniqueDateValue() const;



    public:
        Date();
        Date(int Year, int Month, int Day);
        ~Date();
        bool operator==(const Date& date) const;
        bool operator!=(const Date& date) const;
        bool operator<(const Date& date)  const;
        bool operator>(const Date& date)  const;
        bool operator<=(const Date& date) const;
        bool operator>=(const Date& date) const;
        Date& operator=(const Date& src);
        const Status& state();
        void formatted(bool toFormat);
        operator bool() const;
        std::ostream& write(std::ostream& os) const;
        std::istream& read(std::istream& istr);
        void setEmpty(); 
        void save(std::ofstream& ofstr)const;
        void setDate(int dateSet);


    };
    std::ostream& operator<<(std::ostream& os, const Date& date);
    std::istream& operator>>(std::istream& istr, Date& date);





}
#endif 


