#include "Jeu.h"

#include <string>
#include <iostream>
#include <fstream>

int Jeu::gameLoop()
{
    std::ifstream levelFile("levelNumber");

    levelFile >> m_levelMax;

    m_view.zoom(1.4f);
    m_window.setView(m_view);

    m_map=nullptr;
    m_perso=nullptr;

    sf::Clock timer;
    loadNextLevel();
  
    
    
    // a deplacer dans le constructeur :
    sf::Text HUDCle;
    sf::Text HUDVictoire;
    sf::Text HUDMort;
    sf::Font font;
    font.loadFromFile("sansation.ttf");
    HUDCle.setFont(font);
    HUDMort.setFont(font);
    HUDCle.setFillColor(sf::Color::Red);
    HUDCle.setString("Item : Clé");
    HUDCle.setCharacterSize(24);
    
  while (m_window.isOpen())
  {
     
    eventLoop();
      
      
    m_systemModule.manageEvent(m_event);

    m_physicModule.update( timer.restart() );
    m_graphicModule.update( timer.restart() );
    
    m_window.clear(sf::Color::Black);

    m_view.setCenter(m_perso->getCoord());
    m_graphicModule.draw(m_window);
      
      
    // dessiner l'HUD
    m_window.setView(m_window.getDefaultView());
    if(m_perso->possedeCle())
    {
        m_window.draw(HUDCle);
    }
    m_window.setView(m_view);
    
    // afficher la fenetre
    if(m_perso->hasFinishedLevel())
        loadNextLevel();
    
    m_window.display();
      
      
  }
  return 0;
}

Jeu::~Jeu()
{
    delete m_map;
    delete m_perso;
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
                m_view.zoom(1);
                m_window.setView(m_view);
            
                break;
            default:
                break;
            
        }
    }
}


void Jeu::loadNextLevel()
{
    m_levelNumber = m_levelNumber % m_levelMax + 1;
    m_graphicModule.unload();
    m_physicModule.unload();
    m_systemModule.unload();

    std::ifstream levelFile("level" + std::to_string(m_levelNumber));
    std::string mapFileName, playerFilename;

    double xBeginPlayer, yBeginPlayer;
    levelFile >> mapFileName >> playerFilename >>xBeginPlayer >> yBeginPlayer;

    if(m_map)
        delete m_map;
    if(m_perso)
        delete m_perso;

    m_map=new Map(mapFileName);
    m_perso=new Perso(playerFilename, xBeginPlayer, yBeginPlayer);

    m_perso->loadGraphicComponent(m_graphicModule);
    m_perso->loadPhysicComponent(m_physicModule);
    m_perso->loadSystemComponent(m_systemModule);
    m_map->loadGraphicComponent(m_graphicModule);
    m_map->loadPhysicComponent(m_physicModule);
}

