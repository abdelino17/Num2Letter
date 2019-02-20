//
// Created by Abdel on 21/03/2018.
//
#include <iostream>
#include "Num2Letter.h"
#include <cstdlib>

using namespace std;

string Num2Letter::enter(string userEnter) {

    string montant = userEnter;
    int longueur = userEnter.size();
    string res ="";

    if(longueur >0 && longueur <4)
    {
        res = Num2Letter::Num2Let(std::atoi(montant.c_str()));
    }else if(longueur >= 4 && longueur < 7)
    {
        res = Num2Letter::Mille2Letter(montant);
    }else if(longueur >=7 && longueur < 10)
    {
        res = Num2Letter::Millions2Letter(montant);

    }else if(longueur >=9 && longueur <= 12)
    {
        res = Num2Letter::Milliards2Letter(montant);

    }else
    {
        res = "0";
    }

    return res;
}

string Num2Letter::Num2Let(int number) {

    string units[20] = {"","un","deux","trois","quatre","cinq","six","sept","huit","neuf","dix","onze","douze","treize","quartoze","quinze","seize","dix-sept","dix-huit","dix-neuf"};
    string tens[10] = {"","dix","vingt","trente","quarante","cinquante","soixante","soixante","quatre-vingt","quatre-vingt"};
    
    int unit = number % 10;
    int ten = (number % 100 - unit) / 10;
    int hund = (number % 1000 - (number % 100)) / 100;

    string unitOut = "";
    string tenOut = "";
    string hundOut = "";

    if (number == 0) {
        return "zero";
    } else {
        unitOut = (unit == 1 && ten>0 && ten != 8 ? "et-" : " ") + units[unit];

        if(ten == 1 && unit > 0)
        {
            tenOut = units[10 + unit];
            unitOut = "";
        }
        else if(ten == 7 || ten == 9)
        {
            tenOut = tens[ten] +"-"+ (ten == 7 && unit == 1 ? "et-" : " " ) + units[10 + unit];
            unitOut = "";
        }else
        {
            tenOut = tens[ten];
        }
        tenOut += (unit == 0 && ten == 8 ? "s" : " ");

        hundOut = (hund > 1 ? units[hund] +"-" :" ") + (hund > 0 ? "cent" : " ") + (hund>1 && ten == 0 && unit == 0 ? "s" : " ");

        return hundOut +  tenOut +  unitOut;

    }
}

string Num2Letter::Mille2Letter(string montant_str) {

    int sizeMille = montant_str.size();
    string end = montant_str.substr(sizeMille-3);
    string deb = montant_str.substr(0,sizeMille-3);

    int endI = std::atoi(end.c_str());
    int debI = std::atoi(deb.c_str());

    string debut = "";
    string fin ="";

    if(endI == 1)
    {
        debut = " mille ";
    }else if(debI == 0)
    {
        debut ="";
    }else
    {
        debut = Num2Let(debI)+" milles ";
    }
    if(endI != 0)
    {
        fin = Num2Let(endI);
    }
    return 	debut+" "+fin;

}

string Num2Letter::Millions2Letter(string montant_str) {

    int sizeMillions = montant_str.size();
    string end = montant_str.substr(sizeMillions-3);
    string middle =  montant_str.substr(sizeMillions-6,3);
    string deb = montant_str.substr(0,sizeMillions-6);

    int endI = std::atoi(end.c_str());
    int debI = std::atoi(deb.c_str());
    int midI = std::atoi(middle.c_str());

    string debut = "";
    string fin = "";

    if(debI==1)
    {
        debut = Num2Let(debI)+" million ";
    }else if(debI == 0)
    {
        debut ="";
    }else
    {
        debut = Num2Let(debI)+" millions ";
    }

    if(endI==0 && midI==0)
    {
        fin = "";
    }else
    {
        fin = Mille2Letter(middle+""+end);
    }
    return debut+" "+fin;
}


string Num2Letter::Milliards2Letter(string montant_str) {
    int sizeMillions = montant_str.size();
    string end = montant_str.substr(sizeMillions-3);
    string middle =  montant_str.substr(sizeMillions-6,3);
    string deb2 =  montant_str.substr(sizeMillions-9,3);
    string deb = montant_str.substr(0,sizeMillions-9);

    std::cout << end << std::endl;
    std::cout << middle << std::endl;
    std::cout << deb2 << std::endl;
    std::cout << deb << std::endl;

    string debut = "";
    string fin = "";

    int endI = std::atoi(end.c_str());
    int debI = std::atoi(deb.c_str());
    int deb2I = std::atoi(deb2.c_str());
    int midI = std::atoi(middle.c_str());

    if(debI==1)
    {
        debut = Num2Let(debI)+" milliard ";
    }else if(debI == 0)
    {
        debut ="";
    }else
    {
        debut = Num2Let(debI)+" milliards ";
    }

    if(endI==0 && midI==0 && deb2I==0)
    {
        fin = "";
    }else
    {
        fin = Millions2Letter(deb2+""+middle+""+end);
    }
    return debut+" "+fin;
}



