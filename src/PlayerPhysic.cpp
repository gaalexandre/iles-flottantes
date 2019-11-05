//
//  PlayerPhysic.cpp
//  
//
//  Created by Lucas Bourel on 24/10/2019.
//

#include "PlayerPhysic.h"

PlayerPhysic::PlayerPhysic(sf::floatRect hitBox)
{
    m_hitBox = hitBox;
    m_hitBox_tmp = hitBox;
}



void PlayerPhysic::update(const sf::Time t) // bouge selon les accelaration.
{
    m_hitBox_tmp = m_hitBox
    m_hitBox.left += m_accelerationX*( t.asSeconds());
    m_hitBox.top += m_accelerationY*( t.asSeconds() );
    
    return;
    
}

void PlayerPhysic::collide(PhysicComponent &other)
{
    //algorithme (?)
    if(other.intersect(m_hitBox))  // ne marche pas bien
    {
        m_hitBox = m_hitBox_tmp
    }
    return;
}


bool PlayerPhysic::intersect(sf::Vector2f point)
{
    for(int i=0;i<m_width;i++)
    {
        for(int j = 0;j<m_height;j++)
        {
            if( m_hitBox.left == point.x && m_hitBox.top == point.y)
            {
                return  true;
            }
        }
    }
    
    return false;

}

bool PlayerPhysic::intersect(sf::FloatRect rect)
{
    for(int i=0;i<m_width;i++)
    {
        for(int j = 0;j<m_height ;j++)
        {
            if (rect.contains(m_hitBox) )
            {
                return true;
            }
        }
    }
    return false;
}



void PlayerPhysic::setAccelerationX(float accelerationX)
{
    m_accelerationX = accelerationX;
}
void PlayerPhysic::setAccelerationY(float accelerationY)
{
    m_accelerationY = accelerationY;
}
void PlayerPhysic::addAcceleration(float accelerationX, float accelerationY)
{
    m_accelerationY+= accelerationY;
    m_accelerationX+= accelerationX;
}
