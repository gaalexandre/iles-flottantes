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

  m_height = height;
  m_width = width;
  m_tileSize = tileSize;
  
  std::ifstream textureDescription(textureDescriptionFilename);
  int nbTile;
  textureDescription >> nbTile;
    //std::cout << nbTile << std::endl;
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

int Map::typeBloc(sf::Vector2f point)
{
  int i = point.x / m_tileSize;
  int j = point.y / m_tileSize;
  return m_tilesKind[i][j];
  
}
bool Map::change(sf::Vector2f point, int changement, int changementKind)
{
  
  int i = point.x / m_tileSize;
  int j = point.y / m_tileSize;
  
  if(i > m_width || j> m_height) // >= ?
  {
    return false;
  }
  
  (dynamic_cast<MapGraphic*>(m_graphicComponent))->change(point, changement);// A MODIFIER
  
  
  m_tilesKind[i][j] = changementKind;
   
  return true;
   
  
}
              
              
Map::~Map()
{
  delete m_graphicComponent;
  delete m_physicComponent;
  delete[] m_tilesKind;
}
