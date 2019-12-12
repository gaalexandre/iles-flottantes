#ifndef MAP_H
#define MAP_H

#include <string>
#include "GameComponent.h"
#include "MapGraphic.h"

struct MapEtatSystem
{
  
  
};
class Map : public GameComponent
{

 public:
  Map(std::string filename);
  virtual ~Map();
  
  bool change(sf::Vector2f point, int changementGraphic, int changementKind);
  int typeBloc(sf::Vector2f point);
  
  
 private:
  int** m_tilesKind{nullptr};
  int m_height;
  int m_width;
  int m_tileSize;
  
};

#endif
