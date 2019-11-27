#include "Jeu.h"
#include "Map.h"
#include "Perso.h"

#include <iostream>
#include <fstream>
#include <sstream>


Jeu::~Jeu()
{
    for(int i = 0;i< m_listeMap.size();i++)
    {
        delete m_listeMap[i];
    }
}
int Jeu::gameLoop()
{
   
    //m_window.setView(m_view);
    
    // on charge toutes les map ?
    
    std::ifstream mapFile("Map/descriptionMonde");
    m_niveauMax = 0;
    std::string fileName;
    mapFile >> m_niveauMax >> fileName;
    m_listeMap.resize(m_niveauMax);
    for(int i = 0; i<m_niveauMax;i++)
    {
        std::ostringstream a;
        a << (i+1);
        //std::cout << "-->" << "Map/"+fileName+a.str()<< std::endl;
        m_listeMap[i] = new Map("Map/"+fileName+a.str());
    }
    m_niveauEnCours = 0;
    
    
    
    
    
    
   
    Perso perso("persoExample");
    
    
    
    perso.loadGraphicComponent(m_graphicModule);
    perso.loadPhysicComponent(m_physicModule);
    perso.loadSystemComponent(m_systemModule);
    
    m_listeMap[m_niveauEnCours]->loadGraphicComponent(m_graphicModule);
    m_listeMap[m_niveauEnCours]->loadPhysicComponent(m_physicModule);
    
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


void Jeu::niveauSuivant()
{
    if(m_niveauEnCours<m_niveauMax-1)
    {
        //m_listeMap[m_niveauEnCours].unlo
    }
}
