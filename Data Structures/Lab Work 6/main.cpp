//
//  main.cpp
//  CENG 218 - lab 6
//
//  Created by Ahmet Bora Bakır on 4/2/26.
//

#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node* prev;
    Node* next;
    Node(int data): data(data), next(nullptr), prev(nullptr){}
};

class Stack
{
    Node *top = nullptr;
public:
    bool isEmpty(){if(top == nullptr) return true; return false;}
    void push(int data)
    {
        if(top == nullptr)
        {
            top = new Node(data);
            return;
        }
        Node* temp = new Node(data);
        temp -> next = top;
        top -> prev = temp;
        top = temp;
    }
    void pop()
    {
        if(top == nullptr)
        {
            cout << "Stack is empty.\n";
            return;
        }
        Node* current = top -> next;
        delete top;
        top = current;
    }
    int peek(){if(top == nullptr) throw "Stack is empty\n"; return top -> data;}
    
    void display()
    {
        Node* current = top;
        while(current != nullptr)
        {
            cout << "|" <<current -> data << "|" << endl;
            current = current -> next;
            if(current == nullptr)
                cout << "----" << endl;
        }
    }
};

int main()
{
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.display();
    cout << "Top element: " << s.peek() << endl;
    s.pop();
    s.display();
    return 0;
}
