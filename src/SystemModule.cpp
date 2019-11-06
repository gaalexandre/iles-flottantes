#include "SystemModule.h"
#include "Perso.h"
#include <SFML/Window.hpp>

bool SystemModule::addComponent(SystemComponent &component)
{
    m_components.push_front(&component);
    
  return true;
}

void SystemModule::manageEvent(sf::Event event)
{
    for(auto it = m_components.begin(); it != m_components.end(); it++)
    {
        (*it)->manageEvent(event);
        
    }
  
}
