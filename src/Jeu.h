#ifndef JEU_H
#define JEU_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "GameComponent.h"
#include "PhysicModule.h"
#include "SystemModule.h"
#include "GraphicModule.h"
#include "Map.h"
#include "Perso.h"

#include "Map.h"
#include <vector>
class Jeu
{
 public:
  ~Jeu();
  int gameLoop();
 private:
  void eventLoop();
  void loadNextLevel();
  sf::RenderWindow m_window{sf::VideoMode(800, 800), "Ile flotante!"};
  sf::Event m_event;
  sf::View m_view{sf::FloatRect(0.f, 0.f, 8*256.f, 8*256.f)};
  int m_levelNumber{0};
  GraphicModule m_graphicModule;
  PhysicModule m_physicModule;
  SystemModule m_systemModule;

  Perso *m_perso{nullptr};
  Map *m_map{nullptr};
  int m_levelMax{0};

};

#endif
