#include "ScreenSettings.hpp"

ScreenSettings::ScreenSettings(Settings &settings)
: Screen(settings)
{
}

ScreenSettings::~ScreenSettings()
{
}

ScreenType ScreenSettings::run(sf::RenderWindow &window)
{   
    sf::Event Event;
    nextScreen = ScreenType::Settings;
	
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
                            return ScreenType::Menu;
                            break;
                        default:
                            break;
                    }
                    break;
				default:
				    break;

                case sf::Event::MouseMoved:           
                    for(auto&& objects : clickable)
                        objects->onHover(sf::Mouse::getPosition());
                    break;
                
                case sf::Event::MouseButtonPressed:
                    switch(Event.mouseButton.button)
                    {
                        case sf::Mouse::Left:
                            for(auto&& objects : clickable)
                                objects->onClick(sf::Mouse::getPosition());
                            break;
                        default:
                            break;
                    }
                
			}
		}

		//Clearing screen
		window.clear(sf::Color(133, 191, 70, 128));
		//window.clear(sf::Color(0, 0, 0, 0));

        for (const auto &object : objects)
            window.draw(*object);
            //object->draw(window);
		
		window.display();

        if(nextScreen != ScreenType::Settings) 
            return nextScreen;
	}

    return ScreenType::Error;
}