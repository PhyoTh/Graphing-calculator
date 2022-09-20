#ifndef INTEGER_H
#define INTEGER_H

#include <cmath>
#include <iostream>
#include <iomanip>
#include <set>
#include <vector>
#include <list>
#include <cassert>
#include <string>
#include "token.h"
using namespace std;

class Integer : public Token
{
public:
    Integer();
    Integer(double value);
    Integer(string value);

    void Print(ostream &outs = cout) const;
    TOKEN_TYPES TypeOf() { return INTEGER; }
    double IntegerOnly() { return _val; } // example of a function present in a child
private:
    double _val;
};
// Number will have a double member variable named. _val,
#endif