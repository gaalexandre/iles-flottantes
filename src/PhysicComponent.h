#ifndef PHYSIC_COMPONENT_H
#define PHYSIC_COMPONENT_H

#include <forward_list>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class PhysicComponent
{
    public:
    
    virtual void update(sf::Time) = 0;
    virtual void collide( PhysicComponent &other) = 0;
    virtual bool intersect( sf::Vector2f point) = 0;
    virtual bool intersect(sf::FloatRect rectangle) = 0;
    protected:
    
    
  

  
};


#endif
