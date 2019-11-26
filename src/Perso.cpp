#include "Perso.h"
#include "PersoGraphic.h"
#include "PersoSystem.h"
#include "PlayerPhysic.h"

//#include "PersoSystem.h"
//#include "PersoPhysic.h"
#include <fstream>

Perso::Perso(std::string filename)
{
    
  m_transform.scale(sf::Vector2f(1.f,1.f));
  std::ifstream file(filename);
  std::string textureFilename;
  int x,L,y,l;
  file >> textureFilename >> x >> y >> L >> l;
    
  sf::IntRect textureRect(x,y,L,l);
    
  m_graphicComponent =new PersoGraphic(textureFilename, &m_transform, textureRect);
  
    
    
    
    PlayerPhysic* t = new PlayerPhysic(&m_transform,0,0,L,l,1.f,&m_persoEtat);
    m_physicComponent = t;
    m_systemComponent = new PersoSystem(&m_persoEtat);
    
    
    
  //m_physicComponent=new PersoPhysic;
  //m_systemComponent=new PersoSystem;
  
}

Perso::~Perso()
{
  delete m_graphicComponent;
  //delete m_physicComponent;
  //delete m_systemComponent;
   
}


