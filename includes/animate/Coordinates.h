#ifndef COORDINATES_H
#define COORDINATES_H

#include <iostream>
#include "GraphInfo.h"
#include <SFML/Graphics.hpp>

using namespace std;

class Coordinate
{
public:
    Coordinate();
    Coordinate(Graph_info *graphinfo);

    // sf::Vector2f operator()(sf::Vector2f point);
    sf::Vector2f translate(sf::Vector2f point);

private:
    Graph_info *_info;
};
#endif