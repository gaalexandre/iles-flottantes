//
//  PersoSystem.hpp
//  
//
//  Created by Lucas Bourel on 06/11/2019.
//

#ifndef PERSOSYSTEM_H
#define PERSOSYSTEM_H


#include "SystemComponent.h"
#include <SFML/Window.hpp>
#include "PlayerPhysic.h"

class PersoSystem : public SystemComponent
{
    public :
    PersoSystem(PlayerPhysic* physicComponent);
    virtual void manageEvent (sf::Event event);
    
    
    private :
    PlayerPhysic& m_physicComponent;
    bool* m_isJumping;
    
};


#endif

