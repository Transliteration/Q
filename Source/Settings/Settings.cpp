#include <iostream>
#include <fstream>
#include "Settings.hpp"

Settings::Settings(const std::string &pathToData)
{
    loadData(pathToData);

    std::cout << "[Settings] Data loaded succesfully!" << std::endl;

    if (!font.loadFromFile("Resources/Fonts/SIMPLIFICA Typeface.ttf")) {
		std::cout << "[Settings] Font didn't load!" << std::endl;
		throw;
	}

    std::cout << "[Settings] Font loaded succesfully!" << std::endl;

    std::cout << "[Settings] Settings is set!" << std::endl;
}

Settings::~Settings()
{
    std::cout << "[Settings] Settings destroyed!" << std::endl;
}

void Settings::loadData(const std::string &pathToData)
{
    std::ifstream dataFile(pathToData);
    
    if( !dataFile.is_open() ) // If file can not be opened or it is broken, create default data file
    {
        std::cout << "[Settings] Data file is not open!" << std::endl;

        dataFile.close();
        createDefaultDataFile(pathToData);
        dataFile.open(pathToData);
    }
    
    std::cout << "[Settings] Data file is open!" << std::endl;

    dataFile >> windowSize.x >> windowSize.y;
    dataFile >> windowStyle;

    dataFile.close();
}

void Settings::createDefaultDataFile(const std::string &pathToData)
{
    std::ofstream dataFile(pathToData, std::ios_base::trunc | std::ios_base::out);

    dataFile << "1366 768\n"; // default resolution
    dataFile << sf::Style::Default;

    dataFile.close();

    std::cout << "[Settings] Creating default data file" << std::endl;
}

sf::Vector2u Settings::getWindowSize()
{
    return windowSize;
}

int Settings::getWindowStyle()
{
    return windowStyle;
}

const sf::Font &Settings::getFont()
{
    return font;
}