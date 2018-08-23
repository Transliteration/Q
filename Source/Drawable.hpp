#pragma once
#include <SFML/Graphics.hpp>

class Drawable
{
protected:
    enum class Priority {Background, GUI, Canvas0, Canvas1, Canvas2};

    Priority drawPriority;
public:

    virtual void draw(sf::RenderTarget &target) const = 0;
    virtual void onChangeResoluton(sf::Vector2u newResolution) = 0;
    
    Drawable(Priority drawPriority = Priority::Background);
    ~Drawable();
};
