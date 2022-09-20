#ifndef SYSTEM_H
#define SYSTEM_H

#include <SFML/Graphics.hpp>
#include "Graph.h"
#include "scales.h"

using namespace std;
class System
{
public:
    System();
    System(Graph_info *graphinfo);
    void set_info();
    void Step();
    void Draw(sf::RenderWindow &window);

private:
    Graph_info *_info;
    Graph graph;
};
#endif // SYSTEM_H
