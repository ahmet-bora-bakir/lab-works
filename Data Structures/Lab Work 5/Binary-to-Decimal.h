//
//  Binary-to-Decimal.h
//  CENG 218 - Labwork 5
//
//  Created by Ahmet Bora Bakır on 3/29/26.
//

#ifndef Binary_to_Decimal_h
#define Binary_to_Decimal_h

#include "Stack.h"
#include <cmath>
int convertBinaryToInt(char binString[])
{
    Stack<int> stack(999);
    int number = 0;
    try
    {
        
        int i = 0;
        for( ; binString[i] != '\0' ; i++)
                stack.push(int(binString[i]) % 2);
        
        for(int j = 0 ; j < i ; j++)
            number += stack.pop() * pow(2, j);
       
    }
    catch(const char* err)
    {
        cout << err;
    }
    return number;
}


#endif /* Binary_to_Decimal_h */
