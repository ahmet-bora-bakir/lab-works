//
//  main.cpp
//  CENG 218 - Labwork 5
//
//  Created by Ahmet Bora Bakır on 3/29/26.
//

#include <iostream>
#include "Infix-to-Postfix.hpp"
#include "Binary-to-Decimal.h"
#include "Postfix-Calculator.h"

using namespace std;

int main()
{
    char bin[] = "1001101";
    cout << "Binary 1001101 to Decimal: " << convertBinaryToInt(bin) << endl;

    char bin2[] = "1000011";
    cout << "Binary 1000011 to Decimal: " << convertBinaryToInt(bin2) << endl << endl;
    string tests[] =
    {
        "A + B - C",
        "( A + B ) * C",
        "( A + B ) * ( C - D )",
        "A + ( ( B + C ) * ( E - F ) - G ) / ( H - I )",
        "A + B * ( C + D ) - E / F * G + H"
    };

    Fix f;
    for (string t : tests)
    {
        f.getInfix(t);
        f.convertToPostfix(t);
        cout << "Infix Expression: " << t << ";" << endl;
        f.showPostfix();
        cout << endl;
    }

    cout << "Postfix Calc (10 5 + 3 *): " << endl;
    try {
        postfixCalc("10 5 + 3 *");
    } catch (const char* msg) {
        cout << msg << endl;
    }
    cout << endl;

    return 0;
}
