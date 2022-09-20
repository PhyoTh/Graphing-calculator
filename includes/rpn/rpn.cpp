#include "rpn.h"

RPN::RPN()
{
}

RPN::RPN(const Queue<Token *> &q)
{
    que = q;
    // cout << "RPN default COTR called" << endl; //
    // que.print_pointers();                      //
}

void RPN::set_input(const Queue<Token *> &q)
{
    que = q;
    // cout << "Rpn set input (postfix) called" << endl;//
    // que.print_pointers();//
}

double RPN::operator()(double f)
{
    return evaluate(f);
}

double RPN::evaluate(double f)
{
    Stack<Token *> stack;
    while (que.size() != 0)
    {
        switch (que.front()->TypeOf())
        {
        case INTEGER:
        {
            // cout << "INTEGER CASE worked" << endl; //
            stack.push(new Integer(static_cast<Integer *>(que.pop())->IntegerOnly()));
            // stack.print_pointers(); //
            break;
        }
        case OPERATOR:
        {
            // cout << "OPERATOR CASE worked" << endl; //
            double x, y;
            x = ((static_cast<Integer *>(stack.pop()))->IntegerOnly());
            y = ((static_cast<Integer *>(stack.pop()))->IntegerOnly());
            stack.push(new Integer(static_cast<Operator *>(que.pop())->evaluate(x, y)));
            // stack.print_pointers(); //
            break;
        }
        case FUNCTION:
        {
            // cout << "FUNCTION CASE worked" << endl; //
            Token *wait = que.pop();
            if ((static_cast<Function *>(wait))->FunctionOnly() == "X" || (static_cast<Function *>(wait))->FunctionOnly() == "x")
                stack.push(new Integer(f));
            if ((static_cast<Function *>(wait))->FunctionOnly() == "sin" || (static_cast<Function *>(wait))->FunctionOnly() == "cos" || (static_cast<Function *>(wait))->FunctionOnly() == "tan" || (static_cast<Function *>(wait))->FunctionOnly() == "cot" || (static_cast<Function *>(wait))->FunctionOnly() == "sec" || (static_cast<Function *>(wait))->FunctionOnly() == "csc" || (static_cast<Function *>(wait))->FunctionOnly() == "asin" || (static_cast<Function *>(wait))->FunctionOnly() == "sinh" || (static_cast<Function *>(wait))->FunctionOnly() == "asinh" || (static_cast<Function *>(wait))->FunctionOnly() == "acos" || (static_cast<Function *>(wait))->FunctionOnly() == "cosh" || (static_cast<Function *>(wait))->FunctionOnly() == "acosh" || (static_cast<Function *>(wait))->FunctionOnly() == "atan" || (static_cast<Function *>(wait))->FunctionOnly() == "tanh" || (static_cast<Function *>(wait))->FunctionOnly() == "atanh" || (static_cast<Function *>(wait))->FunctionOnly() == "abs" || (static_cast<Function *>(wait))->FunctionOnly() == "ln" || (static_cast<Function *>(wait))->FunctionOnly() == "log" || (static_cast<Function *>(wait))->FunctionOnly() == "sqrt" || (static_cast<Function *>(wait))->FunctionOnly() == "cbrt")
            {
                double x = static_cast<Integer *>(stack.pop())->IntegerOnly();
                stack.push(new Integer(static_cast<Function *>(wait)->evaluate(x)));
            }
            if ((static_cast<Function *>(wait))->FunctionOnly() == "max" || (static_cast<Function *>(wait))->FunctionOnly() == "min")
            {
                double x = static_cast<Integer *>(stack.pop())->IntegerOnly();
                double y = static_cast<Integer *>(stack.pop())->IntegerOnly();
                stack.push(new Integer(static_cast<Function *>(wait)->evaluate(x, y)));
            }
            // stack.print_pointers(); //
            break;
        }
        }
    }
    return (static_cast<Integer *>(stack.pop())->IntegerOnly());
}
