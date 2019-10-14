#ifndef PHYSIC_H
#define PHYSIC_H

#include <forward_list>

class Physic
{
 public:
  bool addComponent(PhysicComponent &component);
  void update();
 private:
  forward_list<PhysicComponent*> m_components; 
};


#endif
