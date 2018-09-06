#include "Player.hpp"

Player::Player()
{
    if (!loadPlayerTexture()) throw "Error loading texture";
    sprite.setTexture(playerTexture); 
}

Player::~Player()
{
}

void Player::onChangeResoluton(sf::Vector2u newResolution)
{

}

bool Player::checkForCollision()
{
    return false;
}

void Player::castShadow()
{

}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(sprite);
}

bool Player::loadPlayerTexture()
{
    if (!playerTexture.loadFromFile("Resources/player.psd"))
    {
        std::cout << "[Player] cannot load player texture!" << std::endl;
        return false;
    } else
    {
        std::cout << "[Player] player texture load succesfully!" << std::endl;
        return true;
    }
}