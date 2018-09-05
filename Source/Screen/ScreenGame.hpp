#pragma once 
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Screen.hpp"

class ScreenGame : public Screen
{
private:
    
public:
    ScreenGame(Settings &settings);
    ~ScreenGame();
};
