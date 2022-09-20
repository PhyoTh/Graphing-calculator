#include <cmath>
#include <iostream>
#include <iomanip>
#include <set>
#include <vector>
#include "includes/animate/animate.h"

using namespace std;

int main(int argv, char **argc)
{
    cout << "\n\n"
         << endl;
    animate game;
    game.run();
    // RPN rpn(strToinfix("sinx"));

    cout << endl
         << endl
         << "------ MAIN EXITING --------------------------" << endl;

    cout
        << "\n\n\n=====================" << endl;
    return 0;
}
