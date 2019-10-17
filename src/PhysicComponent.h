#ifndef PHYSIC_COMPONENT_H
#define PHYSIC_COMPONENT_H

#include <forward_list>
#include <SFML/Graphics.hpp>

class PhysicComponent
{
    public:
    
    void update();
    void collide( PhysicComponent &other);
    void intersect( sf::Vector2f point);
    
    protected:
    
    
  

  
};


#endif
