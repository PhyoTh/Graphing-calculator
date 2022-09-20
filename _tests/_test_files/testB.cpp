#include "gtest/gtest.h"
#include <iostream>
#include <iomanip>
#include "../../includes/token/token.h"
#include "../../includes/token/operator.h"
#include "../../includes/token/integer.h"
#include "../../includes/token/function.h"
#include "../../includes/token/leftparen.h"
#include "../../includes/token/rightparen.h"
#include "../../includes/queue/MyQueue.h"
#include "../../includes/shunting_yard/shunting_yard.h"
#include "../../includes/rpn/rpn.h"
using namespace std;

bool test_stub(bool debug = false)
{
  if (debug)
  {
    cout << "testB:: test-sub() entering test_sub" << endl;
  }
  return true;
}

bool test_rpn(bool debug = false)
{
  if (debug)
  {
    cout << "testB:: test-rpn() entering test_rpn" << endl;
  }

  if (debug)
  {
    cout << "---------- Testing +- ----------\n";
    Queue<Token *> postfix;
    postfix.push(new Integer(3));
    postfix.push(new Integer(5));
    postfix.push(new Operator("+"));
    postfix.push(new Integer(4));
    postfix.push(new Operator("-"));
    postfix.print_pointers();
    RPN rpn(postfix);
    cout << "3 5 + 4 -: " << rpn() << endl;

    Queue<Token *> postfix2;
    postfix2.push(new Integer(3));
    postfix2.push(new Function("x"));
    postfix2.push(new Operator("+"));
    postfix2.push(new Integer(4));
    postfix2.push(new Operator("-"));
    postfix2.print_pointers();
    rpn.set_input(postfix2);
    cout << "3 x + 4 -: (x = 5): " << rpn(5) << endl
         << endl;
  }

  if (debug)
  {
    cout << "---------- Testing */ ----------\n";
    Queue<Token *> postfix;
    postfix.push(new Integer(3));
    postfix.push(new Integer(5));
    postfix.push(new Operator("*"));
    postfix.push(new Integer(5));
    postfix.push(new Operator("/"));
    postfix.print_pointers();
    RPN rpn(postfix);
    cout << "3 5 * 5 /: " << rpn() << endl;

    Queue<Token *> postfix2;
    postfix2.push(new Integer(3));
    postfix2.push(new Function("x"));
    postfix2.push(new Operator("*"));
    postfix2.push(new Integer(5));
    postfix2.push(new Operator("/"));
    postfix2.print_pointers();
    rpn.set_input(postfix2);
    cout << "3 x * 5 /: (x = 5): " << rpn(5) << endl
         << endl;
  }

  if (debug)
  {
    cout << "---------- Testing ^ ----------\n";
    Queue<Token *> postfix;
    postfix.push(new Integer(2));
    postfix.push(new Integer(3));
    postfix.push(new Operator("^"));
    postfix.print_pointers();
    RPN rpn(postfix);
    cout << "2 3 ^: " << rpn() << endl;

    Queue<Token *> postfix2;
    postfix2.push(new Integer(2));
    postfix2.push(new Function("x"));
    postfix2.push(new Operator("^"));
    postfix2.print_pointers();
    rpn.set_input(postfix2);
    cout << "2 x ^: (x = 3): " << rpn(3) << endl
         << endl;
  }

  return true;
}

bool test_shunting_yard(bool debug = false)
{
  if (debug)
  {
    cout << "testB:: test-shunting-yard() entering test_shunting_yard" << endl;
  }

  if (debug)
  {
    cout << "---------- Testing +* ----------\n";
    Queue<Token *> infix;
    infix.push(new Integer(3));
    infix.push(new Operator("+"));
    infix.push(new Integer(5));
    infix.push(new Operator("*"));
    infix.push(new Integer(4));
    infix.print_pointers();
    ShuntingYard sy(infix);
    Queue<Token *> postfix = sy.postfix();
    postfix.print_pointers();
    RPN rpn(postfix);
    cout << "3 + 5 * 4 = : " << rpn() << endl;

    Queue<Token *> infix2;
    infix2.push(new Integer(3));
    infix2.push(new Operator("+"));
    infix2.push(new Function("X"));
    infix2.push(new Operator("*"));
    infix2.push(new Integer(4));
    infix2.print_pointers();
    sy.infix(infix2);
    postfix = sy.postfix();
    postfix.print_pointers();
    rpn.set_input(postfix);
    cout << "3 + X * 4 = : (x = 5): " << rpn(5) << endl
         << endl;
  }

  if (debug)
  {
    cout << "---------- Testing *+ ----------\n";
    Queue<Token *> infix;
    infix.push(new Integer(3));
    infix.push(new Operator("*"));
    infix.push(new Integer(5));
    infix.push(new Operator("+"));
    infix.push(new Integer(4));
    infix.print_pointers();
    ShuntingYard sy(infix);
    Queue<Token *> postfix = sy.postfix();
    postfix.print_pointers();
    RPN rpn(postfix);
    cout << "3 * 5 + 4 = : " << rpn() << endl;

    Queue<Token *> infix2;
    infix2.push(new Integer(3));
    infix2.push(new Operator("*"));
    infix2.push(new Function("X"));
    infix2.push(new Operator("+"));
    infix2.push(new Integer(4));
    infix2.print_pointers();
    sy.infix(infix2);
    postfix = sy.postfix();
    postfix.print_pointers();
    rpn.set_input(postfix);
    cout << "3 * x + 4 = : (x = 5): " << rpn(5) << endl
         << endl;
  }

  if (debug)
  {
    cout << "---------- Testing +*^ ----------\n";
    Queue<Token *> infix;
    infix.push(new Integer(3));
    infix.push(new Operator("+"));
    infix.push(new Integer(5));
    infix.push(new Operator("*"));
    infix.push(new Integer(4));
    infix.push(new Operator("^"));
    infix.push(new Integer(2));
    infix.print_pointers();
    ShuntingYard sy(infix);
    Queue<Token *> postfix = sy.postfix();
    postfix.print_pointers();
    RPN rpn(postfix);
    cout << "3 + 5 * 4 ^ 2 = : " << rpn() << endl;

    Queue<Token *> infix2;
    infix2.push(new Integer(3));
    infix2.push(new Operator("+"));
    infix2.push(new Function("X"));
    infix2.push(new Operator("*"));
    infix2.push(new Integer(4));
    infix2.push(new Operator("^"));
    infix2.push(new Integer(2));
    infix2.print_pointers();
    sy.infix(infix2);
    postfix = sy.postfix();
    postfix.print_pointers();
    rpn.set_input(postfix);
    cout << "3 + x * 4 ^ 2 = : (x = 5): " << rpn(5) << endl
         << endl;
  }

  if (debug)
  {
    cout << "---------- Testing +*^() ----------\n";
    Queue<Token *> infix;
    infix.push(new LeftParen());
    infix.push(new Integer(3));
    infix.push(new Operator("+"));
    infix.push(new Integer(5));
    infix.push(new RightParen());
    infix.push(new Operator("*"));
    infix.push(new LeftParen());
    infix.push(new Integer(4));
    infix.push(new Operator("^"));
    infix.push(new Integer(2));
    infix.push(new RightParen());
    infix.print_pointers();
    ShuntingYard sy(infix);
    Queue<Token *> postfix = sy.postfix();
    postfix.print_pointers();
    RPN rpn(postfix);
    cout << "(3 + 5) * (4 ^ 2) = : " << rpn() << endl;

    Queue<Token *> infix2;
    infix2.push(new LeftParen());
    infix2.push(new Integer(3));
    infix2.push(new Operator("+"));
    infix2.push(new Function("X"));
    infix2.push(new RightParen());
    infix2.push(new Operator("*"));
    infix2.push(new LeftParen());
    infix2.push(new Integer(4));
    infix2.push(new Operator("^"));
    infix2.push(new Integer(2));
    infix2.push(new RightParen());
    infix2.print_pointers();
    sy.infix(infix2);
    postfix = sy.postfix();
    postfix.print_pointers();
    rpn.set_input(postfix);
    cout << "(3 + x) * (4 ^ 2) = : (x = 5): " << rpn(5) << endl
         << endl;
  }

  if (debug)
  {
    cout << "---------- Testing +-*/^ v1 ----------\n";
    Queue<Token *> infix;
    infix.push(new Integer(3));
    infix.push(new Operator("*"));
    infix.push(new Integer(5));
    infix.push(new Operator("+"));
    infix.push(new Integer(2));
    infix.push(new Operator("-"));
    infix.push(new Integer(6));
    infix.push(new Operator("/"));
    infix.push(new Integer(7));
    infix.push(new Operator("^"));
    infix.push(new Integer(9));
    infix.print_pointers();
    ShuntingYard sy(infix);
    Queue<Token *> postfix = sy.postfix();
    postfix.print_pointers();
    RPN rpn(postfix);
    cout << "3 * 5 + 2 - 6 / 7 ^ 9 = : " << rpn() << endl
         << endl;
  }

  if (debug)
  {
    cout << "---------- Testing +-*/^ v2 ----------\n";
    Queue<Token *> infix;
    infix.push(new Integer(3));
    infix.push(new Operator("*"));
    infix.push(new Integer(5));
    infix.push(new Operator("+"));
    infix.push(new Integer(2));
    infix.push(new Operator("-"));
    infix.push(new Integer(6));
    infix.push(new Operator("/"));
    infix.push(new Integer(7));
    infix.push(new Operator("^"));
    infix.push(new Integer(9));
    infix.push(new Operator("-"));
    infix.push(new Integer(12));
    infix.print_pointers();
    ShuntingYard sy(infix);
    Queue<Token *> postfix = sy.postfix();
    postfix.print_pointers();
    RPN rpn(postfix);
    cout << "3 * 5 + 2 - 6 / 7 ^ 9 - 12 = : " << rpn() << endl
         << endl;
  }

  return true;
}

bool test_project(bool debug = false)
{
  if (debug)
  {
    cout << "testB:: test-project() entering test_project" << endl;
  }

  if (debug)
  {
    cout << "---------- Test 1: ----------\n";
    Queue<Token *> infix;
    infix.push(new Integer(4));
    infix.push(new Operator("+"));
    infix.push(new Function("cos"));
    infix.push(new LeftParen());
    infix.push(new Function("x"));
    infix.push(new RightParen());
    infix.push(new Operator("*"));
    infix.push(new Integer(3));
    infix.print_pointers();
    ShuntingYard sy(infix);
    Queue<Token *> postfix = sy.postfix();
    postfix.print_pointers();
    RPN rpn(postfix);
    cout << "4 + cos (x) * 3: " << rpn() << endl
         << endl;
  }

  if (debug)
  {
    cout << "---------- Test 2: ----------\n";
    Queue<Token *> infix;
    infix.push(new Integer(5));
    infix.push(new Operator("*"));
    infix.push(new Function("x"));
    infix.push(new Operator("+"));
    infix.push(new Integer(2));
    infix.print_pointers();
    ShuntingYard sy(infix);
    Queue<Token *> postfix = sy.postfix();
    postfix.print_pointers();
    RPN rpn(postfix);
    cout << "5 * x + 2 = : " << rpn() << endl
         << endl;
  }

  if (debug)
  {
    cout << "---------- Test 3: ----------\n";
    Queue<Token *> infix;
    infix.push(new Integer(5));
    infix.push(new Operator("+"));
    infix.push(new Function("x"));
    infix.push(new Operator("*"));
    infix.push(new Integer(2));
    infix.print_pointers();
    ShuntingYard sy(infix);
    Queue<Token *> postfix = sy.postfix();
    postfix.print_pointers();
    RPN rpn(postfix);
    cout << "5 + x * 2 = : " << rpn() << endl
         << endl;
  }

  return true;
}

TEST(TEST_STUB, TestStub)
{
  EXPECT_EQ(1, test_stub(false));
}

TEST(TEST_RPN, TestRpn)
{
  EXPECT_EQ(1, test_rpn(true));
}

TEST(TEST_SHUNTING_YARD, TestShuntingYard)
{
  EXPECT_EQ(1, test_shunting_yard(true));
}

TEST(TEST_PROJECT, TestProject)
{
  EXPECT_EQ(1, test_project(true));
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  std::cout << "\n\n----------running testB.cpp---------\n\n"
            << std::endl;
  return RUN_ALL_TESTS();
}