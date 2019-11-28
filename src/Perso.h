#ifndef PERSO_H
#define PERSO_H

#include <string>
#include "GameComponent.h"

struct PersoEtatSystem
{
    
    bool contactMortel = false;
    bool contactFinNiveau = true;
    bool surLeSol = false;
    
    int sonCollision = 0;
    
    
    
    bool cle = false;
    bool saut = false;
    bool resetCoord = false;
    short int deplacementX = 0;
    short int deplacementY = 0;
};

enum states{
  stand=0,
  hurt=1,
  jump=2,
  walk=3
};

struct PersoAnimation
{
  sf::IntRect** sprites = new sf::IntRect*[4];
  int frame = 0;
  int* nbFrames = new int[4];
  int* timeBetweenFrames = new int[4];
  states state = walk;
  int clock = 0;
  int direction = 0;
};


class Perso : public GameComponent
{
public:
  Perso(std::string filename, double xBegin, double yBegin);
  bool hasFinishedLevel();

    sf::Vector2f getCoord();
    
  bool possedeCle();
  bool finNiveau();
  virtual ~Perso();

private:
  sf::Transform m_transform;
  PersoEtatSystem m_persoEtat;
  PersoAnimation m_animation;

};

#endif
