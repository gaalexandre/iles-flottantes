#ifndef GAME_COMPONENT_H
#define GAME_COMPONENT_H

#include "GraphicComponent.h"
#include "PhysicComponent.h"
#include "SystemComponent.h"

class GameComponent
{
 public:
  
protected:
  GraphicComponent* m_graphicComponent{nullptr};
  PhysicComponent* m_physicComponent{nullptr};
  SystemComponent* m_systemComponent{nullptr};
};


#endif
