#pragma once
#ifndef SEQLIST_H
#define SEQLIST_H

#include"Base.h"
class SeqList :public Base
{
private:
    int* data;
    int length;

public:
    SeqList();
    SeqList(int i);
    ~SeqList();
    bool insert();
    bool remove();
    int get(int index);
    int size();
    bool CreateList();
    void print_List();
};

#endif