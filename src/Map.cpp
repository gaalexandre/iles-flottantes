#include "Map.h"
#include "MapGraphic.h"
#include "MapPhysic.h"
#include <fstream>
Map::Map(std::string filename) 
{
  std::ifstream mapFile(filename);
  std::string textureDescriptionFilename, textureFilename;
  int height, width, tileSize;
  mapFile >> textureDescriptionFilename >> textureFilename >> height >> width >> tileSize;

  std::ifstream textureDescription(filename);
  int nbTile;
  textureDescription >> nbTile;
  int *tilesKinds = new int[nbTile];
  for(int i(0);i<nbTile;++i)
    textureDescription >> tilesKinds[i];

  int *tilesNumber = new int[height*width];
  int *tilesKind = new int[height*width];
  for(int i(0);i<width;++i)
  {
    for(int j(0);j<height;++j)
    {
      mapFile >> tilesNumber[(i + j * width)];
      tilesKind[(i + j * width)] = tilesKinds[tilesNumber[(i + j * width)]];
    }
  }
  m_graphicComponent = new MapGraphic(textureFilename, height, width, tileSize, tilesNumber);
  m_physicComponent = new MapPhysic(height, width, tileSize, tilesKind);
}


bool Map::isSolid(float x,float y){
  return m_physicComponent->isSolid(x,y);
}
