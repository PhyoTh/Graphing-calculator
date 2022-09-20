#ifndef RPN_H
#define RPN_H
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
using namespace std;

class RPN
{
public:
    RPN();
    RPN(const Queue<Token *> &q);
    void set_input(const Queue<Token *> &q);

    double operator()(double f = 0);
    double evaluate(double f = 0);

private:
    Queue<Token *> que;
};
#endif