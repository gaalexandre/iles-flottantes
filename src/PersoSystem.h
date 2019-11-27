#ifndef PERSOSYSTEM_H
#define PERSOSYSTEM_H

#include "Perso.h"
#include "SystemComponent.h"
#include <SFML/Window.hpp>
#include "PlayerPhysic.h"

class PersoSystem : public SystemComponent
{
public :
    PersoSystem(PersoEtatSystem* persoEtat, PersoAnimation *animation);
    virtual void manageEvent (sf::Event event);
    
    
private :
    PersoEtatSystem& m_persoEtat;
  PersoAnimation &m_animation;
    
    
};


#endif

