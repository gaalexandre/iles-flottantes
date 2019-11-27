#ifndef PHYSIC_COMPONENT_H
#define PHYSIC_COMPONENT_H

#include <forward_list>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>


enum typeCollision
{
    //l'ordre indique la priorité dans le retour lors d'une collision multiple
    AucuneCollision=0,
    CollisionCle=1,
    Collision=2,
    CollisionMortel=3,
    CollisionFinNiveau=4
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
