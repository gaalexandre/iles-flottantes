#include "MapGraphic.h"
#include <fstream>
#include <iostream>

MapGraphic::MapGraphic(const std::string& textureInfoFilename, const std::string& backgroundFilename, int height, int width, int tileSize, const int* tiles, int worldType)
{
    std::ifstream textureInfo(textureInfoFilename);
    typedef struct {
        int id;
        std::string name;
        int x;
        int y;
        int width;
        int height;
        int up;
        int right;
        int down;
        int left;
    } tile;

    std::string textureFilename, name;
    int nbTypesOfTiles, nbTexturesTypes, nbTextures, id;
    tile tileA;

    textureInfo >> textureFilename >> nbTypesOfTiles;

    tile*** tileList = new tile**[nbTypesOfTiles];
    
    for (int i=0; i<nbTypesOfTiles; ++i){
        textureInfo >> id >> name >> nbTexturesTypes;
        tileList[i] = new tile*[nbTexturesTypes];

        for (int j=0; j<nbTexturesTypes; ++j){
            textureInfo >> id >> name >> nbTextures;
            tileList[i][j] = new tile[nbTextures];

            std::cout << name << " " << i << " " << j << "\n";

            for (int k=0; k<nbTextures; ++k){
                textureInfo >> tileA.id >> tileA.name >> tileA.x >> tileA.y >> tileA.width >> tileA.height >> tileA.up >> tileA.right >> tileA.down >> tileA.left;
                std::cout << tileA.name << " " << i << " " << j << " " << k << "\n";
                tileList[i][j][k] = tileA;
            }
        }
    }
    

    
    m_tileset.loadFromFile(textureFilename);
    m_tilesetBackground.loadFromFile(backgroundFilename);
    m_vertices.setPrimitiveType(sf::Quads);
    m_vertices.resize(width * height * 4);
    m_verticesBackground.setPrimitiveType(sf::Quads);
    m_verticesBackground.resize(4);

    sf::Vertex* quad = &m_verticesBackground[0];
    
    quad[0].position = sf::Vector2f(0, 0);
    quad[1].position = sf::Vector2f(width * tileSize, 0);
    quad[2].position = sf::Vector2f(width * tileSize, height * tileSize);
    quad[3].position = sf::Vector2f(0, height * tileSize);

    sf::Vector2u backgroundSize = m_tilesetBackground.getSize();
    quad[0].texCoords = sf::Vector2f(0, 0);
    quad[1].texCoords = sf::Vector2f(backgroundSize.x, 0);
    quad[2].texCoords = sf::Vector2f(backgroundSize.x, backgroundSize.y);
    quad[3].texCoords = sf::Vector2f(0, backgroundSize.y);

    for (int i = 0; i < width; ++i)
        for (int j = 0; j < height; ++j)
        {
            int tileNumber = tiles[i + j * width];

            for(int k = 0; ;++k){
                tileA = tileList[tileNumber][worldType][k];
                if((tileA.up==1 && j > 0 && tiles[i + (j-1) * width]!=tileNumber ) ||
                    (tileA.up==0 && j > 0 && tiles[i + (j-1) * width]==tileNumber ) ||
                    (tileA.down==1 && j < height && tiles[i + (j+1) * width]!=tileNumber ) ||
                    (tileA.down==0 && j < height && tiles[i + (j+1) * width]==tileNumber ) ||
                    (tileA.left==1 && i > 0 && tiles[(i-1) + j * width]!=tileNumber ) ||
                    (tileA.left==0 && i > 0 && tiles[(i-1) + j * width]==tileNumber ) ||
                    (tileA.right==1 && i < width && tiles[(i+1) + j * width]!=tileNumber ) ||
                    (tileA.right==0 && i < width && tiles[(i+1) + j * width]==tileNumber )){
                        continue;
                }
                break;
            }

            int tu = tileNumber % (m_tileset.getSize().x / tileSize);
            int tv = tileNumber / (m_tileset.getSize().x / tileSize);

            sf::Vertex* quad = &m_vertices[(i + j * width) * 4];

            quad[0].position = sf::Vector2f(i * tileSize, j * tileSize);
            quad[1].position = sf::Vector2f((i + 1) * tileSize, j * tileSize);
            quad[2].position = sf::Vector2f((i + 1) * tileSize, (j + 1) * tileSize);
            quad[3].position = sf::Vector2f(i * tileSize, (j + 1) * tileSize);

            quad[0].texCoords = sf::Vector2f(tileA.x, tileA.y);
            quad[1].texCoords = sf::Vector2f(tileA.x + tileA.width, tileA.y);
            quad[2].texCoords = sf::Vector2f(tileA.x + tileA.width, tileA.y + tileA.height);
            quad[3].texCoords = sf::Vector2f(tileA.x, tileA.y + tileA.height);
        }
}

void MapGraphic::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.texture = &m_tilesetBackground;

    target.draw(m_verticesBackground, states);

    states.texture = &m_tileset;

    target.draw(m_vertices, states);
}
