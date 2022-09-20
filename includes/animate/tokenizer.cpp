#include "tokenizer.h"

Queue<Token *> strToinfix(string equation)
{
    string temp = equation;
    Queue<Token *> res;
    while (temp.length() != 0)
    {
        switch (temp[0])
        {
        case ' ':
        {
            temp.erase(0, 1);
            break;
        }
        case 'a':
        {
            if (temp.substr(0, 4) == "asin")
            {
                temp.erase(0, 4);
                res.push(new Function("asin"));
            }
            else if (temp.substr(0, 5) == "asinh")
            {
                temp.erase(0, 5);
                res.push(new Function("asinh"));
            }
            else if (temp.substr(0, 4) == "acos")
            {
                temp.erase(0, 4);
                res.push(new Function("acos"));
            }
            else if (temp.substr(0, 5) == "acosh")
            {
                temp.erase(0, 5);
                res.push(new Function("acosh"));
            }
            else if (temp.substr(0, 4) == "atan")
            {
                temp.erase(0, 4);
                res.push(new Function("atan"));
            }
            else if (temp.substr(0, 5) == "atanh")
            {
                temp.erase(0, 5);
                res.push(new Function("atanh"));
            }
            else
                temp.erase(0, 1);
            break;
        }
        case 's':
        {
            if (temp.substr(0, 3) == "sin")
            {
                temp.erase(0, 3);
                res.push(new Function("sin"));
            }
            else if (temp.substr(0, 4) == "sinh")
            {
                temp.erase(0, 4);
                res.push(new Function("sinh"));
            }
            else if (temp.substr(0, 3) == "sec")
            {
                temp.erase(0, 3);
                res.push(new Function("sec"));
            }
            else if (temp.substr(0, 4) == "sqrt")
            {
                temp.erase(0, 4);
                res.push(new Function("sqrt"));
            }
            else
                temp.erase(0, 1);
            break;
        }
        case 'c':
        {
            if (temp.substr(0, 3) == "cos")
            {
                temp.erase(0, 3);
                res.push(new Function("cos"));
            }
            else if (temp.substr(0, 4) == "cosh")
            {
                temp.erase(0, 4);
                res.push(new Function("cosh"));
            }
            else if (temp.substr(0, 3) == "cot")
            {
                temp.erase(0, 3);
                res.push(new Function("cot"));
            }
            else if (temp.substr(0, 3) == "csc")
            {
                temp.erase(0, 3);
                res.push(new Function("csc"));
            }
            else if (temp.substr(0, 4) == "cbrt")
            {
                temp.erase(0, 4);
                res.push(new Function("cbrt"));
            }
            else
                temp.erase(0, 1);
            break;
        }
        case 'l':
        {
            if (temp.substr(0, 3) == "log")
            {
                temp.erase(0, 3);
                res.push(new Function("log"));
            }
            else if (temp.substr(0, 2) == "ln")
            {
                temp.erase(0, 2);
                res.push(new Function("ln"));
            }
            else
                temp.erase(0, 1);
            break;
        }
        case 't':
        {
            if (temp.substr(0, 3) == "tan")
            {
                temp.erase(0, 3);
                res.push(new Function("tan"));
            }
            else if (temp.substr(0, 4) == "tanh")
            {
                temp.erase(0, 4);
                res.push(new Function("tanh"));
            }
            else
                temp.erase(0, 1);
            break;
        }
        case 'x':
        {
            temp.erase(0, 1);
            res.push(new Function("x"));
            break;
        }
        case 'X':
        {
            temp.erase(0, 1);
            res.push(new Function("X"));
            break;
        }
        case 'e':
        {
            temp.erase(0, 1);
            res.push(new Integer("e"));
            break;
        }
        case '+':
        {
            temp.erase(0, 1);
            res.push(new Operator("+"));
            break;
        }
        case '-':
        {
            temp.erase(0, 1);
            res.push(new Operator("-"));
            break;
        }
        case '*':
        {
            temp.erase(0, 1);
            res.push(new Operator("*"));
            break;
        }
        case '/':
        {
            temp.erase(0, 1);
            res.push(new Operator("/"));
            break;
        }
        case '^':
        {
            temp.erase(0, 1);
            res.push(new Operator("^"));
            break;
        }
        case '(':
        {
            temp.erase(0, 1);
            res.push(new LeftParen());
            break;
        }
        case ')':
        {
            temp.erase(0, 1);
            res.push(new RightParen());
            break;
        }
        default:
        {
            if (isdigit(temp[0]))
            {
                string digit;
                while (isdigit(temp[0]))
                {
                    digit += temp[0];
                    temp.erase(0, 1);
                }
                res.push(new Integer(digit));
            }
            else
                temp.erase(0, 1);
        }
        }
    }
    return res;
}