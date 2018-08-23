#pragma once 
#include <SFML/Graphics.hpp>

class Settings
{
private:
    sf::Vector2u windowSize;
    sf::Font font;
    int windowStyle;

    void loadData(const std::string &pathToData);
    void createDefaultDataFile(const std::string &pathToData);
public:
    Settings(const std::string &pathToData);
    ~Settings();

    sf::Vector2u getWindowSize();
    const sf::Font &getFont();
    int getWindowStyle();
};


