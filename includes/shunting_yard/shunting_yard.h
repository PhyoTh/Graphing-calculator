#ifndef SHUNTING_YARD_H
#define SHUNTING_YARD_H
#include <cmath>
#include <iostream>
#include <iomanip>
#include <set>
#include <vector>
#include <list>
#include <cassert>
#include <string>
#include <cstring>
#include "../token/token.h"
#include "../token/constants.h"
#include "../token/integer.h"
#include "../token/operator.h"
#include "../queue/MyQueue.h"
#include "../stack/MyStack.h"
#include "../token/function.h"
#include "../token/leftparen.h"
#include "../token/rightparen.h"
#include "../rpn/rpn.h"

class ShuntingYard
{
public:
    ShuntingYard();
    ShuntingYard(const Queue<Token *> &infix); // infix input(can be done with = operator for both)
    void infix(const Queue<Token *> &infix);   // infix input

    Queue<Token *> postfix();                            // return postfix que
    Queue<Token *> postfix(const Queue<Token *> &infix); // return postfix que

private:
    Queue<Token *> que;
};
#endif