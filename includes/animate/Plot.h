#ifndef PLOT_H
#define PLOT_H
#include <iostream>
#include <vector>
#include "GraphInfo.h"
#include "Coordinates.h"
#include "tokenizer.h"
#include "../shunting_yard/shunting_yard.h"
#include "../rpn/rpn.h"
#include <SFML/Graphics.hpp>

using namespace std;

class Plot
{
public:
    Plot();
    Plot(Graph_info *graphinfo);
    void set_info();
    vector<sf::Vector2f> operator()();

private:
    Graph_info *_info;
    Queue<Token *> _postfix;
};
#endif