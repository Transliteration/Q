#pragma once 
#include <SFML/Graphics.hpp>
#include <vector>
#include <utility>
#include "../Drawable.hpp"

#define MAP_TILE_SIZE 128

class GameMap : public Drawable
{
private:
    sf::VertexArray m_vertices;
    sf::Texture textureTiles;
    sf::Vector2u size;
    std::vector<std::vector<int>> map;

    void onChangeResoluton(sf::Vector2u newResolution);
    bool loadMapFromFile(const std::string &path); // resize map and load map from file 
    bool loadTextureFile(); // load tiles
    void assignTilesToMap();

public:
    GameMap(std::string path); // size - is number of tiles on screen
    ~GameMap();

    void draw(sf::RenderTarget &target, sf::RenderStates states) const;
    
};

