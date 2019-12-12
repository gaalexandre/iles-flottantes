#include "MapGraphic.h"
#include <fstream>
#include <iostream>



MapGraphic::MapGraphic(const std::string& textureInfoFilename, const std::string& backgroundFilename, int height, int width, int tileSize, const int* tiles, int worldType)
{
    m_tileSize =  tileSize;
    m_width = width;
    m_height = height;
  
    std::ifstream textureInfo(textureInfoFilename);
    
    

    std::string textureFilename, name;
    int  id;
    tile tileA;

    textureInfo >> textureFilename >> m_nbTypesOfTiles;

    m_tileList = new tile**[m_nbTypesOfTiles];
    
    for (int i=0; i<m_nbTypesOfTiles; ++i){
        textureInfo >> id >> name >> m_nbTexturesTypes;
        m_tileList[i] = new tile*[m_nbTexturesTypes];

        for (int j=0; j<m_nbTexturesTypes; ++j){
            textureInfo >> id >> name >> m_nbTextures;
            m_tileList[i][j] = new tile[m_nbTextures];

            //std::cout << name << " " << i << " " << j << "\n";

            for (int k=0; k<m_nbTextures; ++k){
                textureInfo >> tileA.id >> tileA.name >> tileA.x >> tileA.y >> tileA.width >> tileA.height >> tileA.up >> tileA.right >> tileA.down >> tileA.left;
                //std::cout << tileA.name << " " << i << " " << j << " " << k << "\n";
                m_tileList[i][j][k] = tileA;
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
                tileA = m_tileList[tileNumber][worldType][k];
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

void MapGraphic::update(sf::Time t)
{
    // Le MapGraphic n'est pas un component dynamique
    return;
}



void MapGraphic::change(sf::Vector2f point, int changement)
{
  
  // 0,0,0 ?
  int width = m_tileList[1][0][0].width;
  int height = m_tileList[1][0][0].height;
  
  
  tile tileA = m_tileList[changement][0][0];
  
  
 
  int i = point.x / m_tileSize;
  int j = point.y / m_tileSize;
  
  std::cout << i << std::endl;
  std::cout << j << std::endl;
  
  sf::Vertex* quad = &m_vertices[(j*m_width+i)*4];
  
  
  
  quad[0].texCoords = sf::Vector2f(tileA.x, tileA.y);
  quad[1].texCoords = sf::Vector2f(tileA.x + tileA.width, tileA.y);
  quad[2].texCoords = sf::Vector2f(tileA.x + tileA.width, tileA.y + tileA.height);
  quad[3].texCoords = sf::Vector2f(tileA.x, tileA.y + tileA.height);
  
}
