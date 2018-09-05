#include <iostream>
#include "Clickable.hpp"

Clickable::Clickable()
{
}

Clickable::~Clickable()
{
}

void Clickable::setFunction(std::function<void ()> func)
{
    function = func;
}

void Clickable::onHover(sf::Vector2i mouse)
{
    std::cout << "Default hover." << std::endl;
}