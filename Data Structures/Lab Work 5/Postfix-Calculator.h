//
//  Postfix-Calculator.h
//  CENG 218 - Labwork 5
//
//  Created by Ahmet Bora Bakır on 3/29/26.
//

#ifndef Postfix_Calculator_h
#define Postfix_Calculator_h

#include "Stack.h"


bool operatorCheck_(const char a)
{
    if(a != '*' && a != '/' && a != '+' && a != '-')
        return false;
    return true;
}

void postfixCalc(const char* arr)
{
    int arrSize = -1;
    while(arr[++arrSize] != '\0'){}

    
    Stack<float> stack(100);
    
    float sum = 0;
    bool digitRead = false;
    for(int i = 0 ; i < arrSize ; i++)
    {
        if(!operatorCheck_(arr[i]) && arr[i] != ' ' && (arr[i] > '9' || arr[i] < '0'))
            throw "Symbol is undefined.\n";
    
        try
        {
            if (arr[i] >= '0' && arr[i] <= '9')
            {
                sum = sum * 10 + (arr[i] - '0');
                digitRead = true;
            }
            else
            {
                if(digitRead)
                {
                    stack.push(sum);
                    digitRead = false;
                    sum = 0;
                }
            }
            if(operatorCheck_(arr[i]))
            {
                float pop2 = stack.pop();
                float pop1 = stack.pop();
                switch (arr[i])
                {
                    case '*':
                        stack.push(pop1 * pop2);
                        break;
                    case '/':
                        if(pop2 == 0) throw "Number cannot be divided by 0(zero).\n";
                        stack.push(pop1 / pop2);
                        break;
                    case '-':
                        stack.push(pop1 - pop2);
                        break;
                    case '+':
                        stack.push(pop1 + pop2);
                        break;
                }
                
            }
        }
        catch(const char* err)
        {
            cout << err;
        }
    }
    
    cout << "Result: " << stack.pop();
}


#endif /* Postfix_Calculator_h */
