#include <iostream>
#include "GameInitializer.hpp"
#include "Screen/ScreenManager.hpp"

void GameInitializer::initialize()
{
    std::cout << "====Loading settings..." << std::endl;
    Settings settings("Data/settings.dat");
    std::cout << "====Done!" << std::endl;

    std::cout << "====Constructing screen manager..." << std::endl;
    ScreenManager screenManager(settings);
    std::cout << "====Done!" << std::endl;

    std::cout << "====Launching game..." << std::endl;
    screenManager.start();
    std::cout << "====Exiting the game..." << std::endl;
}