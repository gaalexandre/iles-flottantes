#include "GameComponent.h"

void GameComponent::loadGraphicComponent(GraphicModule &graphicModule)
{
  if(m_graphicComponent!=nullptr)
    graphicModule.addComponent(*m_graphicComponent);
}

void GameComponent::loadSystemComponent(SystemModule &systemModule)
{
  if(m_physicComponent!=nullptr)
    systemModule.addComponent(*m_systemComponent);
}
void GameComponent::loadPhysicComponent(PhysicModule &physicModule)
{
  if(m_systemComponent!=nullptr)
    physicModule.addComponent(*m_physicComponent);
}
