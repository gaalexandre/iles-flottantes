//
//  PersoSystem.hpp
//  
//
//  Created by Lucas Bourel on 06/11/2019.
//

#ifndef PERSOSYSTEM_H
#define PERSOSYSTEM_H

#include "Perso.h"
#include "SystemComponent.h"
#include <SFML/Window.hpp>
#include "PlayerPhysic.h"

class PersoSystem : public SystemComponent
{
    public :
    PersoSystem(PersoEtatSystem* persoEtat);
    virtual void manageEvent (sf::Event event);
    
    
    private :
    PersoEtatSystem& m_persoEtat;
    
    
};


#endif

