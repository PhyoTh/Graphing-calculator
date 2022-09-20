#ifndef TOKEN_H
#define TOKEN_H

#include <cmath>
#include <iostream>
#include <iomanip>
#include <set>
#include <vector>
#include <list>
#include <cassert>
#include "constants.h"
using namespace std;

// Design a class Token with an integer _type to indicate what type of token it is: 1 for numbers, 2 for operators.
class Token
{
public:
    Token();
    friend ostream &operator<<(ostream &outs, const Token *token);
    friend ostream &operator<<(ostream &outs, const Token &token);
    virtual void Print(ostream &outs = cout) const;
    virtual TOKEN_TYPES TypeOf() { return TOKEN; }
};
#endif