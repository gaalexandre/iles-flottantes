//
//  PlayerPhysic.hpp
//  
//
//  Created by Lucas Bourel on 24/10/2019.
//

#ifndef PlayerPhysic_hpp
#define PlayerPhysic_hpp

#include <SFML/Graphics.hpp>
#include "PhysicComponent.h"
#include <SFML/System.hpp>

#include <stdio.h>

class PlayerPhysic : public
{
public:
    
    PlayerPhysic()

    virtual void update(sf::Time t);
    virtual void collide( PhysicComponent &other);
    void setAccelerationX(float);
    void setAccelerationY(float);
    void addAcceleration(float, float);
    

protected:

    virtual bool intersect(sf::Vector2f point);
    virtual bool intersect(sf::FloatRect rect);
    
private:
    float sf::floatRect m_hitBox{0, 0, 0, 0};
    float sf::floatRect m_hitBox_tmp{0, 0, 0, 0};
    float m_accelerationX{0};
    float m_accelerationY{0};
    
    
}




#endif /* PlayerPhysic_hpp */
