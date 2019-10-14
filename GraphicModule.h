#ifndef GRAPHIC_MODULE_H
#define GRAPHIC_MODULE_H

#include <forward_list>
#include "GraphicComponent.h"

class GraphicModule
{
 public:
  bool addComponent(GraphicComponent &component);
  void draw();
 private:
  std::forward_list<GraphicComponent*> m_components;
};


#endif
