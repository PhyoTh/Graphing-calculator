#include "Plot.h"

Plot::Plot()
{
    _info = nullptr;
}

Plot::Plot(Graph_info *graphinfo)
{
    _info = graphinfo;
    set_info();
}

void Plot::set_info()
{
    Queue<Token *> infix = strToinfix(_info->_equation);
    ShuntingYard sy(infix);
    _postfix = sy.postfix();
}

vector<sf::Vector2f> Plot::operator()()
{
    // if (_info->_polar == true)
    // {
    // }
    // else
    // {
    vector<sf::Vector2f> res;
    Coordinate c(_info);
    double space = (_info->_domain.y - _info->_domain.x) / _info->_point;
    for (double i = _info->_domain.x; i <= _info->_domain.y; i += space)
    {
        RPN rpn(_postfix);
        sf::Vector2f v(i, rpn(i));
        res.push_back(c.translate(v));
    }
    return res;
    // }
}