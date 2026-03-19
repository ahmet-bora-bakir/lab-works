//
//  Node.h
//  CENG 218 - Labwork 4
//
//  Created by Ahmet Bora Bakır on 3/19/26.
//

#ifndef Node_h
#define Node_h

#include "IntSet.h"
using namespace std;
class Node
{
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr){}
    
};

class LinkedBasedSet: public IntSet
{
    Node* head;
    int size_;
public:
    virtual ~LinkedBasedSet() {clear();}
    int size()const{return size_;}
    bool isEmpty()const{return size_ == 0;};
    bool isFull()const
    {
        return false; //It dynamically reserves storage to store data.
    };
    /** Adds a new entry to this set, avoiding duplicates.
     @param newEntry The object to be added as a new entry.
     @return True if the addition is successful, or
     false if the item already is in the set. */
    bool add(int newEntry)
    {
        if(head != nullptr)
        {
            Node* current = head;
            while(current != nullptr)
            {
                if(current -> data == newEntry)
                    return false;
                current = current -> next;
            }
            
        }
        if(head == nullptr)
            head = new Node(newEntry);
        else
        {
            Node* newNode = new Node(newEntry);
            newNode -> next = head;
            head = newNode;
        }
        size_++;
        return true;
    }
    /** Removes a specific entry from this set, if possible.
     @param anEntry The entry to be removed.
     @return True if the removal was successful, or false if not. */
    bool remove(int anEntry)
    {
        if(head == nullptr)
            return false;
        else
        {
            if(head -> data == anEntry)
            {
                Node* temp = head -> next;
                delete head;
                head = temp;;
                return true;
            }
            
        }
        Node* current = head;
        
        while(current -> next != nullptr)
        {
            if(current -> next -> data == anEntry)
            {
                Node* temp = current -> next -> next;
                delete current -> next;
                current -> next = temp;
                size_--;
                return true;
            }
            current = current -> next;
        }
        return false;
    }
    void clear()
    {
        size_ = 0;
        if(head == nullptr)
            return;
        
        Node* current = head;
        
        while(current != nullptr)
        {
            Node* temp = current -> next;
            delete current;
            current = temp;
        }
        head = nullptr;
    }
    bool contains(int anEntry)
    {
        if(head == nullptr)
            return false;
        Node* current = head;
        
        while(current != nullptr)
        {
            if(current -> data == anEntry)
                return true;
            current = current -> next;
        }
        return false;
    }
    
    string toString()// returns the content of set as a string
    {
        if(head == nullptr)
            return "NULL";
        Node* current = head;
        string str;
        while(current != nullptr)
        {
            int temp = current -> data;
            int length = 0;
            while(int(temp / pow(10, length++)) != 0) {}
            
            if(temp == 0) length++;
            else length--;
            if(current -> data < 0) str += "-";
            
            for(int j = length - 1 ; 0 <= j ; j--)
            {
                temp = (int)(current -> data / pow(10, j)) % 10;
                str = str + (char)('0' + abs(temp));
            }
            current = current -> next;
        }
        return str;
    }
};


#endif /* Node_h */
