#ifndef FUNCTION_H
#define FUNCTION_H
#include <cmath>
#include <iostream>
#include <iomanip>
#include <set>
#include <vector>
#include <list>
#include <cassert>
#include <string>
#include <math.h>
#include "token.h"
using namespace std;

class Function : public Token
{
public:
    Function();
    Function(string f);

    double evaluate(double x);
    double evaluate(double x, double y);
    void Print(ostream &outs = cout) const;
    TOKEN_TYPES TypeOf() { return FUNCTION; }
    string FunctionOnly() { return _f; }

private:
    string _f;
};
#endif