#include <iostream>
#include "Clickable.hpp"

Clickable::Clickable()
{
}

Clickable::~Clickable()
{
}

void Clickable::onHover(sf::Vector2i mouse)
{
    std::cout << "Default hover." << std::endl;
}