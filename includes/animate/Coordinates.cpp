#include "Coordinates.h"

Coordinate::Coordinate()
{
    _info = nullptr;
}

Coordinate::Coordinate(Graph_info *graphinfo)
{
    _info = graphinfo;
}

// sf::Vector2f Coordinate::operator()(sf::Vector2f point)
// {
//     return sf::Vector2f(((point.x * _info->_scale.x) + _info->_origin.x), (_info->_origin.y - (point.y * _info->_scale.y)));
// }

sf::Vector2f Coordinate::translate(sf::Vector2f point)
{
    return sf::Vector2f(((point.x * _info->_scale.x) + _info->_origin.x), (_info->_origin.y - (point.y * _info->_scale.y)));
}