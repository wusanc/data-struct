#pragma once
#ifndef BASE_H
#define BASE_H

#include <iostream>
#include <string>
using namespace std;

class Base
{
private:
public:
     Base();
    virtual ~Base();
    virtual bool insert() = 0;
    virtual bool remove() = 0;
    virtual int get(int index) = 0;
    virtual int size() = 0;
    virtual bool CreateList() = 0;
    virtual void print_List() = 0;
    virtual bool reverse();
};

#endif
