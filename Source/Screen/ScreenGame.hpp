#pragma once 
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Screen.hpp"
#include "../Objects/Map/GameMap.hpp"
#include "../Objects/Player/Player.hpp"

class ScreenGame : public Screen
{
private:
    std::shared_ptr<Player> player;
public:
    ScreenGame(Settings &settings);
    ~ScreenGame();

    ScreenType run(sf::RenderWindow &window);
};
