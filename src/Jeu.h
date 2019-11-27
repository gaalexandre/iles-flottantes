#ifndef JEU_H
#define JEU_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "GameComponent.h"
#include "PhysicModule.h"
#include "SystemModule.h"
#include "GraphicModule.h"

#include "Map.h"
#include <vector>
class Jeu
{
 public:
    ~Jeu();
  int gameLoop();
  
 private:
  void eventLoop();

    void niveauSuivant();
    
  
  sf::RenderWindow m_window{sf::VideoMode(800, 800), "Ile flotante!"};
  sf::Event m_event;
  sf::View m_view{sf::FloatRect(0.f, 0.f, 8*256.f, 8*256.f)};
  GraphicModule m_graphicModule;
  PhysicModule m_physicModule;
  SystemModule m_systemModule;
    
    
    std::vector<Map*> m_listeMap;
    int m_niveauEnCours{0};
    int m_niveauMax{0};
};
  

#endif
