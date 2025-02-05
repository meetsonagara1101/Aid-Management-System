#ifndef SDDS_MENU_H
#define SDDS_MENU_H
#include "Utils.h"
namespace sdds {
    class Menu {
        char* menuContext;
        unsigned int numoption;

    public:
        Menu();
        Menu(const char* MenuContext, unsigned int NumberOptions);
        ~Menu();
        void setEmpty();
        Menu(const Menu& source) = delete;
        Menu& operator=(const Menu& source) = delete;
        unsigned int run() const;
        void set(const char* MenuContext, unsigned int NumberOptions);

    };




}
#endif 


