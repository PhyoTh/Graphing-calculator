#ifndef GRAPHINFO_H
#define GRAPHINFO_H
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

using namespace std;

struct Graph_info
{
public:
    Graph_info(string equation, sf::Vector2f window_dimension, sf::Vector2f orgin, sf::Vector2f domain, sf::Vector2f scale, int point, bool polar);
    string _equation;
    sf::Vector2f _window_dimension;
    sf::Vector2f _origin;
    sf::Vector2f _domain;
    sf::Vector2f _scale;
    int _point;
    bool _polar;
};
#endif