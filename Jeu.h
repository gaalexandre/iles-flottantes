#ifndef JEU_H
#define JEU_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "GameComponent.h"
#include "PhysicModule.h"
#include "SystemModule.h"
#include "GraphicModule.h"

class Jeu
{
 public:
  int gameLoop();
  
 private:
  void eventLoop();
  bool createComponent(GameComponent component);
  
  sf::RenderWindow m_window{sf::VideoMode(200, 200), "SFML works!"};
  sf::Event m_event;
  
  GraphicModule m_graphicModule;
  PhysicModule m_physicModule;
  SystemModule m_systemModule;
};


#endif
