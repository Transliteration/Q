#pragma once 
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include <algorithm>
#include <iostream>
#include "../Objects/Drawable.hpp"
#include "../Objects/Clickable.hpp"

class Settings;

enum class ScreenType {Menu, Settings, Game, Exit, Error};

class Screen
{
protected:
    Settings &settings;
    std::vector<std::shared_ptr<Drawable>> objects; 
    std::vector<std::shared_ptr<Clickable>> clickable;
    ScreenType nextScreen;
public:
    Screen(Settings &settings);
    virtual ~Screen();
    virtual ScreenType run(sf::RenderWindow &window) = 0;
    void sortDrawables();
};
