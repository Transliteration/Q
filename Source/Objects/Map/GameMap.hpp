#pragma once 
#include <SFML/Graphics.hpp>
#include <vector>
#include <utility>
#include "../Drawable.hpp"

#define MAP_TILE_SIZE 128

class GameMap : public Drawable
{
private:
    sf::RenderTexture mapTexture, fogTexture;
    sf::Sprite mapSprite;
    sf::Texture textureTiles;
    sf::Vector2u size;
    std::vector<std::vector<int>> map;
    std::vector<std::pair<sf::Vector2f, sf::Vector2f>> obstacleLines;

    void onChangeResoluton(sf::Vector2u newResolution);
    bool loadMapFromFile(const std::string &path); // resize map and load map from file 
    bool loadTextureFile(); // load tiles
    void assignTilesToMap();

    void computeObstacleLines();
    void drawLinesFromSides(unsigned x, unsigned y);
    void tryToProlongLine(unsigned x, unsigned y, bool isVertical, bool isTopleft);


public:
    GameMap(std::string path); // size - is number of tiles on screen
    ~GameMap();

    void draw(sf::RenderTarget &target, sf::RenderStates states) const;
    
};

