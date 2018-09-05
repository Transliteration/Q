#pragma once 
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Screen.hpp"

class ScreenSettings : public Screen
{
private:
    
public:
    ScreenSettings(Settings &settings);
    ~ScreenSettings();

    ScreenType run(sf::RenderWindow &window);
};
