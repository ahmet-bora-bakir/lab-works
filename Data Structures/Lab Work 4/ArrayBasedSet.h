//
//  ArrayBasedSet.h
//  CENG 218 - Labwork 4
//
//  Created by Ahmet Bora Bakır on 3/19/26.
//

#ifndef ArrayBasedSet_h
#define ArrayBasedSet_h

#include "IntSet.h"

class ArrayBasedSet:public IntSet
{
private:
    static const int MAXSIZE = 12;
    int size_ = 0;
    int items[MAXSIZE];
    // your implementation details and methods
    
public:
    int size()const{return size_;}
    bool isEmpty()const{return size_ == 0;};
    bool isFull()const{return size_ == MAXSIZE;};
    /** Adds a new entry to this set, avoiding duplicates.
     @param newEntry The object to be added as a new entry.
     @return True if the addition is successful, or
     false if the item already is in the set. */
    bool add(int newEntry)
    {
        
        for(int i = 0 ; i < size_ ; i++)
        {
            if(newEntry == items[i])
                return false;
        }
        if(size_ < MAXSIZE)
        {
            items[size_++] = newEntry;
            return true;
        }
        
        return false;
    }
    /** Removes a specific entry from this set, if possible.
     @param anEntry The entry to be removed.
     @return True if the removal was successful, or false if not. */
    bool remove(int anEntry)
    {
        bool flag = false;
        for(int i = 0 ; i < size_ ; i++)
        {
            if(anEntry == items[i])
            {
                for(int j = i ; j < size_ - 1 ; j++)
                    items[j] = items[j + 1];
                flag = true;
                size_--;
            }
        }
        return flag;
    }
    void clear(){size_ = 0;}
    bool contains(int anEntry)
    {
        for(int i = 0 ; i < size_ ; i++)
        {
            if(items[i] == anEntry)
                return true;
        }
        return false;
    }
    string toString()// returns the content of set as a string
    {
        string intStr;
        for(int i = 0 ; i < size_ ; i++)
        {
            int lenghtInt = 0, temp = items[i];
            while(temp != 0)
            {
                temp = temp / 10;
                lenghtInt++;
            }
            
            if(items[i] == 0) lenghtInt++;
            if(items[i] < 0) intStr += "-";
            for(int j = lenghtInt - 1 ; 0 <= j ; j--)
            {
                int temp2 = items[i] / (int)pow(10, j);
                temp2 = temp2 % 10;
                
                intStr = intStr + (char)('0' + abs(temp2));
            }
        }
        return intStr;
    }
};





#endif /* ArrayBasedSet_h */
