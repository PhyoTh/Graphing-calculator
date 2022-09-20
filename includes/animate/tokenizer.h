#ifndef TOKENIZER_H
#define TOKENIZER_H
#include <iostream>
#include <string>
#include <cstring>
#include "../token/constants.h"
#include "../queue/MyQueue.h"
#include "../token/function.h"
#include "../token/integer.h"
#include "../token/operator.h"
#include "../token/leftparen.h"
#include "../token/rightparen.h"
#include "../token/token.h"

using namespace std;

Queue<Token *> strToinfix(string equation);
#endif