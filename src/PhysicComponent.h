#ifndef PHYSIC_COMPONENT_H
#define PHYSIC_COMPONENT_H

#include <forward_list>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>


enum typeCollision
{
    //l'ordre indique la priorité dans le retour lors d'une collision multiple
    AucuneCollision=0,
    CollisionCle = 1<<0,
    CollisionFireAltar = 1<<1,
    CollisionWaterAltar = 1<<2,
    CollisionEarthAltar = 1<<3,
    CollisionAirAltar = 1<<4,
    CollisionNullAltar = 1<<5,
    CollisionFinNiveau = 1<<6,
    Collision = 1<<7,
    CollisionMortel = 1<<8,
    CollisionFeu = 1<<9
};



class PhysicComponent
{

public:
  virtual ~PhysicComponent(){};
  virtual void update(sf::Time) = 0;
  virtual void collide( PhysicComponent &other) = 0;
  virtual int intersect( sf::Vector2f point) = 0;
  virtual int intersect(sf::FloatRect rectangle) = 0;

protected:
  
};


#endif
