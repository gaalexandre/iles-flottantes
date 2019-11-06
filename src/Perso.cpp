#include "Perso.h"
#include "PersoGraphic.h"
#include "PersoSystem.h"
#include "PlayerPhysic.h"

//#include "PersoSystem.h"
//#include "PersoPhysic.h"
#include <fstream>

Perso::Perso(std::string filename)
{
    
  m_transform.scale(sf::Vector2f(4.f,12.f));
  std::ifstream file(filename);
  std::string textureFilename;
  int x,L,y,l;
  file >> textureFilename >> x >> y >> L >> l;
  sf::IntRect textureRect(x,y,L,l);
  m_graphicComponent =new PersoGraphic(textureFilename, &m_transform, textureRect);
  
    PlayerPhysic* t = new PlayerPhysic(&m_transform);
    m_physicComponent = t;
    m_systemComponent = new PersoSystem(t);
    
    
    
  //m_physicComponent=new PersoPhysic;
  //m_systemComponent=new PersoSystem;
  
}

Perso::~Perso()
{
  delete m_graphicComponent;
  //delete m_physicComponent;
  //delete m_systemComponent;
}
