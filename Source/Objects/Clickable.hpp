#pragma once 
#include <SFML/Graphics.hpp>
#include <functional>

class Clickable
{
protected:
    std::function<void ()> function;
public:
    Clickable();
    ~Clickable();

    virtual void onClick(sf::Vector2i) = 0;
    virtual void onHover(sf::Vector2i);
    void setFunction(std::function<void ()> function);
};

