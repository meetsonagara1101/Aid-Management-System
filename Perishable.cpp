#define _CRT_SECURE_NO_WARNINGS
#include "Perishable.h"
#include <cstring>
#include <iostream>
#include <fstream>
using namespace std;
namespace sdds {

    Perishable::Perishable() {
        instruction = nullptr;
        m_expiry.setEmpty();



    };

    Perishable::~Perishable() {

        delete[] instruction;

    };

    Perishable::Perishable(const Perishable& src) :Item(src) {
        if (src.instruction != nullptr) {
            instruction = new char[strlen(src.instruction) + 1];
            strcpy(instruction, src.instruction);

        }
        else {
            instruction = nullptr;

        };
        m_expiry.setEmpty();
        m_expiry = src.m_expiry;
    };
    Perishable& Perishable::operator=(const Perishable& src) {
        Item::operator=(src);
        delete[] instruction;
        if (src.instruction != nullptr) {
            instruction = new char[strlen(src.instruction) + 1];
            strcpy(instruction, src.instruction);

        }
        else {
            instruction = nullptr;

        };
        m_expiry = src.m_expiry;
        return *this;
    };

    const Date& Perishable::expiry() const {
        return m_expiry;

    };

    int Perishable::readSku(std::istream& istr) {
        cout << "SKU: ";
        int sku = (int)ut.getIntegerWithRange(39999, 10000, istr);
        (*this).setSku(sku);
        return sku;

    };

    ofstream& Perishable::save(std::ofstream& ofstr)const {
        if (bool(*this)) {
            Item::save(ofstr);
            ofstr << '\t';
            if (instruction != nullptr && strlen(instruction) > 0) {
                ofstr << instruction;
            };
            ofstr << '\t';
            m_expiry.save(ofstr);

        }
        else {
            // do nothing

        };
        return ofstr;
    };

    ifstream& Perishable::load(std::ifstream& ifstr) {
        if (Item::load(ifstr)) {
            char tempInst[1000] = "\0";
            int i = 0;
            while (ifstr.peek() != '\t') {
                tempInst[i] = ifstr.get();
                i += 1;
            };

            delete[] instruction;
            if (strlen(tempInst) > 0) {
                instruction = new char[strlen(tempInst) + 1];
                strcpy(instruction, tempInst);
            }
            else {
                instruction = nullptr;

            };

            ifstr.get();
            int tempDate;
            ifstr >> tempDate;
            m_expiry.setDate(tempDate);
            ifstr.get();

            if (ifstr.fail()) {
                (*this).setStatus("Input file stream read (perishable) failed!");

            };

        };


        return ifstr;

    };

    ostream& Perishable::display(std::ostream& ostr)const {
        if (bool(*this)) {
            if (linear()) {
                Item::display(ostr);
                if (instruction != nullptr && strlen(instruction) > 0) {
                    ostr << "*";
                }
                else {
                    ostr << " ";

                };
                m_expiry.write(ostr);

            }
            else {
                ostr << "Perishable ";
                Item::display(ostr);
                ostr << "Expiry date: ";
                m_expiry.write(ostr);
                ostr << endl;
                if (instruction != nullptr && strlen(instruction) > 0) {
                    ostr << "Handling Instructions: ";
                    ostr << instruction;
                    ostr << endl;

                };
            };


        }
        else {
            (*this).printState(ostr);
        };

        return ostr;
    };

    istream& Perishable::read(std::istream& istr) {
        Item::read(istr);
        delete[] instruction;
        instruction = nullptr;
        cout << "Expiry date (YYMMDD): ";
        m_expiry.read(istr);
        istr.get();
        cout << "Handling Instructions, ENTER to skip: ";
        if (istr.peek() == '\n') {
            istr.get();
        }
        else {
            char tempInst[1000] = "\0";
            int i = 0;
            while (istr.peek() != '\n') {
                tempInst[i] = istr.get();
                i += 1;
            };
            istr.get();
            instruction = new char[strlen(tempInst) + 1];
            strcpy(instruction, tempInst);
        };
        if (istr.fail()) {
            m_state.set("Perishable console date entry failed!");

        };

        return istr;
    };

    Perishable::operator bool() const {
        bool returnValue;
        if (m_sku != 0 && m_state) {
            returnValue = true;
        }
        else {
            returnValue = false;

        };

        return returnValue;
    };


}