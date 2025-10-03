#include "SeqList.h"
#include <string>
using namespace std;
SeqList::SeqList() {
    data = nullptr;
    length = 0;
    //cout << "SeqList created" << endl;
}

SeqList::~SeqList() {
    if (data == nullptr){
        length = 0 ;
        return;
    }
    else {
        delete[] data;
        data = nullptr;
        length = 0 ;
    }
}
bool SeqList::insert() {
    cout << "Enter index and value to insert: ";
    int index, value;
    cin >> index >> value;
    if (index < 0 || index > length) return false;

    int* newData = new int[length + 1];
    for (int i = 0; i < index; i++) newData[i] = data[i];
    newData[index] = value;
    for (int i = index; i < length; i++) newData[i + 1] = data[i];

    delete[] data;
    data = newData;
    length++;
    return true;
}

bool SeqList::remove() {
    int index;
    cout << "enter del index \n";
    cin >> index;
    if (index < 0 || index >= length) return false;

    int* newData = new int[length - 1];
    for (int i = 0; i < index; i++) newData[i] = data[i];
    for (int i = index + 1; i < length; i++) newData[i - 1] = data[i];

    delete[] data;
    data = newData;
    length--;
    return true;
}
int SeqList::get(int index) {
    if (index < 0 || index >= length) return int();
    return data[index];
}

int SeqList::size() {
    return length;
} 

bool SeqList::CreateList() {
    int* temp = new int[100];
    string input;
    int index = 0;
    cout << "Please input numbers (enter @ to exit): ";

    while (index < 100) {
        cin >> input;
        if (input == "@") break;
        temp[index++] = stoi(input);
    }

    length = index;
    data = new int[index];
    for (int i = 0; i < index; i++) {
        data[i] = temp[i];
    }
    delete[] temp;
    return true;
}

void SeqList::print_List() {
    cout << "List elements: ";
    for (int i = 0; i < length; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
}