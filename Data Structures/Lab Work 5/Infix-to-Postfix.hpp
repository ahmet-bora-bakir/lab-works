//
//  Infix-to-Postfix.hpp
//  CENG 218 - Labwork 5
//
//  Created by Ahmet Bora Bakır on 3/29/26.
//

#ifndef Infix_to_Postfix_hpp
#define Infix_to_Postfix_hpp

#include "Stack.h"
#include <string>

using std::string;
using std::cout;
using std::endl;

class Fix
{
    string infix,postfix;
    
public:
    string getInfix(string input){infix = input; postfix = ""; return infix;}           //—Stores the infix expression
    void showInfix(){cout << "Infix: " << infix << endl;}            //—Outputs the infix expression
    void showPostfix(){cout << "Postfix: " << postfix << endl;}                //—Outputs the postfix expression
    
   // bool operatorCheck(char a);
    bool precedence(char op1, char op2);
    void convertToPostfix(string input);
    
};

bool operatorCheck(const char a)
{
    if(a != '*' && a != '/' && a != '+' && a != '-')
        return false;
    return true;
}

bool Fix::precedence(char op1, char op2)
{
    if(((op1 == '*' || op1 == '/') && (op2 == '+' || op2 == '-')) || op1 == op2) return true;
    else if((op1 == '+' && op2 == '-') || (op1 == '-' && op2 == '+')) return true;
    else if((op1 == '*' && op2 == '/') || (op1 == '/' && op2 == '*')) return true;
    else return false;
}
void Fix::convertToPostfix(string input)
{
    postfix = "";
    infix = "";
    
    Stack<char> s(100);
    
    for(int i = 0 ; input[i] != '\0' ; i++)
        infix.push_back(input[i]);
    
    for(int i = 0 ; i < infix.size() ; i++)
    {
        if((infix[i] >= 'A' && infix[i] <= 'Z') || (infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= '0' && infix[i] <= '9'))
            postfix.push_back(infix[i]);
        else if(infix[i] == '(')
            s.push(infix[i]);
        
        else if(infix[i] == ')')
        {
            char temp = s.pop();
            while(temp != '(')
            {
                postfix.push_back(temp);
                temp = s.pop();
            }
        }
            
        else if(operatorCheck(infix[i]))
        {
            
            if(!s.isEmpty())
            {
                char temp = s.pop();
                while(precedence(temp, infix[i]) && temp != '(')
                {
                    postfix.push_back(temp);
                    if(s.isEmpty())     break;
                    
                    temp = s.pop();
                }
                if(!precedence(temp, infix[i]) || temp == '(')
                            s.push(temp);
                s.push(infix[i]);
                
                
                
            }
            else    s.push(infix[i]);
            /*
            if(!s.isEmpty())
            {
                char temp = s.pop();
                s.push(temp);
                bool flag = false;
                while(precedence(temp, infix[i]) && !s.isEmpty() && temp != '(')
                {
                    if(s.size() == 1 && flag == false)
                    {
                        s.pop();
                        flag = true;
                    }
                    postfix.push_back(temp);
                    temp = s.pop();
                }
                if(!precedence(temp, infix[i]))
                    s.push(infix[i]);
            }
            else
                s.push(infix[i]);
             */
        }
        
            
    }
    
    while(!s.isEmpty())
        postfix.push_back(s.pop());
        
}


#endif /* Infix_to_Postfix_hpp */
