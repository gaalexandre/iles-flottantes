//
//  PlayerPhysic.cpp
//  
//
//  Created by Lucas Bourel on 24/10/2019.
//

#include "PlayerPhysic.h"


PlayerPhysic::PlayerPhysic(sf::Transform *t) : m_transform (*t)


{
    //m_hitBox = hitBox;
    //m_hitBox_tmp = hitBox;
}



void PlayerPhysic::update(const sf::Time t) // bouge selon les accelaration.
{
    m_hitBox_tmp = m_hitBox;
    m_hitBox.left += m_vitesseX*( t.asSeconds());
    m_hitBox.top += m_vitesseY*( t.asSeconds() );
    m_transform.translate(  m_vitesseX*( t.asSeconds()), m_vitesseY*( t.asSeconds()));
    
    m_transform.translate(0, 10*t.asSeconds());
                          
    return;
    
}

void PlayerPhysic::collide(PhysicComponent &other)
{
    //algorithme (?)
    if(other.intersect(m_hitBox))  // ne marche pas bien
    {
        m_transform.translate(m_hitBox.left- m_hitBox_tmp.left, m_hitBox.top - m_hitBox_tmp.top);
    }
    return;
}


bool PlayerPhysic::intersect(sf::Vector2f point)
{
    
    return m_hitBox.contains(point);
            

}

bool PlayerPhysic::intersect(sf::FloatRect rect)
{
    
    return rect.intersects(m_hitBox);
       
}



void PlayerPhysic::setVitesseX(float accelerationX)
{
    m_vitesseX = accelerationX;
}
void PlayerPhysic::setVitesseY(float accelerationY)
{
    m_vitesseY = accelerationY;
}
void PlayerPhysic::addVitesse(float accelerationX, float accelerationY)
{
    m_vitesseY+= accelerationY;
    m_vitesseX+= accelerationX;
}
