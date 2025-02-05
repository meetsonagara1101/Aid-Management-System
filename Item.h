#ifndef SDDS_ITEM_H
#define SDDS_ITEM_H
#include "Status.h"
#include "iProduct.h"
#include <iostream>
namespace sdds {
    class Item : public iProduct {
    private:
        double m_price;
        int m_qty;
        int m_qtyNeeded;
        char* m_description;
        bool m_linear;
    protected:
        Status m_state;
        int m_sku;
        bool linear() const;
    public:
        // Constructor
        Item();
        // Rule of three.
        // Destructor
        ~Item();
        // Copy Constructor
        Item(const Item& src);
        // Copy Assignment Operator
        Item& operator=(const Item& src);
        // Public Query Overrides.
        int qtyNeeded()const;
        int qty()const;
        operator double()const;
        // returns if the iProduct is in a good state
        operator bool()const;



        // Public modifier overrides.
        int operator-=(int qty);
        int operator+=(int qty);
        void linear(bool isLinear);

        // Public modifier.
        void clear();
        // ==
        bool operator==(int sku)const;
        bool operator==(const char* description)const;

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

        // set sku
        void setSku(int squ);
        // set status
        void setStatus(const char* Status);
        void printState(std::ostream& ostr) const;
        operator const char* () const;
    };




}
#endif // !SDDS_HealthCard_H



