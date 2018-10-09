#include <iostream>
#include <fstream>
#include "GameMap.hpp"

GameMap::GameMap(std::string path)
: Drawable(Priority::Map)
{
    if (!loadMapFromFile(path))
    {
        std::cout << "[MAP] Error loading map: " + path << std::endl;
        return;
    } else std::cout << "[MAP] Map loaded!" << std::endl;

    if (!loadTextureFile())
    {
        std::cout << "[MAP] Error loading tilemap: " + path << std::endl;
        return;
    } else std::cout << "[MAP] Tilemap loaded!" << std::endl;

    assignTilesToMap();
    
    /* pashalochka ot max I.()
    {
        int x,y,z;
        scanf("%d %d",&x,&y);
        z=x*y;
        printf("%d", z);
        return 0;
    }
    */
}

GameMap::~GameMap()
{
}

bool GameMap::loadMapFromFile(const std::string &path) // resize map and load map from file 
{
    std::ifstream mapFile(path);
    
    if( !mapFile.is_open() ) return false;
    else
    {
        mapFile >> size.x >> size.y;

        map = std::vector<std::vector<int>>(size.x, std::vector<int>(size.y, 0));

        for (unsigned int y = 0; y < size.y; y++)
            for (unsigned int x = 0; x < size.x; x++)
                mapFile >> map[x][y];

        return true;
    }
}

bool GameMap::loadTextureFile() // load tiles
{
    return textureTiles.loadFromFile("Resources/tileset.png");
}

void GameMap::assignTilesToMap()
{ 
    m_vertices.resize(size.x * size.y * 4);
    m_vertices.setPrimitiveType(sf::Quads);

    for (unsigned int y = 0, step = 0; y < size.y; ++y)
        for (unsigned int x = 0; x < size.x; ++x)
        {
            // get the current tile number
            int tileNumber = map[x][y]; //map[q].chunk[i][j];
            
            // find its position in the tileset texture
            int tu = tileNumber % (textureTiles.getSize().x / MAP_TILE_SIZE);
            int tv = tileNumber / (textureTiles.getSize().x / MAP_TILE_SIZE);

            // get a pointer to the current tile's quad
            sf::Vertex* quad = &m_vertices[step++ * 4];

            // define its 4 corners
            quad[0].position = sf::Vector2f(x * MAP_TILE_SIZE, y * MAP_TILE_SIZE);
            quad[1].position = sf::Vector2f((x + 1) * MAP_TILE_SIZE, y * MAP_TILE_SIZE);
            quad[2].position = sf::Vector2f((x + 1) * MAP_TILE_SIZE, (y + 1) * MAP_TILE_SIZE);
            quad[3].position = sf::Vector2f(x * MAP_TILE_SIZE, (y + 1) * MAP_TILE_SIZE);

            // define its 4 texture coordinates
            quad[0].texCoords = sf::Vector2f(tu * MAP_TILE_SIZE, tv * MAP_TILE_SIZE);
            quad[1].texCoords = sf::Vector2f((tu + 1) * MAP_TILE_SIZE, tv * MAP_TILE_SIZE);
            quad[2].texCoords = sf::Vector2f((tu + 1) * MAP_TILE_SIZE, (tv + 1) * MAP_TILE_SIZE);
            quad[3].texCoords = sf::Vector2f(tu * MAP_TILE_SIZE, (tv + 1) * MAP_TILE_SIZE);
        }
}

void GameMap::onChangeResoluton(sf::Vector2u newResolution)
{
}

void GameMap::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    // apply the transform
    states.transform *= getTransform();

    // apply the tileset texture
    states.texture = &textureTiles;

    // draw the vertex array
    target.draw(m_vertices, states);
}