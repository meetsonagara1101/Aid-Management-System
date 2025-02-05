#define _CRT_SECURE_NO_WARNINGS
#include "AidMan.h"
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
namespace sdds {
    unsigned int AidMan::menu() const {
        cout << "Aid Management System" << endl;
        int year, month, day;
        ut.getSystemDate(&year, &month, &day);
        cout << "Date: ";
        cout << year << "/";
        cout.fill('0');
        cout.width(2);
        cout << month;
        cout << "/";
        cout.width(2);
        cout << day << endl;
        if (fileName == nullptr) {
            cout << "Data file: No file" << endl;
        }
        else {
            cout << "Data file: " << fileName << endl;
        };
        cout << "---------------------------------" << endl;

        unsigned int option = menuInfo.run();
        return option;
    };
    AidMan::AidMan() {
        fileName = nullptr;
        menuInfo.set("1- List Items\n2- Add Item\n3- Remove Item\n4- Update Quantity\n5- Sort\n6- Ship Items\n7- New/Open Aid Database\n---------------------------------\n", 7);
        numberItemsArray = 0;
        for (int i = 0; i < sdds_max_num_items; i++) {
            allItems[i] = nullptr;

        };


    };
    AidMan::~AidMan() {
        delete[] fileName;

    };

    void AidMan::run() {
        bool flag = true;
        do {
            unsigned int option = menu();

            if (option != 0 && fileName == nullptr && option != 7) {
                option = 7;

            };

            if (option == 0) {
                cout << "Exiting Program!" << endl;
                flag = false;
                save();
                deallocate();
            }
            else if (option == 1) {
                cout << "\n****" << "List Items" << "****\n";
                list();


            }
            else if (option == 2) {
                cout << "\n****" << "Add Item" << "****\n";

            }
            else if (option == 3) {
                cout << "\n****" << "Remove Item" << "****\n";

            }
            else if (option == 4) {
                cout << "\n****" << "Update Quantity" << "****\n";

            }
            else if (option == 5) {
                cout << "\n****" << "Sort" << "****\n";

            }
            else if (option == 6) {
                cout << "\n****" << "Ship Items" << "****\n";

            }
            else if (option == 7) {
                cout << "\n****" << "New/Open Aid Database" << "****\n";
                load();

            };

        } while (flag);

    };
    void AidMan::save() {
        if (fileName != nullptr) {
            ofstream ofstr(fileName);
            for (int i = 0; i < numberItemsArray; i++) {
                allItems[i]->save(ofstr);
                ofstr << endl;
            };
            ofstr.close();
        };


    };
    void AidMan::deallocate() {
        for (int i = 0; i < numberItemsArray; i++) {
            delete allItems[i];

        };
        numberItemsArray = 0;



    };

    bool AidMan::load() {
        save();
        deallocate();
        cout << "Enter file name: ";
        char tempName[100] = "\0";
        int i = 0;
        while (cin.peek() != '\n') {
            tempName[i] = cin.get();
            i += 1;
        };
        cin.get();
        fileName = new char[strlen(tempName) + 1];
        strcpy(fileName, tempName);
        ifstream ifstr(fileName);
        int noRecordsLoaded = 0;
        if (ifstr.is_open()) {
            while (ifstr.peek() != EOF) {
                char c = ifstr.peek();
                int x = c - 48;
                if (x >= 1 && x <= 3) {
                    allItems[numberItemsArray] = new Perishable;
                }
                else if (x >= 4 && x <= 9) {
                    allItems[numberItemsArray] = new Item;
                }
                else {
                    ifstr.setstate(ios::failbit);

                };
                allItems[numberItemsArray]->load(ifstr);

                if (allItems[numberItemsArray]) {
                    noRecordsLoaded += 1;
                    numberItemsArray += 1;
                }
                else {
                    delete allItems[numberItemsArray];
                };

            };



        }
        else {
            cout << "Failed to open FN for reading!" << endl;
            cout << "Would you like to create a new data file?" << endl;
            cout << "1- Yes!" << endl;
            cout << "0- Exit" << endl;
            cout << ">";
            int optionSelected = (int)ut.getIntegerWithRange(1, 0, cin);
            if (optionSelected == 1) {
                ofstream ofstr(fileName);
                ofstr.close();
            };

        };
        cout << noRecordsLoaded << " records loaded!" << endl << endl;

        bool returnValue;
        if (noRecordsLoaded > 0) {
            returnValue = true;

        }
        else {
            returnValue = false;

        };

        return returnValue;
    };

    int AidMan::list(const char* sub_desc) {
        int noProductsPrinted = 0;
        int indexesPrinted[sdds_max_num_items];
        if (sub_desc == nullptr) {
            if (numberItemsArray > 0) {
                cout << " ROW |  SKU  | Description                         | Have | Need |  Price  | Expiry" << endl;
                cout << "-----+-------+-------------------------------------+------+------+---------+-----------" << endl;
                for (int i = 0; i < numberItemsArray; i++) {
                    cout << " ";
                    cout.fill(' ');
                    cout.width(3);
                    cout << i + 1 << " | ";
                    allItems[i]->linear(true);
                    allItems[i]->display(cout);
                    cout << endl;
                    indexesPrinted[i] = i;

                };

                cout << "-----+-------+-------------------------------------+------+------+---------+-----------" << endl;
                noProductsPrinted = numberItemsArray;
            }
            else {
                cout << "The list is emtpy!" << endl;
            };

        }
        else {
            int i2 = 0;
            for (int i = 0; i < numberItemsArray; i++) {
                if (strstr(*(allItems[i]), sub_desc) != NULL) {
                    indexesPrinted[i2] = i;
                    i2 += 1;
                    noProductsPrinted += 1;
                };


            };

            if (noProductsPrinted > 0) {
                cout << " ROW |  SKU  | Description                         | Have | Need |  Price  | Expiry" << endl;
                cout << "-----+-------+-------------------------------------+------+------+---------+-----------" << endl;
                for (int i = 0; i < noProductsPrinted; i++) {
                    cout << " ";
                    cout.fill(' ');
                    cout.width(3);
                    cout << i + 1 << " | ";
                    allItems[indexesPrinted[i]]->linear(true);
                    allItems[indexesPrinted[i]]->display(cout);
                    cout << endl;


                };
                cout << "-----+-------+-------------------------------------+------+------+---------+-----------" << endl;

            }
            else {
                cout << "The list is emtpy!" << endl;

            };


        };

        if (noProductsPrinted > 0) {
            cout << "Enter row number to display details or <ENTER> to continue:" << endl;
            cout << "> ";

            if (cin.peek() == '\n') {
                cin.get();
                cout << endl;

            }
            else {

                int option = (int)ut.getIntegerWithRange(noProductsPrinted, 1, cin);
                allItems[indexesPrinted[option - 1]]->linear(false);
                allItems[indexesPrinted[option - 1]]->display(cout);
                cout << endl << endl;

            };



        };


        return noProductsPrinted;
    };

}