#include "Map.h"
#include "MapGraphic.h"
#include "MapPhysic.h"
#include <fstream>
#include <iostream>

Map::Map(std::string filename) 
{
  std::ifstream mapFile(filename);
  std::string textureDescriptionFilename, textureFilename;
  int height, width, tileSize;
  mapFile >> textureDescriptionFilename >> textureFilename >> height >> width >> tileSize;

  std::ifstream textureDescription(filename);
  int nbTile;
  textureDescription >> nbTile;
    std::cout << nbTile << std::endl;
  int *tilesKinds = new int[nbTile];
    
  for(int i(0);i<nbTile;++i)
    textureDescription >> tilesKinds[i];

  int *tilesNumber = new int[height*width];
    
  m_tilesKind = new int*[width];
  for(int i(0);i<width;++i)
  {
      m_tilesKind[i] = new int[height];
    for(int j(0);j<height;++j)
    {
      mapFile >> tilesNumber[(i + j * width)];
        m_tilesKind[i][j] = tilesKinds[tilesNumber[(i + j * width)]];
    }
  }
  m_graphicComponent = new MapGraphic(textureFilename, height, width, tileSize, tilesNumber);
  m_physicComponent = new MapPhysic(height, width, tileSize, m_tilesKind);
    

  delete[] tilesKinds;
  delete[] tilesNumber;
}


Map::~Map()
{
  delete m_graphicComponent;
  delete m_physicComponent;
  delete[] m_tilesKind;
}
