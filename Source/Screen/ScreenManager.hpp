#pragma once 
#include <iostream>
#include <SFML/Graphics.hpp>
#include <memory>
#include "../Settings/Settings.hpp"
#include "Screen.hpp"

#define SM_WINDOW_NAME "Q"

class ScreenManager
{
private:
    Settings &settings;
    sf::RenderWindow window;
    std::vector<std::unique_ptr<Screen>> screens;
    
public:
    ScreenManager(Settings &settings);
    ~ScreenManager();
    void start();
};
