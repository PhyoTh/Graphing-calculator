#include "shunting_yard.h"

ShuntingYard::ShuntingYard()
{
}

ShuntingYard::ShuntingYard(const Queue<Token *> &infix) // infix input(can be done with = operator for both)
{
    que = infix;
    // cout << "\ndefault CTOR called" << endl;   //
    // que.print_pointers();                      //
    // cout << "\n---------------------" << endl; //
}

void ShuntingYard::infix(const Queue<Token *> &infix) // infix input
{
    que = infix;
    // cout << "\ninfix(infix) void called" << endl; //
    // cout << "---------------------" << endl;      //
    // que.print_pointers();                         //
}

Queue<Token *> ShuntingYard::postfix() // return postfix que
{
    // cout << "postfix get called" << endl; //
    Stack<Token *> stack;
    Queue<Token *> res;
    while (que.size() != 0)
    {
        switch (que.front()->TypeOf())
        {
        case INTEGER:
        {
            // cout << "\nINTEGER CASE WORKED" << endl; //
            // cout << "This is que: ";                 //
            // que.print_pointers();                    //
            res.push(new Integer(static_cast<Integer *>(que.pop())->IntegerOnly()));
            // cout << "\nThis is res: "; //
            // res.print_pointers();      //
            break;
        }
        case FUNCTION:
        {
            // cout << "FUNCTION CASE WORKED" << endl; //
            stack.push(new Function(static_cast<Function *>(que.pop())->FunctionOnly()));
            // cout << "\nThis is stack: "; //
            // stack.print_pointers();      //
            break;
        }
        case OPERATOR:
        {
            // cout << "\nOPERATOR CASE WORKED" << endl; //
            Token *wait = que.pop();
            // cout << "This is que: "; //
            // que.print_pointers();    //
            if (stack.empty())
            {
                stack.push(new Operator(static_cast<Operator *>(wait)->OperatorOnly()));
                // cout << "\nThis is stack: "; //
                // stack.print_pointers();      //
            }
            else if (stack.top()->TypeOf() == LEFTPAREN)
            {
                stack.push(new Operator(static_cast<Operator *>(wait)->OperatorOnly()));
                // cout << "\nThis is stack: "; //
                // stack.print_pointers();      //
            }
            else if (stack.top()->TypeOf() == FUNCTION)
            {
                res.push(new Function(static_cast<Function *>(stack.pop())->FunctionOnly()));
                if (stack.empty())
                {
                    stack.push(new Operator(static_cast<Operator *>(wait)->OperatorOnly()));
                    // cout << "\nThis is stack: "; //
                    // stack.print_pointers();      //
                }
                else if (stack.top()->TypeOf() == LEFTPAREN)
                {
                    stack.push(new Operator(static_cast<Operator *>(wait)->OperatorOnly()));
                    // cout << "\nThis is stack: "; //
                    // stack.print_pointers();      //
                }
                else if (static_cast<Operator *>(stack.top())->_order() < static_cast<Operator *>(wait)->_order())
                {
                    stack.push(new Operator(static_cast<Operator *>(wait)->OperatorOnly()));
                }
                else if (static_cast<Operator *>(stack.top())->_order() >= static_cast<Operator *>(wait)->_order())
                {
                    while (static_cast<Operator *>(stack.top())->_order() >= static_cast<Operator *>(wait)->_order())
                    {
                        res.push(new Operator(static_cast<Operator *>(stack.pop())->OperatorOnly()));
                        if (stack.empty())
                            break;
                        if (stack.top()->TypeOf() == LEFTPAREN)
                            break;
                    }
                    stack.push(new Operator(static_cast<Operator *>(wait)->OperatorOnly()));
                    // cout << "\nThis is stack: "; //
                    // stack.print_pointers();      //
                }
            }
            else if (static_cast<Operator *>(stack.top())->_order() < static_cast<Operator *>(wait)->_order())
            {
                stack.push(new Operator(static_cast<Operator *>(wait)->OperatorOnly()));
            }
            else if (static_cast<Operator *>(stack.top())->_order() >= static_cast<Operator *>(wait)->_order())
            {
                while (static_cast<Operator *>(stack.top())->_order() >= static_cast<Operator *>(wait)->_order())
                {
                    res.push(new Operator(static_cast<Operator *>(stack.pop())->OperatorOnly()));
                    if (stack.empty())
                        break;
                    if (stack.top()->TypeOf() == LEFTPAREN)
                        break;
                }
                stack.push(new Operator(static_cast<Operator *>(wait)->OperatorOnly()));
                // cout << "\nThis is stack: "; //
                // stack.print_pointers();      //
            }
            break;
        }
        case LEFTPAREN:
        {
            // cout << "LEFTPAREN CASE WORKED" << endl; //
            que.pop();
            stack.push(new LeftParen());
            // cout << "\nThis is stack: "; //
            // stack.print_pointers();      //
            break;
        }
        case RIGHTPAREN:
        {
            // cout << "RIGHTPAREN CASE WORKED" << endl; //
            que.pop();
            while (stack.top()->TypeOf() != LEFTPAREN)
            {
                if (stack.top()->TypeOf() == OPERATOR)
                    res.push(new Operator(static_cast<Operator *>(stack.pop())->OperatorOnly()));
                if (stack.top()->TypeOf() == FUNCTION)
                    res.push(new Function(static_cast<Function *>(stack.pop())->FunctionOnly()));
            }
            stack.pop();
            // cout << "\nThis is stack: "; //
            // stack.print_pointers();//
            break;
        }
        }
    }
    // cout << "\n\nAll done\n\n";
    // cout << "This is que: ";
    // que.print_pointers();
    // cout << "\nThis is remaining stack: ";
    // stack.print_pointers();
    if (!stack.empty())
    {
        while (!stack.empty())
        {
            if (stack.top()->TypeOf() == OPERATOR)
                res.push(new Operator(static_cast<Operator *>(stack.pop())->OperatorOnly()));
            else if (stack.top()->TypeOf() == FUNCTION)
                res.push(new Function(static_cast<Function *>(stack.pop())->FunctionOnly()));
        }
    }
    // cout << "\nThis is res: ";
    // res.print_pointers();
    return res;
}
Queue<Token *> ShuntingYard::postfix(const Queue<Token *> &infix) // return postfix que
{
    // cout << "Shunting Yard(postfix)got called" << endl; //
    ShuntingYard sy(infix);
    return sy.postfix();
}