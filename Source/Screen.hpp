#pragma once 
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include "Drawable.hpp"

class Settings;

enum class ScreenType {Menu, Settings, Game, Exit, Error};

class Screen
{
protected:
    Settings &settings;
    std::vector<std::unique_ptr<Drawable>> objects; 
public:
    Screen(Settings &settings);
    virtual ~Screen();
    virtual ScreenType run(sf::RenderWindow &window) = 0;
    
};
