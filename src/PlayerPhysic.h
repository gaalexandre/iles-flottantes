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

class PlayerPhysic : public PhysicComponent
{
public:
    
    PlayerPhysic(sf::Transform *m_transform);
    
    virtual void update(const sf::Time t);
    virtual void collide( PhysicComponent &other);
    void setVitesseX(float);
    void setVitesseY(float);
    void addVitesse(float, float);
    

protected:

    virtual bool intersect(sf::Vector2f point);
    virtual bool intersect(sf::FloatRect rect);
    
     sf::FloatRect m_hitBox{0, 0, 0, 0};
     sf::FloatRect m_hitBox_tmp{0, 0, 0, 0};
    float m_vitesseX{0};
    float m_vitesseY{0};
    
    
    sf::Transform &m_transform;

    
};




#endif /* PlayerPhysic_hpp */
