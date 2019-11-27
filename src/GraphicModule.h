#ifndef GRAPHIC_MODULE_H
#define GRAPHIC_MODULE_H

#include <forward_list>
#include "GraphicComponent.h"

class GraphicModule
{
 public:
  void addComponent(GraphicComponent &component);
  void draw(sf::RenderWindow &window);
  void update(const sf::Time);
 private:
    std::forward_list<GraphicComponent*> m_components;
    
    
    
};


#endif
