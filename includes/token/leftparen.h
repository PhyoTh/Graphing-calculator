#ifndef LEFTPAREN_H
#define LEFTPAREN_H

#include <iostream>
#include <iomanip>
#include <set>
#include <vector>
#include <list>
#include <cassert>
#include <string>
#include "token.h"
using namespace std;

class LeftParen : public Token
{
public:
    LeftParen();
    void Print(ostream &outs = cout) const;
    TOKEN_TYPES TypeOf() { return LEFTPAREN; }
};
#endif