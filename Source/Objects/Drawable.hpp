#pragma once
#include <SFML/Graphics.hpp>

class Drawable : public sf::Drawable
{
protected:
    enum class Priority {Background, GUI, Canvas0, Canvas1, Canvas2};

    Priority drawPriority;
public:

    virtual void onChangeResoluton(sf::Vector2u newResolution) = 0;
    
    Drawable(Priority drawPriority = Priority::Background);
    ~Drawable();
};
