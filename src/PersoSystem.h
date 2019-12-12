#ifndef PERSOSYSTEM_H
#define PERSOSYSTEM_H

#include "Perso.h"
#include "SystemComponent.h"
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include "Map.h"

#include <map>
#include <string>

#include "PlayerPhysic.h"

class PersoSystem : public SystemComponent
{
public :
    PersoSystem(PersoEtatSystem* persoEtat, PersoAnimation *animation, Map  *map);
    virtual void manageEvent (sf::Event event);
    
    
private :
  
  int m_blocTerreInventaire{0};
  bool keyPressed{false};
    PersoEtatSystem& m_persoEtat;
  PersoAnimation &m_animation;
    
    std::map<std::string, sf::SoundBuffer> m_soundBuffers;
    std::map<std::string, sf::Sound> m_sounds;
  
  Map *m_map;
    
    
};


#endif

