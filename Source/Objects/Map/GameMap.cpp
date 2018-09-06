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

    mapTexture.create(size.x * MAP_TILE_SIZE, size.y * MAP_TILE_SIZE);
    fogTexture.create(size.x * MAP_TILE_SIZE, size.y * MAP_TILE_SIZE);

    assignTilesToMap();
    computeObstacleLines();

    
    for(auto&& line : obstacleLines)
    {
        std::cout << "(" << line.first.x  << ", " << line.first.y  << ")" 
                  << "(" << line.second.x << ", " << line.second.y << ")" << std::endl;
    }
    
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
    sf::VertexArray m_vertices;
    m_vertices.resize(size.x * size.y * 4);
    m_vertices.setPrimitiveType(sf::Quads);

    for (unsigned int x = 0, step = 0; x < size.x; ++x)
        for (unsigned int y = 0; y < size.y; ++y)
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

    sf::RenderStates states;
    states.texture = &textureTiles;
    mapTexture.draw(m_vertices, states);
    mapSprite.setTexture(mapTexture.getTexture());
}

void GameMap::onChangeResoluton(sf::Vector2u newResolution)
{
}

void GameMap::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    //states.transform *= getTransform();
    //states.texture = &textureTiles;
    target.draw(mapSprite);
    //target.draw(visionLines, states);
    //target.draw(player, states);
}

void GameMap::computeObstacleLines()
{
    for(unsigned x = 0; x < size.x; x++)
        for (unsigned y = 0; y < size.y; y++)
        if(map[x][y] > 0)
        {
            std::cout << "JJJJJJJ" << std::endl;
            drawLinesFromSides(x, y);
        } 
}

void GameMap::drawLinesFromSides(unsigned x, unsigned y)
{
    if(x > 0 && map[x - 1][y] == 0) tryToProlongLine(x - 1, y, true, true);
    if(y > 0 && map[x][y - 1] == 0) tryToProlongLine(x, y - 1, false, true);
    if(x < size.x - 1 && map[x + 1][y] == 0) tryToProlongLine(x - 1, y, true, false);
    if(y < size.y - 1 && map[x][y + 1] == 0) tryToProlongLine(x - 1, y, false, false);
}

void GameMap::tryToProlongLine(unsigned x, unsigned y, bool isVertical, bool isTopleft)
{
    sf::Vector2f coords;
    if (isTopleft) coords = sf::Vector2f(x * MAP_TILE_SIZE, y * MAP_TILE_SIZE);
    else coords = sf::Vector2f((x + 1) * MAP_TILE_SIZE, (y + 1) * MAP_TILE_SIZE);

    obstacleLines.emplace_back(coords, coords);
}