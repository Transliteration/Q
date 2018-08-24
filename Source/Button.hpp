#pragma once 
#include <SFML/Graphics.hpp>
#include "Drawable.hpp"
#include "Clickable.hpp"

#define B_DEF_CHAR_SIZE 52
#define B_DEF_SPACES_FROM_BUTTON_SIDES 20
#define B_DEF_BUTTON_HEIGHT 60
#define B_DEF_RESOLUTION_WIDTH 1366
#define B_DEF_RESOLUTION_HEIGHT 768
#define B_DEF_RECT_OUTLINE_THICKNESS 4.0f

class Button : public Drawable, public Clickable
{
private:
    const sf::Font &font;
    sf::Text text;
    sf::RectangleShape rectangle;
    sf::Vector2f relativePos, realPos;
    bool isHighlighted;

    void setOriginToCenter();
    void setHighlight(bool isHighlighted);

public:
    Button(const sf::Font &font, sf::Vector2f relativePos, std::string message);
    ~Button();

    virtual void draw(sf::RenderTarget &target) const;
    virtual void onChangeResoluton(sf::Vector2u newResolution);
    virtual void onClick(sf::Vector2i);
    virtual void onHover(sf::Vector2i);
};