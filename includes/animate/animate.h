#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include "sidebar.h"
#include "system.h"
#include "scales.h"
// #include "button.h"
#include <boost/algorithm/string.hpp>
using namespace std;

class animate
{
public:
    animate();
    void set_info();
    void run();
    void processEvents();
    void update();
    void render();
    void Draw();
    string domain_string(sf::RenderWindow &window)
    {
        return "(-" +
               to_string(_info->_domain.x) +
               "," +
               to_string(_info->_domain.y) +
               ")";
    }

private:
    int count, count1;
    float LDOMAIN, RDOMAIN;
    bool popUp;
    bool save, saved;

    fstream f;
    vector<string> history; // string of history

    sf::RenderWindow window;
    System system;   // container for all the animated objects
    Sidebar sidebar; // rectangular message sidebar
    string input;    // stores user input and pass to the graphinfo equation
    Graph_info *_info;

    sf::RectangleShape backGround;
    sf::RectangleShape inputBox; // input box
    sf::CircleShape mousePoint;  // The little red dot
    sf::Font font;               // font to draw on main screen
    sf::Text myTextLabel;        // text to draw on main screen
    sf::Text TextBox;            // text for input

    bool mouseIn; // mouse is in the screen

    vector<sf::RectangleShape> buttons;
};

string mouse_pos_string(sf::RenderWindow &window);
bool isMouseOver(float mouseX, float mouseY, sf::RectangleShape button);

#endif // GAME_H