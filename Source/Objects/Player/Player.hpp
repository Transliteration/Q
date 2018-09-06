#pragma once 
#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include "../Drawable.hpp"
#include "../Solid.hpp"

class Player : public Drawable, public Solid
{
private:
    sf::Sprite sprite;
    sf::Texture playerTexture;

    bool loadPlayerTexture();

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    virtual void onChangeResoluton(sf::Vector2u newResolution);
    virtual bool checkForCollision();
    virtual void castShadow();
public:
    Player();
    ~Player();
};


