#pragma once 
#include <iostream>
#include <SFML/Graphics.hpp>
#include <memory>

class inputManager
{
private:
    std::vector<sf::Keyboard::Key> pressedKeys;
public:
    inputManager();
    ~inputManager();
};

inputManager::inputManager()
{
    pressedKeys = std::vector<sf::Keyboard::Key>();
}

inputManager::~inputManager()
{
}


