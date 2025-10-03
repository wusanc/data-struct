#include "LinList.h"
LinList::LinList() :val(0), next(nullptr) {}
LinList::LinList(int value, LinList* _next):val(value), next(_next) {}
LinList::~LinList() {}
bool LinList::insert() {
    int side_val, value;
    cout << "������λ��(���ĸ�Ԫ�صĺ���)��ֵ\n";
    cin >> side_val >> value;
    bool inserted = false;
    LinList* temp = this->next;
    while (temp) {
        if (temp->val == side_val) {
            LinList* temp1 = new LinList(value, temp->next); 
            temp->next = temp1;
            temp = temp-> next;
            length++;
            inserted = true;
            if (temp->val == side_val) {
                temp = temp->next;
            }
        }
        else {
            temp = temp->next;
        }
    }
    return inserted;
}
bool LinList::remove() {
    int value;
    cout << "please input need remove number's value" << endl;
    cin >> value;
    LinList* current = this->next;
    LinList* prev = this;
    bool removed = false;

    while (current != nullptr) {
        if (current->val == value) {
            prev->next = current->next;
            delete current;
            current = prev->next;
            removed = true;
            length--;
        }
        else {
            prev = current;
            current = current->next;
        }
    }
    return removed;
}
int LinList::get(int index) { 
    cout << "û�иò��� " << endl;
    return false; }
int LinList::size() { return length; }
bool LinList::CreateList() {
    cout << "please input number \n" << "exit input @" << endl;;
    string input;
    LinList* temp = this;
    while (1)
    {
        cin >> input;
        if (input == "@")
            break;
        else
        {
            LinList* temp1 = new LinList(stoi(input), NULL);
            temp->next = temp1;
            temp = temp->next;
            length++;
        }
    }
    return true;
}
void LinList::print_List() {
    LinList* temp = this->next;
    while (temp) {
        cout << temp->val << "   ";
        temp = temp->next;
    }
    cout << endl;
};
bool LinList::reverse() {
    LinList* prev = nullptr;
    LinList* curr = this->next;  // ��һ����Ч�ڵ�
    while (curr) {
        LinList* next = curr->next; // �ݴ���һ��
        curr->next = prev;          // ��תָ��
        prev = curr;                // ���� prev
        curr = next;                // ��������
    }
    this->next = prev;  // ͷ���ָ���µ��׽ڵ�
    return true;
}