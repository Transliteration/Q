#include "ScreenMenu.hpp"
#include "Settings.hpp"

ScreenMenu::ScreenMenu(Settings &settings)
: Screen(settings)
{
}

ScreenMenu::~ScreenMenu()
{
}

ScreenType ScreenMenu::run(sf::RenderWindow &window)
{   
    return ScreenType::Error;
}
