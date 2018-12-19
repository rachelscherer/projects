/* 
 * File:   MyVector.h
 * Author: rachel
 *
 * Created on December 13, 2018, 10:11 AM
 */

#ifndef MYVECTOR_H
#define MYVECTOR_H

//System Libraries
#include <iostream>
#include <new>
using namespace std;

class MyVector {
private:
    int* arr;
    int size;
    int maxSize;
    
    //Error Handling
    void memError();
    void subError();
public:
    //Constructors
    MyVector();
    MyVector(int);
    MyVector(const MyVector&);
    MyVector& operator=(const MyVector&);
    
    int operator[](const int);
    
    //Destructor
    ~MyVector();
    
    //Getters
    int getSize();
    int getMaxSize();
    
    //Setters
    void push(int val);
    void pop();
    
    bool empty();
};

#endif /* MYVECTOR_H */

