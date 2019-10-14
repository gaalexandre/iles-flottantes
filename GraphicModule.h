#ifndef GRAPHIC_H
#define GRAPHIC_H

#include <forward_list>

class Graphic
{
 public:
  bool addComponent(GraphicComponent &component);
  void draw();
 private:
  forward_list<GraphicComponent*> m_components;
};


#endif
