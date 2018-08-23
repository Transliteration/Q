#include "Button.hpp"

Button::Button(const sf::Font &font, sf::Vector2f relativePos, std::string message)
: Drawable(Priority::GUI)
, font(font)
, relativePos(relativePos)
{
    text.setFont(font);
    text.setString(message);
    text.setStyle(sf::Text::Bold);
    text.setOutlineColor(sf::Color(255, 255, 255, 200));
    text.setFillColor(sf::Color(255, 255, 255, 192));
    text.setCharacterSize(B_DEF_CHAR_SIZE); // in pixels, not points! 

    rectangle.setOutlineThickness(B_DEF_RECT_OUTLINE_THICKNESS);
    rectangle.setOutlineColor(sf::Color(255, 255, 255, 96));
    rectangle.setFillColor(sf::Color(255, 255, 255, 64));
    rectangle.setSize(sf::Vector2f((float)(text.getLocalBounds().width +  B_DEF_SPACES_FROM_BUTTON_SIDES)
                , B_DEF_BUTTON_HEIGHT));
    
    setOriginToCenter();
}

void Button::setOriginToCenter()
{
    sf::FloatRect newOrigin = rectangle.getLocalBounds();
    rectangle.setOrigin(newOrigin.left + newOrigin.width/2.0f,
            newOrigin.top  + newOrigin.height/2.0f);

    newOrigin = text.getLocalBounds();
    text.setOrigin(newOrigin.left + newOrigin.width/2.0f,
            newOrigin.top  + newOrigin.height/2.0f); 
}

Button::~Button()
{
}

void Button::draw(sf::RenderTarget &target) const
{
    target.draw(rectangle);
    target.draw(text);
}

void Button::onChangeResoluton(sf::Vector2u newResolution)
{
    realPos = {newResolution.x * relativePos.x, newResolution.y * relativePos.y};
    rectangle.setPosition(realPos);
    text.setPosition(realPos);
}