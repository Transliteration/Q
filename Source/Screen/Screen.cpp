#include "Screen.hpp"
#include "../Objects/Drawable.hpp"

Screen::Screen(Settings &settings)
: settings(settings)
{
}

Screen::~Screen()
{
}

void Screen::sortDrawables()
{
    std::sort(objects.begin(), objects.end()
    , [](const std::shared_ptr<Drawable>& a, const std::shared_ptr<Drawable>& b) -> bool 
    {
        return  (a->drawPriority > b->drawPriority);
    });
}