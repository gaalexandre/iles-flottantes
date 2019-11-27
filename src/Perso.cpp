#include "Perso.h"
#include "PersoGraphic.h"
#include "PersoSystem.h"
#include "PlayerPhysic.h"

//#include "PersoSystem.h"
//#include "PersoPhysic.h"
#include <fstream>
#include <iostream>

Perso::Perso(std::string filename, double xBegin, double yBegin)
{
    
  m_transform.scale(sf::Vector2f(1.f,1.f));
  std::ifstream file(filename);
  std::string textureFilename, name;
  int x,L,y,l,nb,height,width;
  float time;
  file >> textureFilename >> width >> height;
  
    
  for(int i=0; i<4; ++i){
    file >> name >> nb >> time;

    m_animation.nbFrames[i] = nb;
    m_animation.timeBetweenFrames[i] = time;
    m_animation.sprites[i] = new sf::IntRect[nb];

    for(int j=0; j<nb; ++j){
      file >> name >> x >> y >> L >> l;
      m_animation.sprites[i][j] = sf::IntRect(x,y,L,l);
    }
  }
  
    
  m_graphicComponent =new PersoGraphic(textureFilename, &m_transform, &m_animation);
  
    
    
    
  PlayerPhysic* t = new PlayerPhysic(&m_transform,0,0,L,l,1.f,&m_persoEtat, &m_animation,xBegin,yBegin);
  m_physicComponent = t;
  m_systemComponent = new PersoSystem(&m_persoEtat, &m_animation);
    
    
    
  //m_physicComponent=new PersoPhysic;
  //m_systemComponent=new PersoSystem;
  
}


bool Perso::possedeCle()
{
    
    return m_persoEtat.cle;
}
bool Perso::finNiveau()
{
    return m_persoEtat.contactFinNiveau;
}
Perso::~Perso()
{
  delete m_graphicComponent;
  //delete m_physicComponent;
  //delete m_systemComponent;
   
}

bool Perso::hasFinishedLevel()
{
  return m_persoEtat.contactFinNiveau;
}
