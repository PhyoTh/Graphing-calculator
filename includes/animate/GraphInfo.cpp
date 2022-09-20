#include "GraphInfo.h"

Graph_info::Graph_info(string equation, sf::Vector2f window_dimension, sf::Vector2f orgin, sf::Vector2f domain, sf::Vector2f scale, int point, bool polar)
{
    _equation = equation;
    _window_dimension = window_dimension;
    _origin = orgin;
    _domain = domain;
    _scale = scale;
    _point = point;
    _polar = polar;
}