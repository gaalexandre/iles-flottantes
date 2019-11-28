#ifndef GRAPHIC_COMPONENT_H
#define GRAPHIC_COMPONENT_H

#include <SFML/Graphics.hpp>

class GraphicComponent : public sf::Drawable
{
 public:
   virtual void update(sf::Time t)=0;
  
 protected:
  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const=0;
};




#endif
