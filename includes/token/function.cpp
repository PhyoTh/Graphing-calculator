#include "function.h"

Function::Function()
{
}

Function::Function(string f)
{
    _f = f;
}

double Function::evaluate(double x)
{
    if (_f == "sin")
        return sin(x);
    if (_f == "asin")
        return asin(x);
    if (_f == "sinh")
        return sinh(x);
    if (_f == "asinh")
        return asinh(x);
    if (_f == "cos")
        return cos(x);
    if (_f == "acos")
        return acos(x);
    if (_f == "cosh")
        return cosh(x);
    if (_f == "acosh")
        return acosh(x);
    if (_f == "tan")
        return (sin(x) / cos(x));
    if (_f == "atan")
        return atan(x);
    if (_f == "tanh")
        return tanh(x);
    if (_f == "atanh")
        return atanh(x);
    if (_f == "cot")
        return (cos(x), sin(x));
    if (_f == "sec")
        return (1 / cos(x));
    if (_f == "csc")
        return (1 / sin(x));
    if (_f == "abs")
        return fabs(x);
    if (_f == "ln")
        return log(x);
    if (_f == "log")
        return log10(x);
    if (_f == "sqrt")
        return sqrt(x);
    if (_f == "cbrt")
        return cbrt(x);
    return 0;
}

double Function::evaluate(double x, double y)
{
    if (_f == "max")
        return max(x, y);
    if (_f == "min")
        return min(x, y);
    return 0;
}
void Function::Print(ostream &outs) const
{
    // outs << "Function:[" << _f << "]->";
    outs << _f;
}
