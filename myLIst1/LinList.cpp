#include "LinList.h"
LinList::LinList() :val(0), next(nullptr) {}
LinList::LinList(int value, LinList* _next):val(value), next(_next) {}
LinList::~LinList() {}
bool LinList::insert() {
    int side_val, value;
    cout << "请输入位置(在哪个元素的后面)和值\n";
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
    cout << "没有该操作 " << endl;
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
    LinList* curr = this->next;  // 第一个有效节点
    while (curr) {
        LinList* next = curr->next; // 暂存下一个
        curr->next = prev;          // 反转指针
        prev = curr;                // 更新 prev
        curr = next;                // 继续往后
    }
    this->next = prev;  // 头结点指向新的首节点
    return true;
}