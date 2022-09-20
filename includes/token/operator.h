#ifndef OPERATOR_H
#define OPERATOR_H
#include <cmath>
#include <iostream>
#include <iomanip>
#include <set>
#include <vector>
#include <list>
#include <cassert>
#include <string>
#include <cstring>
#include "token.h"

// Operator will have a character _op to hold the operator.
// The operator will have a function evaluate() that takes two doubles and returns the resulting double value

class Operator : public Token
{
public:
    Operator();
    Operator(string op);
    Operator(char op);

    double evaluate(double x, double y);
    void Print(ostream &outs = cout) const;
    TOKEN_TYPES TypeOf() { return OPERATOR; }
    char OperatorOnly() { return _op; }
    int _order() { return order; }

private:
    char _op;
    int order = 0;
};
#endif