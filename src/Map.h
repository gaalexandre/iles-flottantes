#ifndef MAP_H
#define MAP_H

#include <string>
#include "GameComponent.h"

class Map : public GameComponent
{

 public:
  Map(std::string filename);
  virtual ~Map();
  
 private:
  int* m_tilesKind{nullptr}; //il est là juste pour être delete dans le destructeur
  
};

#endif
