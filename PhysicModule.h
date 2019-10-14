#ifndef PHYSIC_Module_H
#define PHYSIC_Module_H

#include <forward_list>
#include "PhysicComponent.h"
class PhysicModule
{
 public:
  bool addComponent(PhysicComponent &component);
  void update();
 private:
  std::forward_list<PhysicComponent*> m_components; 
};


#endif
