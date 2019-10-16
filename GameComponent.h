#ifndef GAME_COMPONENT_H
#define GAME_COMPONENT_H

#include "GraphicComponent.h"
#include "PhysicComponent.h"
#include "SystemComponent.h"
#include "PhysicModule.h"
#include "GraphicModule.h"
#include "SystemModule.h"


class GameComponent
{
public:
  void loadGraphicComponent(GraphicModule &graphicModule);
  void loadSystemComponent(SystemModule &systemModule);
  void loadPhysicComponent(PhysicModule &physicModule);
protected:
  GraphicComponent* m_graphicComponent{nullptr};
  PhysicComponent* m_physicComponent{nullptr};
  SystemComponent* m_systemComponent{nullptr};
};


#endif
