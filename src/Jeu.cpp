#include "Jeu.h"
#include "Map.h"
#include "Perso.h"

#include <iostream>

int Jeu::gameLoop()
{
   
    //m_window.setView(m_view);
    
    // on charge toutes les map ? 
    Map map("mapExemple");
    Perso perso("persoExample");
    perso.loadGraphicComponent(m_graphicModule);
    perso.loadPhysicComponent(m_physicModule);
    perso.loadSystemComponent(m_systemModule);
    
    map.loadGraphicComponent(m_graphicModule);
    map.loadPhysicComponent(m_physicModule);
    
    
    sf::Clock timer;
    
  while (m_window.isOpen())
  {
    eventLoop();
    m_systemModule.manageEvent(m_event);
      
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
           
	  break;
	case sf::Event::Resized:
    m_view.setSize(m_event.size.width, m_event.size.height);
    m_view.zoom(2);
    m_window.setView(m_view);
	  
	  break;
	default:
            
	  break;
	}
    }
}
