#include "SeqList.h"
#include "LinList.h"
#include <iostream>
using namespace std;

int main() {
    Base* p = nullptr;
    int ch;

    do {
        cout << "Please select the list type:" << endl;
        cout << "1. Linear List (SeqList)" << endl;
        cout << "2. Linked List (LinList)" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch) {
        case 1:
            p = new SeqList();
            p->CreateList();
            break;
        case 2:
            p = new LinList();
            p->CreateList();
            break;
        case 3:
            cout << "Exiting program." << endl;
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
            continue;
        }

        if (p != nullptr) break;
    } while (true);

    int operation;
    do {
        cout << "\nPlease select an operation:" << endl;
        cout << "1. Insert Element" << endl;
        cout << "2. Delete Element" << endl;
        cout << "3. Get Element" << endl;
        cout << "4. Print List" << endl;
        cout << "5. Get List Size" << endl;
        cout << "6. Reverse List" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> operation;

        int index, value;
        switch (operation) {
        case 1:
            
            
            if (p->insert()) {
                cout << "Insert successful." << endl;
            }
            else {
                cout << "Insert failed. Invalid index." << endl;
            }
            break;
        case 2:
            if (p->remove()) {
                cout << "Remove successful." << endl;
            }
            else {
                cout << "Remove failed. Invalid index." << endl;
            }
            break;
        case 3:
            cout << "Enter index to get: ";
            cin >> index;
            cout << "Element at index " << index << ": " << p->get(index) << endl;
            break;
        case 4:
            p->print_List();
            break;
        case 5:
            cout << "List size: " << p->size() << endl;
            break;
        case 6:
            if (p->reverse()){
                p->print_List();
            cout << "List reversed successfully.\n" << endl;
            }
            else{
                cout << "²Ù×÷Ê§°Ü\n";
            }
            break;
        case 7:
            delete p;
            cout << "Exiting program." << endl;
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    } while (operation != 7);

    return 0;
}