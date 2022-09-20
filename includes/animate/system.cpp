#include "system.h"

System::System()
{
    _info = nullptr;
}

System::System(Graph_info *graphinfo)
{
    _info = graphinfo;
    set_info();
}

void System::set_info()
{
    graph = Graph(_info);
}

void System::Step()
{
    graph.update(_info);
}

void System::Draw(sf::RenderWindow &window)
{
    graph.draw(window);
}
