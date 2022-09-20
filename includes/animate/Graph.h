#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include "Plot.h"
#include "scales.h"
#include <SFML/Graphics.hpp>

using namespace std;
class Graph
{
public:
    Graph();
    Graph(Graph_info *graphinfo);
    void set_info();
    void update(Graph_info *graphinfo);
    void draw(sf::RenderWindow &window);

private:
    Graph_info *_info;
    Plot _plotter;
    vector<sf::Vector2f> _points;
    // sf::Font stuff;
};
#endif