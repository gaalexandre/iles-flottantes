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
  
  sf::RenderWindow m_window{sf::VideoMode(200, 200), "SFML works!"};
  sf::Event m_event;
  sf::View m_view{sf::FloatRect(0.f, 0.f, 8*256.f, 8*256.f)};
  GraphicModule m_graphicModule;
  PhysicModule m_physicModule;
  SystemModule m_systemModule;
};
  

#endif
