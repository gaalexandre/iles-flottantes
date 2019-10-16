#ifndef PHYSIC_COMPONENT_H
#define PHYSIC_COMPONENT_H

#include <forward_list>
#include <SFML/Graphics.hpp>

class PhysicComponent
{
    public:
        
    protected:
        sf::FloatRect m_hitbox;
        bool m_gravity;
        bool solid;

  
};


#endif
