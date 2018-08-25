#include <iostream>
#include "Button.hpp"

Button::Button(const sf::Font &font, sf::Vector2f relativePos, std::string message, Align align)
: Drawable(Priority::GUI)
, font(font)
, relativePos(relativePos)
, isHighlighted(false)
, align(align)
{
    text.setFont(font);
    text.setString(message);
    text.setStyle(sf::Text::Bold);
    text.setOutlineColor(sf::Color(255, 255, 255, 200));
    text.setFillColor(sf::Color::Black);
    text.setCharacterSize(B_DEF_CHAR_SIZE); // in pixels, not points! 

    rectangle.setOutlineThickness(B_DEF_RECT_OUTLINE_THICKNESS);
    rectangle.setOutlineColor(sf::Color(255, 255, 255, 96));
    rectangle.setFillColor(sf::Color(255, 255, 255, 64));
    rectangle.setSize(sf::Vector2f((float)(text.getLocalBounds().width +  B_DEF_SPACES_FROM_BUTTON_SIDES)
        , B_DEF_BUTTON_HEIGHT));
    
    switch(align)
    {
        case Align::Center: 
            setOriginToCenter();
            break;
        case Align::TopLeft:
            setOriginTopLeft();
            break;
    }

    std::cout << "Button [" << message << "] constructed!" << std::endl;
}

Button::~Button()
{
    std::cout << "Button [" << text.getString().toAnsiString() << "] destroyed!" << std::endl;
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

void Button::setOriginTopLeft()
{
    text.setOrigin(-B_DEF_SPACES_FROM_BUTTON_SIDES/2.0f
    , B_DEF_BUTTON_HEIGHT/10.0f); 
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

void Button::onHover(sf::Vector2i mouse)
{
    sf::FloatRect rect(rectangle.getGlobalBounds());

    if(rect.contains((sf::Vector2f)mouse))
    {
        setHighlight(true);
        // std::cout << "Hover over button." << std::endl;
    } else setHighlight(false);
}

void Button::onClick(sf::Vector2i mouse)
{
    if(isHighlighted)
    {
        std::cout << "Click on button [" << text.getString().toAnsiString() << "]" << std::endl;
        function();
    }
}

void Button::setHighlight(bool isHighlighted)
{
    if(isHighlighted)
    {
        this->isHighlighted = true;
        text.setOutlineThickness(1.0f);
    }
    else
    {
        this->isHighlighted = false;
        text.setOutlineThickness(0.0f);
    }
}