#ifndef SYSTEM_COMPONENT_H
#define SYSTEM_COMPONENT_H

#include <SFML/Window.hpp>

class SystemComponent
{
 public:
    
  virtual void manageEvent (sf::Event event) = 0;
 protected:
  
};


#endif
