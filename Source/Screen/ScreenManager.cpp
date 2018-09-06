#include "ScreenManager.hpp"
#include "ScreenMenu.hpp"
#include "ScreenGame.hpp"
#include "ScreenSettings.hpp"
#include <SFML/Graphics.hpp>

ScreenManager::ScreenManager(Settings &settings)
: settings(settings)
{
    // RenderWindow creation
    {
        sf::ContextSettings windowSettings;
        windowSettings.antialiasingLevel = 4;

        sf::Vector2u windowSize = settings.getWindowSize();

        window.create(sf::VideoMode(windowSize.x, windowSize.y, 32)
            , SM_WINDOW_NAME
            , settings.getWindowStyle()
            , windowSettings);

        window.setFramerateLimit(0);
    }

    // Screens memory allocation and construction
    {
        screens.reserve(3);
        screens.emplace_back(new ScreenMenu(settings)); // Menu
        screens.emplace_back(new ScreenSettings(settings)); // Settings
        screens.emplace_back(new ScreenGame(settings)); // Game
    }

    std::cout << "[SM] ScreenManager created!" << std::endl;
}

ScreenManager::~ScreenManager()
{
    std::cout << "[SM] ScreenManager destroyed!" << std::endl;
}

void ScreenManager::start()
{
    std::cout << "[SM] Opening menu..." << std::endl;

    ScreenType nextScreen = ScreenType::Menu;

    while(true)
    {
        nextScreen = screens[static_cast<int>(nextScreen)]->run(window);

        switch(nextScreen)
        {
            case ScreenType::Menu:
                break;
            case ScreenType::Game:
            std::cout << "[SM] Game!!!!!" << std::endl;
                break;
            case ScreenType::Settings:
            std::cout << "[SM] Settings!!!" << std::endl;
                break;
            case ScreenType::Exit:
                std::cout << "[SM] Return value \"Exit\" catched! Exiting" << std::endl;
                return;
                break;
            case ScreenType::Error:
                std::cout << "[SM] Return value \"Error\" catched! Exiting" << std::endl;
                return;
                break;
        }
    }
    
}