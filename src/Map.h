#ifndef MAP_H
#define MAP_H

#include <string>
#include "GameComponent.h"

class Map : public GameComponent
{

 public:
  Map(std::string filename);
  bool isSolid(float x, float y);
  
 private:
  
  
};

#endif