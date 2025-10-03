#pragma once
#ifndef LINLIST_H
#define LINLIST_H

#include "Base.h"
class LinList :public Base
{
private:
    LinList* next;
    int val;
    int length;
public:
    LinList();
    LinList(int value, LinList* _next);
    ~LinList();
    bool insert();
    bool remove();
    int get(int index);
    int size();
    bool CreateList();
    void print_List();
    bool reverse();
};

#endif