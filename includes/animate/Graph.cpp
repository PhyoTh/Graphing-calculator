#include "Graph.h"

Graph::Graph()
{
    _info = nullptr;
}

Graph::Graph(Graph_info *graphinfo)
{
    _info = graphinfo;
    set_info();
}

void Graph::set_info()
{
    _plotter = Plot(_info);
    _points = _plotter();
}

void Graph::update(Graph_info *graphinfo)
{
    _info = graphinfo;
    set_info();
}

void Graph::draw(sf::RenderWindow &window)
{
    sf::RectangleShape x(sf::Vector2f(SCREEN_WIDTH, 1));
    sf::RectangleShape y(sf::Vector2f(1, SCREEN_HEIGHT));
    x.setFillColor(sf::Color::Black);
    y.setFillColor(sf::Color::Black);
    x.setPosition(sf::Vector2f(0, _info->_origin.y));
    y.setPosition(sf::Vector2f(_info->_origin.x, 0));
    window.draw(x);
    window.draw(y);
    for (int i = 0; i < _points.size(); i++)
    {
        sf::CircleShape c(2);
        c.setPosition(_points[i]);
        c.setFillColor(sf::Color::White);
        window.draw(c);
    }
}