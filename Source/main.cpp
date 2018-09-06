#include <iostream>
#include <SFML/Graphics.hpp>
#include "GameInitializer.hpp"

int main(int agrv, char **argc)
{
    GameInitializer::initialize();
    std::cout << "Done!" << std::endl;
    return 0;
}
