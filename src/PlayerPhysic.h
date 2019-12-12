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
                 float y, float width, float height,float, PersoEtatSystem*, PersoAnimation *animation, double xBegin, double yBegin);
    
    virtual void update(const sf::Time t);
    virtual void collide( PhysicComponent &other);
    void setVitesseX(float);
    void setVitesseY(float);
    void addVitesse(float, float);
    
    void saut();
    
    bool estEncollisionObstacle();
    bool estEnColiisionFinNiveau();
    
    
    

protected:
    

    virtual int intersect(sf::Vector2f point);
    virtual int intersect(sf::FloatRect rect);
    
    void resetCoord();
    
    sf::FloatRect m_hitBox;
    
    float m_transfX{0};
    float m_transfY{0};

    const int sizeDeplacement{2000};
    const int sizeJump{-700};
    const int gravite{1300};
    const int vitesseLimiteGravite{10000};

    const int airPowerFactor{2};
    const double deceleration{200};
    float m_vitesseX{0};
    float m_vitesseY{0};
    
   
    
    
    sf::Transform &m_transform;
    PersoEtatSystem& m_persoEtat;
    
    
    float m_scale{0};
    
    PersoAnimation &m_animation;
    
    double m_xBegin;
    double m_yBegin;

};




#endif /* PlayerPhysic_hpp */
