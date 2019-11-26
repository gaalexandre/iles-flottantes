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
#include "SystemComponent.h"
#include "Perso.h"
#include <SFML/System.hpp>

#include <stdio.h>

class PlayerPhysic : public PhysicComponent
{
public:
    
    PlayerPhysic(sf::Transform *m_transform,float x,
                 float y, float width, float height,float, PersoEtatSystem*);
    
    virtual void update(const sf::Time t);
    virtual void collide( PhysicComponent &other);
    void setVitesseX(float);
    void setVitesseY(float);
    void addVitesse(float, float);
    
    void saut();
    
    bool estEncollisionObstacle();
    bool estEnColiisionFinNiveau();
    
    
    

protected:
    

    virtual typeCollision intersect(sf::Vector2f point);
    virtual typeCollision intersect(sf::FloatRect rect);
    
    void resetCoord();
    
     sf::FloatRect m_hitBox;
    
    float m_transfX{0};
    float m_transfY{0};
    
    
    float m_vitesseX{0};
    float m_vitesseY{0};
    
    
    
    sf::Transform &m_transform;
    PersoEtatSystem& m_persoEtat;
    
    
    float m_scale{0};
    

    
};




#endif /* PlayerPhysic_hpp */
