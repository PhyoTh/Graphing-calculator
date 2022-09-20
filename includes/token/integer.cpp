#include "integer.h"

Integer::Integer()
{
}

Integer::Integer(double value)
{
    _val = value;
}

Integer::Integer(string value)
{
    if (value == "e")
        _val = 2.71828182846;
    else
        _val = atoi(value.c_str());
}

void Integer::Print(ostream &outs) const
{
    // outs << "Integer:[" << _val << "]->";
    outs << _val;
}