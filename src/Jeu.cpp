#include "Jeu.h"
#include "Map.h"
#include "Perso.h"
int Jeu::gameLoop()
{
  Map map("mapExemple");
  Perso perso("persoExample");
  perso.loadGraphicComponent(m_graphicModule);
  map.loadGraphicComponent(m_graphicModule);
    
    sf::Clock timer;
  while (m_window.isOpen())
  {
    eventLoop();
    m_physicModule.update( timer.restart() );
    m_window.clear(sf::Color::Black);
    m_graphicModule.draw(m_window);
    m_window.display();
  }
  return 0;
}

void Jeu::eventLoop()
{
  while (m_window.pollEvent(m_event))
  {
    switch (m_event.type)
	  {
      case sf::Event::Closed:
        m_window.close();
        break;

      case sf::Event::KeyPressed:
        m_systemModule.manageEvent(m_event);
        break;

      default:
	      break;
	}
  }
}
