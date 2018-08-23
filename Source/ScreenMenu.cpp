#include "ScreenMenu.hpp"
#include "Settings.hpp"
#include "Button.hpp"

ScreenMenu::ScreenMenu(Settings &settings)
: Screen(settings)
{
    const sf::Font &font = settings.getFont();
    objects.emplace_back(new Button(font, sf::Vector2f(0.15f, 0.6f), "New game"));
    objects.emplace_back(new Button(font, sf::Vector2f(0.15f, 0.7f), "Settings"));
    objects.emplace_back(new Button(font, sf::Vector2f(0.15f, 0.8f), "Exit"));

    for (const auto &object : objects)
        object->onChangeResoluton(settings.getWindowSize());
}

ScreenMenu::~ScreenMenu()
{
}

ScreenType ScreenMenu::run(sf::RenderWindow &window)
{   
    sf::Event Event;
	
	window.setMouseCursorVisible(true);

    bool isRunning = true;
	while (isRunning)
	{
		//Verifying events
		while (window.pollEvent(Event))
		{
			switch(Event.type)
			{
				// Window closed
				case sf::Event::Closed:
					return ScreenType::Exit;
					break;

				//Key pressed
				case sf::Event::KeyPressed:
                    switch(Event.key.code)
                    {
                        case sf::Keyboard::Escape:
                            return ScreenType::Exit;
                            break;
                        default:
                            break;
                    }
                    break;
				default:
				    break;
			}
		}

		//Clearing screen
		//App.clear(sf::Color(0, 191, 255, 128));
		window.clear(sf::Color(0, 0, 0, 0));

        for (const auto &object : objects)
            object->draw(window);
		
		window.display();
	}

    return ScreenType::Error;
}
