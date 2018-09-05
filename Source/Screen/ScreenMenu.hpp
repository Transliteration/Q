#pragma once 
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Screen.hpp"

class Settings;

class ScreenMenu : public Screen
{
private:
    
public:
    ScreenMenu(Settings &settings);
    ~ScreenMenu();
    virtual ScreenType run(sf::RenderWindow &window);
};

