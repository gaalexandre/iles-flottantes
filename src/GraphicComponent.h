#ifndef GRAPHIC_COMPONENT_H
#define GRAPHIC_COMPONENT_H

#include <SFML/Graphics.hpp>

class GraphicComponent : public sf::Drawable
{
 public:
  
 protected:
  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const=0;  
};




#endif
