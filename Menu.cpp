#define _CRT_SECURE_NO_WARNINGS
#include "Menu.h"
#include <iostream>
#include <cstring>
using namespace std;
namespace sdds {

    Menu::Menu() {
        setEmpty();
    };

    Menu::Menu(const char* MenuContext, unsigned int NumberOptions) {
        if (NumberOptions <= 15 && NumberOptions >= 1 && MenuContext != nullptr && strlen(MenuContext) > 0) {
            numoption = NumberOptions;
            menuContext = new char[strlen(MenuContext) + 1];
            strcpy(menuContext, MenuContext);

        }
        else {
            setEmpty();
        };


    };

    Menu::~Menu() {
        delete[] menuContext;

    };

    void Menu::setEmpty() {
        menuContext = nullptr;
        numoption = -1;

    };

    unsigned int Menu::run() const {
        cout << menuContext;
        cout << "0- Exit" << endl;
        cout << "> ";
        unsigned int optionNumber = ut.getIntegerWithRange(numoption);
        return optionNumber;

    };

    void Menu::set(const char* MenuContext, unsigned int NumberOptions) {
        delete[] menuContext;
        menuContext = new char[strlen(MenuContext) + 1];
        strcpy(menuContext, MenuContext);
        numoption = NumberOptions;
    };


}