#ifndef MAP_PHYSIC_H
#define MAP_PHYSIC_H

#include <SFML/Graphics.hpp>
#include "PhysicComponent.h"

class MapPhysic : public PhysicComponent
{

public:
  MapPhysic(int height, int width, int tileSize, const int* tilesKind);

private:

};




#endif
