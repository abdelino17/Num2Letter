//
// Created by Abdel on 21/03/2018.
//

#include <string>
#ifndef NUM2LETTER_NUM2LETTER_H
#define NUM2LETTER_NUM2LETTER_H

using namespace std;

class Num2Letter {

public:
    static string Milliards2Letter(string montant_str);
    static string Millions2Letter(string montant_str);
    static string Mille2Letter(string montant_str);
    static string Num2Let(int number);
    static string enter(string userEnter);
};


#endif //NUM2LETTER_NUM2LETTER_H
