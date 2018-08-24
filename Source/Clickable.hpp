#pragma once 
#include <SFML/Graphics.hpp>

class Clickable
{
public:
    Clickable();
    ~Clickable();

    virtual void onClick(sf::Vector2i) = 0;
    virtual void onHover(sf::Vector2i);
};

