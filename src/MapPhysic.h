#ifndef MAP_PHYSIC_H
#define MAP_PHYSIC_H

#include <SFML/Graphics.hpp>
#include "PhysicComponent.h"
#include <SFML/System.hpp>


class MapPhysic : public PhysicComponent
{

public:

  MapPhysic(int height, int width, int tileSize, int const* const* const tilesKind);
  virtual ~MapPhysic();


    virtual void update(sf::Time t);
    virtual void collide( PhysicComponent &other);
    
protected:
    
    
    virtual typeCollision intersect(sf::Vector2f point);
    virtual typeCollision intersect(sf::FloatRect rect);
    
    
    const int* const* m_tilesKind;
    int m_width;
    int m_height;
    int m_tileSize;
    
    
};

#endif
