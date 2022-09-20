#include "operator.h"

Operator::Operator()
{
}

Operator::Operator(string op)
{
    _op = op[0];
    if (_op == '+' || _op == '-')
    {
        order = 1;
    }
    if (_op == '*' || _op == '/')
    {
        order = 2;
    }
    if (_op == '^')
    {
        order = 3;
    }
}

Operator::Operator(char op)
{
    _op = op;
    if (_op == '+' || _op == '-')
    {
        order = 1;
    }
    if (_op == '*' || _op == '/')
    {
        order = 2;
    }
    if (_op == '^')
    {
        order = 3;
    }
}

void Operator::Print(ostream &outs) const
{
    // outs << "Operator:[" << _op << "]->";
    outs << _op;
}

double Operator::evaluate(double x, double y)
{
    if (_op == '+')
    {
        return x + y;
    }
    if (_op == '*')
    {
        return x * y;
    }
    if (_op == '-')
    {
        return y - x;
    }
    if (_op == '/')
    {
        return y / x;
    }
    if (_op == '^')
    {
        return pow(y, x);
    }
    return 0;
}
