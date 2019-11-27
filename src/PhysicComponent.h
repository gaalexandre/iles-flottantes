#ifndef PHYSIC_COMPONENT_H
#define PHYSIC_COMPONENT_H

#include <forward_list>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>


enum typeCollision
{
    AucuneCollision=0,
    Collision=1,
    CollisionMortel=2,
    CollisionFinNiveau=3
};



class PhysicComponent
{

public:
  virtual ~PhysicComponent(){};
  virtual void update(sf::Time) = 0;
  virtual void collide( PhysicComponent &other) = 0;
  virtual typeCollision intersect( sf::Vector2f point) = 0;
  virtual typeCollision intersect(sf::FloatRect rectangle) = 0;

protected:
  
};


#endif
