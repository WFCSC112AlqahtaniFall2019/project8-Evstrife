//
// Created by Eva Wu on 11/20/19.
//

#ifndef PROJECT8_DATA_H
#define PROJECT8_DATA_H

#include <string>
#include <iostream>
using namespace std;

class data {
public:

    data ();
    data(int n,string name, double hp, double atk, double def, double spatk, double spdef, double sp);
    friend ostream& operator<<(ostream& os, const data& pr);
    friend bool operator >= (const data& hr, const data &d);
    friend bool operator < (const data& hr, const data &d);
    friend bool operator > (const data& hr, const data &d);

private:
    int Num;
    string Name;
    double Hp;
    double Attack;
    double Defence;
    double Spatk;
    double Spdef;
    double Speed;
};


#endif //PROJECT8_DATA_H
