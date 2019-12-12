#ifndef MENU_H
#define MENU_H

#include <string>
#include "GameComponent.h"

class Menu : public GameComponent
{
 public:
  Menu(bool &inMenu,sf::View &view);
  void manageEvent(sf::Event event);
  virtual ~Menu();
 private:
  bool &m_inMenu;
  unsigned int m_selected;
};

#endif
