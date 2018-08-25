#include <memory>
#include "ScreenMenu.hpp"
#include "Settings.hpp"
#include "Button.hpp"

ScreenMenu::ScreenMenu(Settings &settings)
: Screen(settings)
{
    nextScreen = ScreenType::Menu;
    const sf::Font &font = settings.getFont();

    std::shared_ptr<Button> buttonNewGame(new Button(font, sf::Vector2f(0.15f, 0.6f), "New game", Align::TopLeft));
    objects.emplace_back(buttonNewGame);
    clickable.emplace_back(buttonNewGame);

    std::shared_ptr<Button> buttonSettings(new Button(font, sf::Vector2f(0.15f, 0.7f), "Settings", Align::TopLeft));
    objects.emplace_back(buttonSettings);
    clickable.emplace_back(buttonSettings);

    std::shared_ptr<Button> buttonExit(new Button(font, sf::Vector2f(0.15f, 0.8f), "Exit", Align::TopLeft));
    
    objects.emplace_back(buttonExit);
    clickable.emplace_back(buttonExit);

    buttonExit->setFunction([this](){ nextScreen = ScreenType::Exit; });
    buttonNewGame->setFunction([this](){ nextScreen = ScreenType::Game; });
    buttonSettings->setFunction([this](){ nextScreen = ScreenType::Settings; });

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
		//App.clear(sf::Color(0, 191, 255, 128));
		window.clear(sf::Color(0, 0, 0, 0));

        for (const auto &object : objects)
            object->draw(window);
		
		window.display();

        if(nextScreen != ScreenType::Menu) 
            return nextScreen;
	}

    return ScreenType::Error;
}
