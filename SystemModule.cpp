#include "SystemModule.h"
#include "Perso.h"

bool SystemModule::addComponent(SystemComponent &component)
{
  return false;
}

void SystemModule::manageEvent(Event event)
{
  // Evènement liés au clavier
  switch(event.KeyEvent.code)
    {
    case sf::Keyboard::Key::Up :
      Perso.saut(10);//Valeur de l'accélération à déterminer
      break;
    }
  
}
