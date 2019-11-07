//
//  PlayerPhysic.cpp
//  
//
//  Created by Lucas Bourel on 24/10/2019.
//

#include "PlayerPhysic.h"
#include <iostream>

PlayerPhysic::PlayerPhysic(sf::Transform *t,float x, float y, float width, float height)
:  m_hitBox(x,y, 4.f*width, 4.f*height),m_transform (*t)
{
   
}



void PlayerPhysic::update(const sf::Time t) // bouge selon les accelaration.
{
    
    addVitesse(0,50*t.asSeconds());
    
    //gestion de la gravité
    if(m_vitesseY>400) // vitesse limite
    {
        m_vitesseY=400;
    }
    
    
    m_hitBox.left += 4.f*m_vitesseX*( t.asSeconds());
    m_hitBox.top += 4.f*(m_vitesseY*( t.asSeconds() )+10*t.asSeconds());
    m_transform.translate(  m_vitesseX*( t.asSeconds()), m_vitesseY*( t.asSeconds())+10*t.asSeconds());
    m_transfX =m_vitesseX*( t.asSeconds());
    m_transfY =m_vitesseY*( t.asSeconds())+10*t.asSeconds();
    
    
    
    
    return;
    
}

void PlayerPhysic::collide(PhysicComponent &other)
{
    //algorithme (?)
    m_surLeSol = false;
    
    if(other.intersect(m_hitBox))  // ne marche pas bien
    {
        
        m_transform.translate( -1*m_transfX, 0);
        m_hitBox.left -= 4.f*m_transfX;
        if(other.intersect(m_hitBox))
        {
            if(m_transfY>0)
            {
                m_surLeSol=true;
            }
            
            m_transform.translate(m_transfX, 0);
            m_hitBox.left += 4.f*m_transfX;
            
            m_transform.translate(0, -1*m_transfY);
            m_hitBox.top -= 4.f*m_transfY;
            if(other.intersect(m_hitBox))
            {
                m_transform.translate( -1*m_transfX, 0);
                m_hitBox.left -= 4.f*m_transfX;
                
                return;
            }
            
            else{
                
                return;
            }
            
        }
        
        else{
            return;
        }
        
        
     
        
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





void PlayerPhysic::saut()
{
    if(m_surLeSol)
    {
        setVitesseY(-100);
        m_surLeSol=false;
    }
}
