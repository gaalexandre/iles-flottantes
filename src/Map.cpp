#include "Map.h"
#include "MapGraphic.h"
#include "MapPhysic.h"
#include <fstream>
#include <iostream>

Map::Map(std::string filename) 
{
  std::ifstream mapFile(filename);
  std::string textureDescriptionFilename, textureFilename, backgroundFilename;
  int height, width, tileSize, worldType;
  mapFile >> textureDescriptionFilename >> textureFilename >> backgroundFilename >> height >> width >> tileSize >> worldType;

  std::ifstream textureDescription(textureDescriptionFilename);
  int nbTile;
  textureDescription >> nbTile;
    std::cout << nbTile << std::endl;
  int *tilesKinds = new int[nbTile];
    
  for(int i(0);i<nbTile;++i)
    textureDescription >> tilesKinds[i];

  int *tilesNumber = new int[height*width];


  m_tilesKind = new int*[width];

  for(int i(0);i<width;++i)
    m_tilesKind[i] = new int[height];
  

  for(int j(0);j<height;++j)
  {
    for(int i(0);i<width;++i)
    {
      mapFile >> tilesNumber[(i + j * width)];
      m_tilesKind[i][j] = tilesKinds[tilesNumber[(i + j * width)]];

      //std::cout << m_tilesKind[i][j] << "";
    }
    //std::cout << "\n";
  }
  m_graphicComponent = new MapGraphic(textureFilename, backgroundFilename, height, width, tileSize, tilesNumber, worldType);
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
