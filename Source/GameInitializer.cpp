#include <iostream>
#include "GameInitializer.hpp"
#include "Screen/ScreenManager.hpp"

void GameInitializer::initialize()
{
    std::cout << "[GameInit] Loading settings..." << std::endl;
    Settings settings("Data/settings.dat");
    std::cout << "[GameInit] Done!" << std::endl;

    std::cout << "[GameInit] Constructing screen manager..." << std::endl;
    ScreenManager screenManager(settings);
    std::cout << "[GameInit] Done!" << std::endl;

    std::cout << "[GameInit] Launching game..." << std::endl;
    screenManager.start();
    std::cout << "[GameInit] Exiting the game..." << std::endl;
}