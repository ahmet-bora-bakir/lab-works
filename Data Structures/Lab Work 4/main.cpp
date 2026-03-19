//
//  main.cpp
//  CENG 218 - Labwork 4
//
//  Created by Ahmet Bora Bakır on 3/19/26.
//

#include <iostream>
#include "ArrayBasedSet.h"
#include "Node.h"

int main()
{
    IntSet *set1 = new ArrayBasedSet();
    
    set1->add(33);
    set1->add(23);
    set1->add(14);
    set1->add(1);
    set1->add(2);
    set1->add(23);
    set1->add(18);
    set1->add(33);
    set1->add(33);
    set1->add(33);
    
    //cout << (set1) << endl;  I dunno why it is there but labwork file contains that.
    
    
    cout << "Set: " << set1->toString() << endl;

    if(set1->contains(44))
        cout << "Set1 contains 44" << endl;
    else
        cout << "Set1 doesn't contain 44" << endl;
    set1->remove(23);
    
    cout << "After \"23\" was deleted: " << set1 -> toString() << endl;

    cout << "\n--- Linked List Set Test ---" << endl;
    delete set1;
    set1 = new LinkedBasedSet();
    set1->add(33);
    set1->add(23);
    set1->add(14);
    set1->add(1);
    set1->add(2);
    set1->add(23);
    set1->add(18);
    set1->add(33);
    set1->add(33);
    set1->add(33);
    
    cout << "Set: " << set1->toString() << endl;
    
    if(set1 -> contains(44))
        cout << "Set1 contains 44" << endl;
    else
        cout << "Set1 doesn’t contain 44" << endl;
    set1 -> remove(23);
    cout << "Set: " << set1->toString() << endl;
    return 0;
}
