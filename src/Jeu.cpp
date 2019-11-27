#include "Jeu.h"

#include <string>
#include <iostream>
#include <fstream>

int Jeu::gameLoop()
{
  m_map=nullptr;
  m_perso=nullptr;
  m_window.setView(m_view);

  sf::Clock timer;
  loadNextLevel();

  while (m_window.isOpen())
  {
    eventLoop();
    m_systemModule.manageEvent(m_event);

    m_physicModule.update( timer.restart() );

    m_window.clear(sf::Color::Black);

    m_graphicModule.draw(m_window);

    m_window.display();
    if(m_perso->hasFinishedLevel())
	loadNextLevel();
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
      m_view.zoom(2);
      m_window.setView(m_view);
      
      break;
    default:
      
      break;
    }
  }
}

void Jeu::loadNextLevel()
{
  m_levelNumber++;
  m_graphicModule.unload();
  m_physicModule.unload();
  m_systemModule.unload();
  std::ifstream levelFile("level" + std::to_string(m_levelNumber));
  std::string mapFileName, playerFilename;
  double xBeginPlayer, yBeginPlayer;
  levelFile >> mapFileName >> playerFilename >>xBeginPlayer >>  yBeginPlayer;
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
