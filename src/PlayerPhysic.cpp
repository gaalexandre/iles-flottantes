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



void PlayerPhysic::update(sf::Time t) // bouge selon les accelaration.
{
    
    return;
}

void PlayerPhysic::collide(PhysicComponent &other)
{
    return;
}


bool PlayerPhysic::intersect(sf::Vector2f point)
{
    return false;
}
bool PlayerPhysic::intersect(sf::FloatRect rect)
{
    return false;
}
