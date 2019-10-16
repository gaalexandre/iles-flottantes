#include "SystemModule.h"
#include "Perso.h"
#include <SFML/Window.hpp>

bool SystemModule::addComponent(SystemComponent &component)
{
  return false;
}

void SystemModule::manageEvent(sf::Event event)
{
  // Evènement liés au clavier
  switch(event.key.code)
    {
    case sf::Keyboard::Key::Up :
      //Perso.saut(10);//Valeur de l'accélération à déterminer
      break;
    }
  
}
