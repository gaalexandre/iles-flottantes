#ifndef MENUSYSTEM_H
#define MENUSYSTEM_H

#include "Menu.h"
#include "SystemComponent.h"
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

#include <map>
#include <string>

class MenuSystem : public SystemComponent
{
public :
  MenuSystem(bool &inMenu, unsigned int &selected);
  virtual void manageEvent (sf::Event event);

private :
  bool &m_inMenu;
  unsigned int &m_selected;
};

#endif
