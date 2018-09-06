#pragma once
#include <SFML/Graphics.hpp>

class Drawable : public sf::Drawable, public sf::Transformable
{
protected:
    enum class Priority {Background, Map, GUI, Canvas0, Canvas1, Canvas2};
public:
    Priority drawPriority;
    virtual void onChangeResoluton(sf::Vector2u newResolution) = 0;
    
    Drawable(Priority drawPriority = Priority::Background);
    ~Drawable();
};
