//
//  Stack.h
//  CENG 218 - Labwork 5
//
//  Created by Ahmet Bora Bakır on 3/29/26.
//

#ifndef Stack_h
#define Stack_h

#include <iostream>

using std::cout;

template<typename T>
class Stack
{
    T *arr;
    int size;
    int lastIndex;
    
public:
    Stack(int size) : size(size), lastIndex(-1){arr = new T[size]; if(size <= 0) throw "Size must be greater than 0.\n";}
    Stack(): size(0), lastIndex(-1){cout << "Arr size is uninitialized.\n";}
    ~Stack(){size = 0; lastIndex = 0; delete[] arr;}
    
    
    bool isEmpty();
    bool isFull();
    
    void push(T data);
    T top();
    T pop();
    
};

template<typename T>
bool Stack<T>::isEmpty()
{
    if(lastIndex == -1)
        return true;
    return false;
}

template<typename T>
bool Stack<T>::isFull()
{
    if(size - 1 == lastIndex)
        return true;
    return false;
}

template<typename T>
void Stack<T>::push(T data)
{
    if(!isFull())
        arr[++lastIndex] = data;
}

template<typename T>
T Stack<T>::top()
{
    if(lastIndex == -1)
        throw "Stack underflow.\n";
    return arr[lastIndex];
}

template<typename T>
T Stack<T>::pop()
{
    return arr[lastIndex--];
}
#endif /* Stack_h */
