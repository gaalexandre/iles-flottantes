#ifndef PERSO_H
#define PERSO_H

#include <string>
#include "GameComponent.h"

class Perso : public GameComponent
{
public:
  Perso(std::string filename);

  virtual ~Perso();
    
 
private:
  sf::Transform m_transform;
  
};

#endif
