/* 
 * File:   Vector.cpp
 * Author: rachel
 * 
 * Created on December 13, 2018, 10:11 AM
 */

#include "MyVector.h"

//Default constructor   
MyVector::MyVector(){
    arr = NULL;
    size = 0;
    maxSize = 1;
}

//Constructor
MyVector::MyVector(int size){
    this->size = size;
    this->maxSize = size*2;
    try{
        arr = new int[maxSize];
    }catch(bad_alloc){
        memError();
    }
    for(int i=0;i<size;i++){
        arr[i] = 0;
    }
}

//Copy Constructor
MyVector::MyVector(const MyVector& copy){
    size = copy.size;
    maxSize = copy.maxSize;
    
    try{
        arr = new int[maxSize];
    }catch(bad_alloc){
        memError();
    }
    
    for(int i=0;i<size;i++){
        arr[i] = copy.arr[i];
    }
}

//Destructor
MyVector::~MyVector(){
    delete[] arr;
}

//Overloaded = operator
MyVector& MyVector::operator=(const MyVector& right){
    if(this==&right) return *this;
    delete[] arr;
    
    size = right.size;
    maxSize = right.maxSize;
    
    try{
        arr = new int[maxSize];
    }catch(bad_alloc){
        memError();
    }
    
    for(int i=0;i<size;i++){
        arr[i] = right.arr[i];
    }
    
    return *this;
}

//Overloaded [] operator
int MyVector::operator [](const int num){
    if(num < 0 || num > size - 1) subError();
    return arr[num];
}

//Returns size
int MyVector::getSize(){return size;}

//Returns maxSize
int MyVector::getMaxSize(){return maxSize;}

//Pushes a value to the vector
void MyVector::push(int val){
    size++;
    
    //Double the max size of the vector when size = maxSize
    if(size == maxSize){
        maxSize *= 2;
        try{
            int* newArr = new int[maxSize];
            for(int i=0;i<size-1;i++){
                 newArr[i] = arr[i];
            }
            delete[] arr;
            arr = newArr;
        }catch(bad_alloc){
            memError();
        }
        
    }
    arr[size-1] = val;
}

//Pops a value from the vector
void MyVector::pop(){
    if(size==0){
        cout << "Cannot pop empty vector.\n";
    } else{
        size--;
        
        //Half the maxSize of the vector when size is a quarter of the maxSize
        if(size == maxSize / 4){
            maxSize /= 2;
            try{
                int* newArr = new int[maxSize];
                for(int i=0;i<size;i++){
                    newArr[i] = arr[i];
                }
                delete[] arr;
                arr = newArr;
            }catch(bad_alloc){
                memError();
            }
        } else{
            arr[size] = 0;
        }
    }
}

bool MyVector::empty(){
    if(size==0) return true;
    else return false;
}
//Memory allocation error message
void MyVector::memError(){
    cout << "Error! Cannot allocate memory.\n";
}

//Subscript error message
void MyVector::subError(){
    cout << "Error! Subscript out of range.\n";
}