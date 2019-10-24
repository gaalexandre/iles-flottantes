#ifndef MAP_PHYSIC_H
#define MAP_PHYSIC_H

#include <SFML/Graphics.hpp>
#include "PhysicComponent.h"

class MapPhysic : public PhysicComponent
{

public:
  MapPhysic(int height, int width, int tileSize, const int* const* tilesKind);
    
// sur quellles coordonnées (?), des float (?) 
  bool isSolid(float x,float y);

protected:
    virtual void update();
    virtual void collide( PhysicComponent &other);
    virtual bool intersect(sf::Vector2f point);
    virtual bool intersect(sf::FloatRect rect);
private:
  const int* const* m_tilesKind;
  int m_width;
  int m_height;
  int m_tileSize;
    
    
};




#endif
