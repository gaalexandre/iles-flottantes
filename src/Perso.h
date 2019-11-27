#ifndef PERSO_H
#define PERSO_H

#include <string>
#include "GameComponent.h"

struct PersoEtatSystem
{
    
    bool contactMortel = false;
    bool contactFinNiveau = false;
    bool surLeSol = false;
    
    bool cle = false;
    bool saut = false;
    bool resetCoord = false;
    short int deplacementX = 0;
    short int deplacementY = 0;
};

class Perso : public GameComponent
{
public:
  Perso(std::string filename, double xBegin, double yBegin);
  bool hasFinishedLevel();
    
  bool possedeCle();
  bool finNiveau();
  virtual ~Perso();

private:
  sf::Transform m_transform;
  PersoEtatSystem m_persoEtat;

};

#endif
