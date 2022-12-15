#include "animate.h"
float ORIGIN_X = (SCREEN_WIDTH - SIDE_BAR) / 2;
float ORIGIN_Y = SCREEN_HEIGHT / 2;

animate::animate() : sidebar(WORK_PANEL, SIDE_BAR)
{
    cout << "animate CTOR: TOP" << endl;
    window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "FINAL PROJECT!!!");
    // VideoMode class has functions to detect screen size etc.
    // RenderWindow constructor has a third argumnet to set style
    // of the window: resize, fullscreen etc.

    // System will be implemented to manage a vector of objects to be animated.
    //   at that point, the constructor of the System class will take a vector
    //   of objects created by the animate object.
    //   animate will
    // system = System();
    window.setFramerateLimit(60);

    mouseIn = true;

    mousePoint = sf::CircleShape();
    mousePoint.setRadius(5.0);
    mousePoint.setFillColor(sf::Color::Red);

    popUp = false;
    save = false;
    saved = false;
    count = 0;
    count1 = 0;
    LDOMAIN = -5;
    RDOMAIN = 5;

    // for (int i = 0; i < 9; i++)
    // {
    //     sf::RectangleShape button(sf::Vector2f(SIDE_BAR, 40));
    //     button.setPosition(WORK_PANEL, 235 + (i * 47));
    //     button.setFillColor(sf::Color::Transparent);
    //     button.setOutlineColor(sf::Color::Black);
    //     button.setOutlineThickness(1);
    //     buttons.push_back(button);
    // }

    inputBox = sf::RectangleShape(sf::Vector2f(200, 50));
    inputBox.setOutlineColor(sf::Color::Black);
    inputBox.setOutlineThickness(2);
    inputBox.setFillColor(sf::Color::White);
    inputBox.setPosition(10, 10);

    backGround = sf::RectangleShape(sf::Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT));
    backGround.setFillColor(sf::Color(192, 192, 192));
    backGround.setPosition(0, 0);

    sidebar[SB_EQUATION] = "f(x) = ";
    sidebar[SB_DOMAINTEXT] = "DOMAIN:";
    sidebar[SB_HISTORYTEXT] = "_HISTORY_(Press S to save)";
    sidebar[SB_HISTORY1] = "(1) ";
    sidebar[SB_HISTORY2] = "(2) ";
    sidebar[SB_HISTORY3] = "(3) ";
    sidebar[SB_HISTORY4] = "(4) ";
    sidebar[SB_HISTORY5] = "(5) ";
    sidebar[SB_HISTORY6] = "(6) ";
    sidebar[SB_HISTORY7] = "(7) ";
    sidebar[SB_HISTORY8] = "(8) ";
    sidebar[SB_HISTORY9] = "(9) ";

    cout
        << "Geme CTOR. preparing to load the font." << endl;
    //--- FONT ----------
    // font file must be in the "working directory:
    //      debug folder
    // Make sure working directory is where it should be and not
    //  inside the app file:
    //  Project->RUN->Working Folder
    //
    // font must be a member of the class.
    //  Will not work with a local declaration
    if (!font.loadFromFile("../arial.ttf"))
    {
        cout << "animate() CTOR: Font failed to load" << endl;
        cin.get();
        exit(-1);
    }
    f.open("../../includes/animate/history.txt", ios::in);
    if (f.is_open())
    {
        string line;
        while (getline(f, line))
        {
            history.push_back(line);
            count++;
            count1 = count;
        }
    }
    f.close();
    for (int i = 0; i < count; i++)
    {
        if (i == 0)
            sidebar[SB_HISTORY1] += history[i];
        if (i == 1)
            sidebar[SB_HISTORY2] += history[i];
        if (i == 2)
            sidebar[SB_HISTORY3] += history[i];
        if (i == 3)
            sidebar[SB_HISTORY4] += history[i];
        if (i == 4)
            sidebar[SB_HISTORY5] += history[i];
        if (i == 5)
            sidebar[SB_HISTORY6] += history[i];
        if (i == 6)
            sidebar[SB_HISTORY7] += history[i];
        if (i == 7)
            sidebar[SB_HISTORY8] += history[i];
        if (i == 8)
            sidebar[SB_HISTORY9] += history[i];
        sf::RectangleShape button(sf::Vector2f(SIDE_BAR, 40));
        button.setPosition(WORK_PANEL, 235 + (i * 47));
        button.setFillColor(sf::Color::Transparent);
        button.setOutlineColor(sf::Color::Black);
        button.setOutlineThickness(0);
        buttons.push_back(button);
    }
    f.open("../../includes/animate/history.txt", ios::app);

    myTextLabel = sf::Text("Graphing Calculator", font);
    myTextLabel.setCharacterSize(20);
    myTextLabel.setStyle(sf::Text::Bold);
    myTextLabel.setFillColor(sf::Color::Black);
    myTextLabel.setPosition(sf::Vector2f(10, SCREEN_HEIGHT - myTextLabel.getLocalBounds().height - 5));

    TextBox.setFont(font);
    TextBox.setCharacterSize(20);
    TextBox.setStyle(sf::Text::Bold | sf::Text::Underlined);
    TextBox.setFillColor(sf::Color::Black);
    TextBox.setPosition(sf::Vector2f(10, 10));
    TextBox.setString("");

    _info = new Graph_info("0", sf::Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT), sf::Vector2f(ORIGIN_X, ORIGIN_Y), sf::Vector2f(LDOMAIN, RDOMAIN), sf::Vector2f(WORK_PANEL / (RDOMAIN - LDOMAIN), WORK_PANEL / (RDOMAIN - LDOMAIN)), 4000, false);
    system = System(_info);
    cout << "animate instantiated successfully." << endl;
}

void animate::Draw()
{
    // Look at the data and based on the data, draw shapes on window object.
    window.draw(backGround);
    system.Draw(window);
    if (mouseIn)
    {
        window.draw(mousePoint);
    }
    if (popUp)
    {
        window.draw(inputBox);
    }
    sidebar.draw(window);
    for (int i = 0; i < count1; i++)
    {
        window.draw(buttons[i]);
    }
    //- - - - - - - - - - - - - - - - - - -
    // getPosition() gives you screen coords, getPosition(window) gives you window coords
    // cout<<"mosue pos: "<<sf::Mouse::getPosition(window).x<<", "<<sf::Mouse::getPosition(window).y<<endl;
    //- - - - - - - - - - - - - - - - - - -

    // drawing Test: . . . . . . . . . . . .
    // This is how you draw text:)
    window.draw(myTextLabel);
    window.draw(TextBox);
    //. . . . . . . . . . . . . . . . . . .
}

void animate::update()
{
    // cause changes to the data for the next frame
    system.Step();
    if (mouseIn)
    {
        // mousePoint red dot:
        mousePoint.setPosition(sf::Mouse::getPosition(window).x - 5,
                               sf::Mouse::getPosition(window).y - 5);

        // mouse location text for sidebar:
        sidebar[SB_MOUSE_POSITION] = mouse_pos_string(window);
    }
    if (saved)
    {
        for (int i = count; i < count1; i++)
        {
            if (i == 0)
                sidebar[SB_HISTORY1] += history.back();
            if (i == 1)
                sidebar[SB_HISTORY2] += history.back();
            if (i == 2)
                sidebar[SB_HISTORY3] += history.back();
            if (i == 3)
                sidebar[SB_HISTORY4] += history.back();
            if (i == 4)
                sidebar[SB_HISTORY5] += history.back();
            if (i == 5)
                sidebar[SB_HISTORY6] += history.back();
            if (i == 6)
                sidebar[SB_HISTORY7] += history.back();
            if (i == 7)
                sidebar[SB_HISTORY8] += history.back();
            if (i == 8)
                sidebar[SB_HISTORY9] += history.back();
            sf::RectangleShape button(sf::Vector2f(SIDE_BAR, 40));
            button.setPosition(WORK_PANEL, 235 + (i * 47));
            button.setFillColor(sf::Color::Transparent);
            button.setOutlineColor(sf::Color::White);
            button.setOutlineThickness(0);
            buttons.push_back(button);
        }
        count = count1;
        saved = false;
    }
    for (int i = 0; i < count; i++)
    {
        if (buttons[i].getOutlineColor() == sf::Color::White)
        {
            buttons[i].setOutlineThickness(1);
        }
    }
    sidebar[SB_DOMAIN] = domain_string(window);
    TextBox.setString(input);
}
void animate::render()
{
    window.clear();
    Draw();
    window.display();
}

void animate::processEvents()
{
    sf::Event event;
    float mouseX, mouseY;
    while (window.pollEvent(event)) // or waitEvent
    {
        // check the type of the event...
        switch (event.type)
        {
        // window closed
        case sf::Event::Closed:
            window.close();
            break;

        // key pressed
        case sf::Event::KeyPressed:
        {
            switch (event.key.code)
            {
            case sf::Keyboard::Left:
            {
                sidebar[SB_KEY_PRESSED] = "LEFT ARROW";
                _info->_origin = sf::Vector2f(_info->_origin.x + 10, _info->_origin.y);
                LDOMAIN -= ((_info->_domain.y - _info->_domain.x) / WORK_PANEL) * 10;
                RDOMAIN -= ((_info->_domain.y - _info->_domain.x) / WORK_PANEL) * 10;
                _info->_domain.x = LDOMAIN;
                _info->_domain.y = RDOMAIN;
                break;
            }
            case sf::Keyboard::Right:
            {
                sidebar[SB_KEY_PRESSED] = "RIGHT ARROW";
                _info->_origin = sf::Vector2f(_info->_origin.x - 10, _info->_origin.y);
                LDOMAIN += ((_info->_domain.y - _info->_domain.x) / WORK_PANEL) * 10;
                RDOMAIN += ((_info->_domain.y - _info->_domain.x) / WORK_PANEL) * 10;
                _info->_domain.x = LDOMAIN;
                _info->_domain.y = RDOMAIN;
                break;
            }
            case sf::Keyboard::Up:
            {
                sidebar[SB_KEY_PRESSED] = "UP ARROW";
                _info->_origin = sf::Vector2f(_info->_origin.x, _info->_origin.y + 10);
                break;
            }
            case sf::Keyboard::Down:
            {
                sidebar[SB_KEY_PRESSED] = "DOWN ARROW";
                _info->_origin = sf::Vector2f(_info->_origin.x, _info->_origin.y - 10);
                break;
            }
            case sf::Keyboard::R:
            {
                sidebar[SB_KEY_PRESSED] = "RESET";
                _info->_origin = sf::Vector2f(ORIGIN_X, ORIGIN_Y);
                LDOMAIN = -5;
                RDOMAIN = 5;
                _info->_scale = sf::Vector2f(WORK_PANEL / (RDOMAIN - LDOMAIN), WORK_PANEL / (RDOMAIN - LDOMAIN));
                _info->_domain = sf::Vector2f(LDOMAIN, RDOMAIN);
                break;
            }
            case sf::Keyboard::Enter:
            {
                popUp = true;
                if (popUp && input.size() > 0)
                {
                    // boost::trim_right(input);
                    // boost::trim_left(input);
                    history.push_back(input);
                    save = true;
                    sidebar[SB_EQUATION] = "f(x) = " + input;
                    _info->_equation = input;
                    for (int i = 0; i < count; i++)
                    {
                        buttons[i].setOutlineColor(sf::Color::Black);
                        buttons[i].setOutlineThickness(0);
                    }
                    popUp = false;
                    input.erase();
                }
                break;
            }
            case sf::Keyboard::S:
            {
                if (save && history.size() > 0 && !popUp)
                {
                    count1 += 1;
                    f << history.back() << endl;
                    save = false;
                    for (int i = 0; i < count; i++)
                    {
                        buttons[i].setOutlineColor(sf::Color::Black);
                        buttons[i].setOutlineThickness(0);
                    }
                }
                saved = true;
                break;
            }
            case sf::Keyboard::Escape:
            {
                popUp = false;
                input.erase();
                break;
            }
            case sf::Keyboard::BackSpace:
            {
                if (input.size() > 0)
                    input.erase(prev(input.end()));
                break;
            }
            }
            break;
        }
        case sf::Event::MouseEntered:
            mouseIn = true;
            break;

        case sf::Event::MouseLeft:
            mouseIn = false;
            break;

        case sf::Event::MouseMoved:
        {
            mouseX = event.mouseMove.x;
            mouseY = event.mouseMove.y;
            for (int i = 0; i < count; i++)
            {
                if (isMouseOver(mouseX, mouseY, buttons[i]))
                {
                    buttons[i].setOutlineThickness(1);
                }
                else if (!isMouseOver(mouseX, mouseY, buttons[i]))
                {
                    if (buttons[i].getOutlineColor() == sf::Color::White)
                        buttons[i].setOutlineThickness(1);
                    buttons[i].setOutlineThickness(0);
                }
            }
            break;
        }

        case sf::Event::MouseButtonPressed:
        {
            if (event.mouseButton.button == sf::Mouse::Left)
            {
                for (int i = 0; i < count; i++)
                {
                    if (isMouseOver(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y, buttons[i]))
                    {
                        for (int j = 0; j < count; j++)
                        {
                            buttons[j].setOutlineColor(sf::Color::Black);
                            buttons[j].setOutlineThickness(0);
                        }
                        buttons[i].setOutlineColor(sf::Color::White);
                        buttons[i].setOutlineThickness(1);
                        _info->_equation = history[i];
                    }
                    else
                    {
                        if (buttons[i].getOutlineColor() == sf::Color::White)
                            buttons[i].setOutlineThickness(1);
                        else
                        {
                            buttons[i].setOutlineColor(sf::Color::Black);
                            buttons[i].setOutlineThickness(0);
                        }
                    }
                }
            }
            break;
        }

        case sf::Event::MouseButtonReleased:
        {
            if (event.mouseButton.button == sf::Mouse::Right)
            {
                sidebar[SB_MOUSE_CLICKED] = "RIGHT CLICK " +
                                            mouse_pos_string(window);
            }
            else
            {
                sidebar[SB_MOUSE_CLICKED] = "LEFT CLICK " +
                                            mouse_pos_string(window);
            }
            break;
        }
        case sf::Event::MouseWheelScrolled:
        {
            // cout << "delta: " << event.mouseWheel.x << endl;
            if (event.mouseWheel.x < 0)
            {
                sidebar[SB_MOUSE_CLICKED] = "ZOOM OUT ";
                LDOMAIN /= 0.5;
                RDOMAIN /= 0.5;
                _info->_domain.x = LDOMAIN;
                _info->_domain.y = RDOMAIN;
                _info->_scale.x = WORK_PANEL / (_info->_domain.y - _info->_domain.x);
                _info->_scale.y = WORK_PANEL / (_info->_domain.y - _info->_domain.x);
            }
            if (event.mouseWheel.x > 0)
            {
                sidebar[SB_MOUSE_CLICKED] = "ZOOM IN ";
                LDOMAIN *= 0.5;
                RDOMAIN *= 0.5;
                _info->_domain.x = LDOMAIN;
                _info->_domain.y = RDOMAIN;
                _info->_scale.x = WORK_PANEL / (_info->_domain.y - _info->_domain.x);
                _info->_scale.y = WORK_PANEL / (_info->_domain.y - _info->_domain.x);
            }
        }
        case sf::Event::TextEntered:
        {
            if (popUp)
            {
                if (event.text.unicode < 128 && event.text.unicode != 8)
                {
                    if (input.size() < 17)
                        input += static_cast<char>(event.text.unicode);
                }
            }
        }
        default:
            break;
        }
    }
}
void animate::run()
{
    while (window.isOpen())
    {
        processEvents();
        update();
        render(); // clear/draw/display
    }
    f.close();
    cout << endl
         << "-------ANIMATE MAIN LOOP EXITING ------------" << endl;
}

string mouse_pos_string(sf::RenderWindow &window)
{
    return "(" +
           to_string(sf::Mouse::getPosition(window).x) +
           ", " +
           to_string(sf::Mouse::getPosition(window).y) +
           ")";
}

bool isMouseOver(float mouseX, float mouseY, sf::RectangleShape button)
{
    float btnPosX = button.getPosition().x;
    float btnPosY = button.getPosition().y;

    float btnxPosWidth = btnPosX + button.getLocalBounds().width;
    float btnyPosHeight = btnPosY + button.getLocalBounds().height;

    if (mouseX > btnPosX && mouseX < btnxPosWidth && mouseY < btnyPosHeight && mouseY > btnPosY)
    {
        return true;
    }
    return false;
}