#ifndef SDDS_PERISHABLE_H
#define SDDS_PERISHABLE_H
#include "Date.h"
#include "Item.h"
#include <iostream>
namespace sdds {
    class Perishable : public Item {

    private:
        Date m_expiry;
        char* instruction;
    public:
        // Constructor
        Perishable();
        // Rule of three
        // Destructor
        ~Perishable();
        // Copy Constructor
        Perishable(const Perishable& src);
        // Copy Assignement operator
        Perishable& operator=(const Perishable& src);
        // Query
        const Date& expiry() const;
        // Input/Output Overrides.
        // Save
        std::ofstream& save(std::ofstream& ofstr)const;
        // Load
        std::ifstream& load(std::ifstream& ifstr);
        // Display
        std::ostream& display(std::ostream& ostr)const;
        // ReadSku
        int readSku(std::istream& istr);
        // Read
        std::istream& read(std::istream& istr);

        operator bool() const;
    };




}
#endif // !SDDS_HealthCard_H


