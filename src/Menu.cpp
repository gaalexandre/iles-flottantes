#include "Menu.h"
#include "MenuGraphic.h"
#include "MenuSystem.h"
#include <iostream>
Menu::Menu(bool &inMenu,sf::View &view): m_selected(0),m_inMenu(inMenu)
{
    m_graphicComponent = new MenuGraphic(inMenu,view,m_selected);
    m_systemComponent = new MenuSystem(inMenu,m_selected);
}

Menu::~Menu()
{
  delete m_graphicComponent;
  delete m_systemComponent;
}

void Menu::manageEvent(sf::Event event)
{
        m_systemComponent->manageEvent(event);
}
