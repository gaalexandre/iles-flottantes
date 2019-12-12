#include "GameComponent.h"
#include "iostream"
void GameComponent::loadGraphicComponent(GraphicModule &graphicModule)
{
  if(m_graphicComponent!=nullptr)
    graphicModule.addComponent(*m_graphicComponent);
}

void GameComponent::loadSystemComponent(SystemModule &systemModule)
{
  if(m_systemComponent!=nullptr)
    systemModule.addComponent(*m_systemComponent);
}
void GameComponent::loadPhysicComponent(PhysicModule &physicModule)
{
  if(m_physicComponent!=nullptr)
    physicModule.addComponent(*m_physicComponent);
}
