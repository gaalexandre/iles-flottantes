#ifndef PHYSIC_COMPONENT_H
#define PHYSIC_COMPONENT_H

#include <forward_list>
#include <SFML/Graphics.hpp>

class PhysicComponent
{
    public:
        float getAbs ();
        float getOrd ();
        void setAcceleration(int acc);
        virtual bool isSolid(float x, float y) = 0;
    protected:
        sf::FloatRect m_hitbox;
        bool m_gravity;
        bool m_solid;
        float m_abs;
        float m_ord;
        float m_acc;
  

  
};


#endif
